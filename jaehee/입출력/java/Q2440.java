import java.util.Scanner;

public class Q2440 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		for(int i=1;i<=N;i++) {
			for(int j=N;j>=i;j--) {
				System.out.print("*");
			}
			System.out.println();
		}
		scanner.close();
	}

}
