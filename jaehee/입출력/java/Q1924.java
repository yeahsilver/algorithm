import java.util.Scanner;

public class Q1924 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int x = scanner.nextInt();
		int y = scanner.nextInt();
		for(int i=1;i<x;i++) {
			switch(i) {
			case 1: 
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				y+=31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				y+=30;
				break;
			case 2:
				y+=28;
				break;
			}	
		}
			switch(y%7) {
			case 0:
				System.out.print("SUN");
				break;
			case 1: 
				System.out.print("MON");
				break;
			case 2:
				System.out.print("TUE");
				break;
			case 3:
				System.out.print("WED");
				break;
			case 4:
				System.out.print("THU");
				break;
			case 5:
				System.out.print("FRI");
				break;
			case 6:
				System.out.print("SAT");
			}
		scanner.close();
	}
}
