// BigInteger and BigDecimal
import java.math.*;
import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			BigInteger a = new BigInteger(in.next());
			BigInteger b = new BigInteger(in.next());
			System.out.println(a.add(b));
			System.out.println(a.subtract(b));
			System.out.println(a.multiply(b));
			System.out.println(a.divide(b));
		}
	}
}