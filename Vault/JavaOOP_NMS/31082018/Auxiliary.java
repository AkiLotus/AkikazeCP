//package 31082018

import java.util.*;

public class Auxiliary {
	public static long GCD(long a, long b) {
		if (a == 0) return b;
		if (b == 0) return a;
		while (a != b) {
			a %= b;
			long swap = a;
			a = b; b = swap;
		}
		return a;
	}

	public static long LCM(long a, long b) {
		long gcdab = GCD(a, b);
		return ((a / gcdab) * b);
	}

	public static boolean isPalindromeNumber(long x) {
		long z = 0, tmp = x;
		while (tmp > 0) {
			z *= 10; z += (tmp % 10); tmp /= 10;
		}
		return (z == x);
	}

	public static long sumDigit(long x) {
		long res = 0;
		while (x > 0) {
			res += x % 10;
			x /= 10;
		}
		return res;
	}

	public static bool isPrime(long x) {
		if (x < 2) return false;
		for (long i=2; i<=Math.sqrt(x); i++) {
			if (x % i == 0) return false;
		}
		return true;
	}
}