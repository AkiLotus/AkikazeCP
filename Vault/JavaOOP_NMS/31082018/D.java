//package 31082018

import java.util.*;

public class D {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long T = sc.nextLong();
		for (long x=1; x<=T; x++) {
			long n = sc.nextLong(), m = sc.nextLong(), p = sc.nextLong();
			long a[] = new long[n], b[] = new long[m], c[] = new long[n+m];
			for (long i=0; i<n; i++) a[i] = sc.nextLong();
			for (long i=0; i<m; i++) b[i] = sc.nextLong();
			for (long i=0; i<p; i++) c[i] = a[i];
			for (long i=p; i<p+m; i++) c[i] = b[i-p];
			for (long i=p+m; i<m+n; i++) c[i] = a[i-m];
			System.out.printf("Test %lld:\n", x);
			for (long i=0; i<n; i++) System.out.printf("%lld ", c[i]);
			System.out.println();
		}
	}
}