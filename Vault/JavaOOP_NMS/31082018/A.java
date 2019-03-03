//package 31082018

import java.util.*;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long T = sc.nextLong();
		while (T > 0) {
			T--; long a = sc.nextLong(), b = sc.nextLong();
			System.out.printf("%lld %lld\n", Auxiliary.GCD(a, b), Auxiliary.LCM(a, b));
		}
	}
}