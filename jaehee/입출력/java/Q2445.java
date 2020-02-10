import java.util.Scanner;

public class Q2445 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=i;j++) System.out.print("*");
			for(int j=1;j<=N*2-i*2;j++) System.out.print(" ");
			for(int j=1;j<=i;j++) System.out.print("*");
			System.out.println();
		}
		for(int i=N-1;i>=1;i--) {
			for(int j=1;j<=i;j++) System.out.print("*");
			for(int j=1;j<=N*2-i*2;j++) System.out.print(" ");
			for(int j=1;j<=i;j++) System.out.print("*");
			System.out.println();
		}
		scanner.close();
	}
}
