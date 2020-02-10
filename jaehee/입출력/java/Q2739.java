import java.util.Scanner;

public class Q2739 {

	public static void main(String[] args) {
		int N;
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		for(int i=1;i<10;i++) {
			System.out.println(N+" * "+i+" = "+N*i);
		}
		scanner.close();
	}

}
