import java.util.Scanner;

public class Q8393 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int sum = n;
		for(int i=1;i<n;i++) {
			sum+=i;
		}
		System.out.print(sum);
		scanner.close();
	}

}
