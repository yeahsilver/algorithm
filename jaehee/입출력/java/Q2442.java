import java.util.Scanner;

public class Q2442 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		for(int i=1;i<=N;i++) {
			for(int j=i;j<N;j++) System.out.print(" ");
			for(int j=1;j<i*2;j++) System.out.print("*");
			System.out.println();
		}
		scanner.close();
	}

}
