import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
    	InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        
		long startTime = System.currentTimeMillis();
		
		Task solver = new Task();
        solver.solve(1, in, out);
		
		long endTime = System.currentTimeMillis();
		out.print(endTime - startTime);
		
        out.close();
    }

    static class Task {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
        	try
        	{
				long a = in.nextLong();
        	}
        	catch(RuntimeException e)
        	{
        		return;
        	}
        }

    }
    
	private static int max(int x,int y)
    {
    	if(x>y)return x;
    	return y;
    }
    
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}