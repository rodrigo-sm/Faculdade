import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.function.Supplier;

public class Exercicio2A {
	
	private static int n;
	private static Random gerador = new Random();
	private static PrintWriter gravarArq;
	private static long start;
	private static int ultimaLinhaProcessada;
	private static int[][] resultado;
	private static FileWriter arq;
	private static int[][] entrada1;
	private static int[][] entrada2;

	public static void main(String[] args) throws IOException, InterruptedException {
		leN();
		
		start = System.currentTimeMillis();

		inicializaArquivo();
		
		gravarArq.println("N: " + n);
		
		entrada1 = geraEntrada1();
	    entrada2 = geraEntrada2();
	    
	    geraResultado();
	    
	    encerraArquivo();
	}
	
	private static void leN() {
		Scanner sc = new Scanner(System.in);
		
		System.out.print("N: ");
		n = sc.nextInt();
		
		sc.close();
	}

	private static void inicializaArquivo() throws IOException {
		arq = new FileWriter("resultado.txt");
		gravarArq = new PrintWriter(arq);
	}
	
	private static int[][] geraEntrada2() {
		gravarArq.println("Entrada 2");
		int [][]  entrada2 = geraMatriz();
		return entrada2;
	}

	private static int[][] geraEntrada1() {
		gravarArq.println("Entrada 1");
		int [][] entrada1 = geraMatriz();
		return entrada1;
	}
	
	private static int[][] geraMatriz() {
		int [][] retorno = new int[n][n];
		
		for(int linha = 0; linha < n; linha++) {
			for(int coluna = 0; coluna < n; coluna++) {
				retorno[linha][coluna] = gerador.nextInt(1000);
				gravarArq.print(retorno[linha][coluna] + " ");
			}
			gravarArq.println();
		}
		
		return retorno;
	}

	private static void geraResultado() throws InterruptedException {
		ExecutorService executor = Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());

	    List<CompletableFuture<Integer>> calculosDeLinha = new ArrayList<>(n);
	    
	    resultado = new int[n][n];
		ultimaLinhaProcessada = 0;
		
	    Supplier<Integer> calculadorDeLinha = criaCalculadorDeLinha();
	    
	    for(int linha = 0; linha < n; linha++) {
			calculosDeLinha.add(CompletableFuture.supplyAsync(calculadorDeLinha, executor));
		}

	    gravarArq.println("Resultado");
	    
	    calculosDeLinha.forEach(calculoDeLinha -> {
			try {
				imprimeLinha(calculoDeLinha.get());
			} catch (InterruptedException | ExecutionException e) {
			}
		});
	    
        executor.shutdown();
	}

	private static Supplier<Integer> criaCalculadorDeLinha() {
		return () -> {
			int linhaASerCalculada = getLinhaASerCalculada();
			
			for(int coluna = 0; coluna < n; coluna++) {
				
				int elemento = 0;
				for(int contador = 0; contador < n; contador++) 
					elemento += entrada1[linhaASerCalculada][contador] * entrada2[contador][coluna];
				
				resultado[linhaASerCalculada][coluna] = elemento;
			}
			
			return Integer.valueOf(linhaASerCalculada);
		};
	}
	
	public synchronized static int getLinhaASerCalculada() {
		return ultimaLinhaProcessada++;
	}
	
	private static void imprimeLinha(int linhaASerImpressa) {
		for(int colunaAtual = 0; colunaAtual < n; colunaAtual++)
			gravarArq.print(resultado[linhaASerImpressa][colunaAtual] + " ");
		gravarArq.println();
	}

	private static void encerraArquivo() {
		gravarArq.println("Tempo de execucao: "+ (System.currentTimeMillis() - start) + " ms");
		try {
			arq.close();
		} catch (IOException e) {
		}
		gravarArq.close();
		
		System.out.println("Resultado salvo no arquivo \"resultado.txt\" na pasta do projeto");
		System.out.println("Tempo de execucao: "+ (System.currentTimeMillis() - start) + " ms (Encontra-se salvo no final do arquivo tambem)");
	}
	
}
