import java.util.Scanner;

public class Q11721 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String str = scanner.next();
		scanner.close();
		for(int i=1;i<=str.length();i++) {
			System.out.print(str.charAt(i-1));
			if(i%10 == 0) System.out.println();
		}
	}
}
