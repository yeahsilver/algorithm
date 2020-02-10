import java.util.Scanner;

public class Q2446 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		for(int i=1;i<=N;i++) {
			for(int j=1;j<i;j++) System.out.print(" ");
			for(int j=1;j<2*(N-i+1);j++) System.out.print("*");
			System.out.println();
		}
		for(int i=2;i<=N;i++) {
			for(int j=1;j<=N-i;j++) System.out.print(" ");
			for(int j=1;j<i*2;j++) System.out.print("*");
			System.out.println();
		}
		scanner.close();
	}
}
