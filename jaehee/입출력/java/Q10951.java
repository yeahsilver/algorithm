import java.io.*;
import java.util.StringTokenizer;

public class Q10951 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = null;
		while((st=new StringTokenizer(br.readLine())).hasMoreTokens()) {
			int A = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());
			bw.write(A+B+"\n");
			bw.flush();
		}
	}
}
