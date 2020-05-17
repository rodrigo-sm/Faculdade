

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * @author Alexandre Saura;
 * @author Fabio Thomaz;
 * @author Ricardo Oliveira;
 * @author Rodrigo Suarez.
 */

public class JantarFilosofos 
{
    public static void main(String[] args) 
    {   
        if(args.length > 0) {
        	int iAmount = Integer.parseInt(args[0].trim());
        	Recursos.setTray(iAmount);
        }
        
        JantarFilosofos.printHeader();
        JantarFilosofos.printStartDinner();
        
        // Iniciando os filosofos
        Recursos.philosophers[0].start();
        Recursos.philosophers[1].start();
        Recursos.philosophers[2].start();
        Recursos.philosophers[3].start();
        Recursos.philosophers[4].start();
        
        // Aguardando o fim do jantar
        try {
        	Recursos.philosophers[0].join();
        	Recursos.philosophers[1].join();
        	Recursos.philosophers[2].join();
        	Recursos.philosophers[3].join();
        	Recursos.philosophers[4].join();
        	
        	imprimeResultadoDoJantar();
        
            JantarFilosofos.printEndDinner();
        } catch (InterruptedException ex) {
            Logger.getLogger(JantarFilosofos.class.getName()).log(Level.SEVERE, null, ex);
        }       
        
    }

	private static void imprimeResultadoDoJantar() {
		System.out.println();
		System.out.println("*************");
		System.out.println("* RESULTADO *");
		System.out.println("*************");
		Recursos.philosophers[0].mostraResultadoFilosofo();
		Recursos.philosophers[1].mostraResultadoFilosofo();
		Recursos.philosophers[2].mostraResultadoFilosofo();
		Recursos.philosophers[3].mostraResultadoFilosofo();
		Recursos.philosophers[4].mostraResultadoFilosofo();
	}
    
    // Mensagem de apresentaa§a£o
    public static void printHeader()
    {
    	System.out.println("******************************************");
        System.out.println("***                                    ***");
        System.out.println("***    JANTAR ANIMADO COM FILOSOFOS    ***");
        System.out.println("***                                    ***");
        System.out.println("******************************************");
        System.out.println(""); 
        System.out.println("");
        System.out.println("******************************************");
        System.out.println("* PONDO A MESA E RECEBENDO OS CONVIDADOS *");
        System.out.println("******************************************");
        System.out.println("");
    }
    
    // Mensagem do ina­cio do jantar
    public static void printStartDinner()
    {
    	System.out.println(""); 
        System.out.println("");
        System.out.println("******************************************");
        System.out.println("*         O JANTAR ESTA SERVIDO          *");
        System.out.println("******************************************");
        System.out.println("");
    }
    
    // Mensagem do fim do jantar
    public static void printEndDinner()
    {
    	System.out.println(""); 
        System.out.println("");
        System.out.println("******************************************");
        System.out.println("*         FIM DO JANTAR ANIMADO          *");
        System.out.println("******************************************");
        System.out.println("");
    }
}

// Recursos compartilhados
class Recursos 
{
	// Criando bandeja compartilhada
	public static Tray tray = new Tray(0, 20);
	
	 // Criando garfos compartilhados
    public static Fork[] forks = new Fork[]{
		new Fork(0), 
		new Fork(1), 
		new Fork(2),
		new Fork(3),
		new Fork(4)
	};
    
    // Criando filosofos
    public static Philosopher[] philosophers = new Philosopher[]{
		new Philosopher(0, 4, 0), // ID do filosofo, ID do garfo a  esquerda, ID do garfo a  direita
		new Philosopher(1, 0, 1),
		new Philosopher(2, 1, 2),
		new Philosopher(3, 2, 3),
		new Philosopher(4, 3, 4)
	};
    
    // Setters
    public static void setTray(int iAmount)
    {
    	Recursos.tray = new Tray(0, iAmount);
    }
}

// Controle dos garfos compartilhados
class Fork 
{
    private int id;		// ID do garfo
    private int iBusy;	// Estado atual do garfo
    
    public Fork(int _id)
    {
        this.id = _id;
        this.iBusy = 0;
        System.out.println(
    		"Garfo " 
			+ Integer.toString(this.id) 
			+ " criado!"
		);
    }
    
    public int getId()
    {
        return this.id;
    }
    
    public void setBusy(int _iBusy)
    {
        this.iBusy = _iBusy;
    }
    
    // Verifica se o garfo esta ocupado
    public Boolean isBusy()
    {
        return (this.iBusy != 0);
    }
    
}

// Controle da bandeja compartilhada
class Tray
{
    private int id;
    private int iAmount;
    private boolean free;
    
    public Tray(int _id, int _iAmount)
    {
        this.id = _id;
        this.iAmount = _iAmount;
        System.out.println(
    		"Bandeja " 
			+ Integer.toString(this.id) 
			+ " criada! - Qtde: " 
			+ Integer.toString(this.iAmount) 
			+ " porcoes."
		);
        free = true;
    }
    
    // Retorna a quantidade de porcoes na bandeja
    public int getAmount()
    {
        return this.iAmount;
    }
    
    // Decrementa uma porcao da bandeja
    public synchronized void decreaseAmount()
    {
    	if(this.iAmount > 0) {
    		this.iAmount--;
    	}
    }
    
    public synchronized void setBusy() {
    	free = false;
    }
    
    public synchronized void setFree() {
    	free = true;
    }
    
    public boolean isFree() {
    	return free;
    }
}

// Controle do filosofo
class Philosopher extends Thread 
{
	private static final int N = 5;			// Quantidade de filosofos
    private static final int THINKING = 0;	// O filosofo esta pensando
    private static final int HUNGRY = 1;	// O filosofo esta tentando pegar os garfos
    private static final int EATING = 2;	// O filosofo esta comendo
    
    private int id;							// ID do filosofo
    private int phState;					// Estado atual do filosofo
    private int iAmount;					// Quantidade de comida pelo filosofo
    private int forkLeftId;					// ID do garfo a  esquerda
    private int forkRightId;				// ID do garfo a  direita
    private int phLeftId; 					// ID do filosofo a  esquerda
    private int phRightId;					// ID do filosofo a  direita
    
    public Philosopher(int _id, int _forkLeftId, int _forkRightId)
    {
        this.id = _id;
        this.iAmount = 0;
        this.forkLeftId = _forkLeftId;
        this.forkRightId = _forkRightId;
        this.phLeftId = (this.id + N - 1) % N;
        this.phRightId = (this.id + 1) % N;
        
        System.out.println(
    		"--- filosofo " 
			+ Integer.toString(this.id) 
			+ " esta pronto."
		);       
    }
    
    @Override
    public void run()
    {
    	// Enquanto houver comida na bandeja
        while(Recursos.tray.getAmount() > 0) {
        	this.think();
        	this.takeForks();
        }
        
    }

	public void mostraResultadoFilosofo() {
		// Caso o filosofo tenha comido alguma porcao
        if(this.iAmount > 0) {
           System.out.println(
    		   ">>> Filosofo " 
    		   + Integer.toString(this.id) 
    		   + " comeu " 
    		   + Integer.toString(this.iAmount) 
    		   + " porcao(oes)."
		   	);
        } else {
           System.out.println(
    		   ">>> Filosofo " 
    		   + Integer.toString(this.id) 
    		   + " nao comeu."
		   );
        }
	}
    
    // Tenta pegar dois garfos ou bloqueia a aa§a£o
    private void takeForks()
    {
    	synchronized (this) {
    		this.hungry();							 // O filosofo passa a estar com fome
    		this.tryTakeForks(this.id);			 	 // Tenta pegar os garfos
		}
    			
    }
    
    // Tenta pegar dois garfos ou bloqueia
    private void tryTakeForks(int id)
    {
    	if(
    		Recursos.philosophers[id].getPhState() == HUNGRY 
    		&& Recursos.philosophers[Recursos.philosophers[id].phLeftId].getPhState() != EATING 
    		&& Recursos.philosophers[Recursos.philosophers[id].phRightId].getPhState() != EATING
    		&& Recursos.tray.getAmount() > 0
    		&& Recursos.tray.isFree()
    	)
    	{
    		Recursos.tray.setBusy();
    		this.getForks(id);
    		this.eat();
    		Recursos.tray.decreaseAmount();
    		Recursos.philosophers[id].increaseAmount();
    		this.releaseForks(this.id);
    		Recursos.tray.setFree();
    	} 
    }

	private void getForks(int id) {
		Recursos.forks[Recursos.philosophers[id].forkLeftId].setBusy(1);
		Recursos.forks[Recursos.philosophers[id].forkRightId].setBusy(1);
	}

	private void releaseForks(int id) {
		Recursos.forks[Recursos.philosophers[id].forkLeftId].setBusy(0);
		Recursos.forks[Recursos.philosophers[id].forkRightId].setBusy(0);
	}
    
    // Faz o filosofo comer por no maximo 700 ms
    private void eat()
    {
    	this.phState = EATING;
        System.out.println(
    		"*** filosofo " 
			+ Integer.toString(this.id) 
			+ " pegou o garfo " 
			+ Integer.toString(this.forkLeftId) 
			+ " (esquerdo) e o garfo " 
			+ Integer.toString(this.forkRightId)
			+ " (direito) e esta comendo."
		);
        try {
        	Random rand = new Random();
            Thread.sleep(rand.nextInt(700) + 1);
        } catch (InterruptedException ex) {
            Logger.getLogger(Philosopher.class.getName()).log(Level.SEVERE, null, ex);
        }
            
        System.out.println(
    		"*** filosofo " 
			+ Integer.toString(this.id) 
			+ " terminou de comer."
		);
    }
    
    // Faz o filosofo dormir por no maximo 500 ms
    private void think()
    {
    	this.phState = THINKING;
        System.out.println(
    		"=== filosofo " 
			+ Integer.toString(this.id) 
			+ " esta pensando."
		);
        try {
        	Random rand = new Random();
            Thread.sleep(rand.nextInt(500) + 1);
        } catch (InterruptedException ex) {
            Logger.getLogger(Philosopher.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    // Informar que o filosofo esta com fome
    public void hungry()
    {
    	this.phState = HUNGRY;
    	System.out.println(
    		"... filosofo " 
			+ Integer.toString(this.id) 
			+ " esta com fome."
		);
    }
    
    // Incrementa a quantidade que foi comida de porcao(oes)
    public void increaseAmount()
    {
		this.iAmount++;
    }
    
    // Getters e setters
    public int getAmount()
    {
        return this.iAmount;
    }
    
    public int getPhState()
    {
    	return this.phState;
    }
    
    public int getPhId()
    {
    	return this.id;
    }
} 
