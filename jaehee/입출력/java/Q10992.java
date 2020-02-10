import java.util.Scanner;

public class Q10992 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		scanner.close();
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N-i;j++) System.out.print(" ");
			if(i==N) 
				for(int j=1;j<2*N;j++) System.out.print("*");
			else { 
				System.out.print("*");
				if(i!=1) {
					for(int j=1;j<2*(i-1);j++) System.out.print(" ");
					System.out.print("*");			
				}
			}
			System.out.println();
		}
	}

}
