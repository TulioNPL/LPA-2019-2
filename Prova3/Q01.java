import java.util.Scanner;
import java.io.*;

class Q01 {
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		
		String linha;
		
		while (in.hasNextLine()) {
			linha = in.nextLine();
			int n = Integer.parseInt(linha.trim());
			linha = in.nextLine();
			int custoDia = Integer.parseInt(linha.trim());
			
			int[] lucros = new int[n];
			for(int i = 0; i < n; i++) {
				linha = in.nextLine();
				lucros[i] = Integer.parseInt(linha.trim()) - custoDia;
			}
			
			kadane(lucros,n);
		}
	}
	
	public static void kadane(int [] lucros, int n) {
		int maxAtual = 0;
		int maxTotal = -1;
		
		for(int i = 0; i < n; i++) {
			maxAtual += lucros[i];
			
			if(maxAtual < 0) {
				maxAtual = 0;
			}
			
			if(maxAtual > maxTotal) {
				maxTotal = maxAtual;
			}
		}
		
		System.out.println(maxTotal);
	}
}
