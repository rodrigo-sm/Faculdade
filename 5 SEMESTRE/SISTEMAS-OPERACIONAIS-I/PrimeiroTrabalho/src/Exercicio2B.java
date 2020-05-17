import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveAction;

public class Exercicio2B {

	private static ForkJoinPool executor = new ForkJoinPool();
	private static PrintWriter gravarArq;
	private static FileWriter arq;
	private static long start;

	public static void main(String[] args) throws IOException, InterruptedException {
		Scanner scanner = new Scanner(System.in);
		
		int n = leN(scanner);
		
		int m = leM(scanner);
		
		scanner.close();
		
		start = System.currentTimeMillis();
		
		arq = new FileWriter("combinacoes.txt");
	    gravarArq = new PrintWriter(arq);
	    
	    gravarArq.println("N: " + n);
	    gravarArq.println("M: " + m);
	    
	    int[] entrada = geraEntrada(n);

	    gravarArq.println("Resultado");
	    imprimeTodasCombinacoes(entrada, n, m);
	    
	    encerraArquivo();
	}
	
	private static int leN(Scanner scanner) {
		System.out.print("N: ");
		int n = scanner.nextInt();
		return n;
	}
	
	private static int leM(Scanner scanner) {
		System.out.print("M: ");
		int m = scanner.nextInt();
		return m;
	}
	
	private static int[] geraEntrada(int n) {
		int [] vetor = new int[n];
		Random gerador = new Random();
		
		gravarArq.println("Entrada");
		for(int i = 0; i < n; i++) {
			vetor[i] = gerador.nextInt(1001);
			gravarArq.print(vetor[i] + " ");
		}
		gravarArq.println();
		return vetor;
	}
	
	private static void imprimeTodasCombinacoes(int[] vetorEntrada, int tamanhoEntrada, int tamanhoCombinacao) throws InterruptedException {
		int vetorCombinacao[] = new int[tamanhoCombinacao];
		
		GeraCombinacao1 gerador = new GeraCombinacao1(vetorEntrada, vetorCombinacao, 0, tamanhoEntrada-1, 0,tamanhoCombinacao, executor, gravarArq);
		
		executor.execute(gerador);
		
		gerador.join();
		
		executor.shutdown();
	}
	
	private static void encerraArquivo() {
		gravarArq.println("Tempo de execucao: "+ (System.currentTimeMillis() - start) + " ms");
		
		gravarArq.close();
		try {
			arq.close();
		} catch (IOException e) {
		}
		
		System.out.println("Resultado salvo no arquivo \"combinacoes.txt\" na pasta do projeto");
		System.out.println("Tempo de execucao: "+ (System.currentTimeMillis() - start) + " ms (Encontra-se salvo no final do arquivo tambem)");
	}

}

class GeraCombinacao1 extends RecursiveAction {
	
	private static final long serialVersionUID = 1L;
	private int[] vetorEntrada;
	private int[] vetorCombinacao;
	private int inicio;
	private int fim;
	private int indexAtual;
	private int tamanhoCombinacao;
	private ForkJoinPool executor;
	private PrintWriter gravarArq;
	private List<GeraCombinacao1> geradores = new ArrayList<GeraCombinacao1>();

	public GeraCombinacao1(int[] vetorEntrada, int[] vetorCombinacao, int inicio, int fim, int indexAtual, int tamanhoCombinacao, ForkJoinPool executor, PrintWriter gravarArq) {
		this.vetorEntrada = vetorEntrada;
		this.gravarArq = gravarArq;
		this.vetorCombinacao = vetorCombinacao.clone();
		this.inicio = inicio;
		this.fim = fim;
		this.indexAtual = indexAtual;
		this.tamanhoCombinacao = tamanhoCombinacao;
		this.executor = executor;
	}

	@Override
	public void compute() {
		// Se a combinacacao atual estiver pronta para ser impressa
		if (indexAtual == tamanhoCombinacao)  { 
			imprimeVetor(vetorCombinacao, tamanhoCombinacao); 
		} 

		// Gera todas combinacoes a partir do index enquanto houver posicoes remanescentes no vetorCombinacao
		else {
			for (int index = inicio; index <= fim && fim-index+1 >= tamanhoCombinacao-indexAtual; index++) 
			{ 
				vetorCombinacao[indexAtual] = vetorEntrada[index];
				GeraCombinacao1 gerador = new GeraCombinacao1(vetorEntrada, vetorCombinacao, index+1, fim, indexAtual+1, tamanhoCombinacao, executor, gravarArq);
				executor.execute(gerador);
				geradores.add(gerador);
			}
			
			geradores.forEach(gerador -> gerador.join());
		}
	}
	
	private void imprimeVetor(int[] vetorCombinacao, int tamanhoCombinacao) {
		synchronized(gravarArq) {
			for (int j=0; j<tamanhoCombinacao; j++) 
				gravarArq.print(vetorCombinacao[j]+" "); 
			gravarArq.println("");
		}
	}
	
	
}
