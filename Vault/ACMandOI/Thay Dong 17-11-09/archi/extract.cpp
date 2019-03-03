#include <iostream>
#include <fstream>
using namespace std;

ifstream fin; ofstream fout;

void read() {
	string s;
	while (getline(fin, s)) fout << s << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	fin.open("test1\\archi.inp"); fout.open("1.in"); read(); fin.close(); fout.close();
	fin.open("test1\\archi.out"); fout.open("1.out"); read(); fin.close(); fout.close();
	fin.open("test2\\archi.inp"); fout.open("2.in"); read(); fin.close(); fout.close();
	fin.open("test2\\archi.out"); fout.open("2.out"); read(); fin.close(); fout.close();
	fin.open("test3\\archi.inp"); fout.open("3.in"); read(); fin.close(); fout.close();
	fin.open("test3\\archi.out"); fout.open("3.out"); read(); fin.close(); fout.close();
	fin.open("test4\\archi.inp"); fout.open("4.in"); read(); fin.close(); fout.close();
	fin.open("test4\\archi.out"); fout.open("4.out"); read(); fin.close(); fout.close();
	fin.open("test5\\archi.inp"); fout.open("5.in"); read(); fin.close(); fout.close();
	fin.open("test5\\archi.out"); fout.open("5.out"); read(); fin.close(); fout.close();
	fin.open("test6\\archi.inp"); fout.open("6.in"); read(); fin.close(); fout.close();
	fin.open("test6\\archi.out"); fout.open("6.out"); read(); fin.close(); fout.close();
	fin.open("test7\\archi.inp"); fout.open("7.in"); read(); fin.close(); fout.close();
	fin.open("test7\\archi.out"); fout.open("7.out"); read(); fin.close(); fout.close();
	fin.open("test8\\archi.inp"); fout.open("8.in"); read(); fin.close(); fout.close();
	fin.open("test8\\archi.out"); fout.open("8.out"); read(); fin.close(); fout.close();
	fin.open("test9\\archi.inp"); fout.open("9.in"); read(); fin.close(); fout.close();
	fin.open("test9\\archi.out"); fout.open("9.out"); read(); fin.close(); fout.close();
	fin.open("test10\\archi.inp"); fout.open("10.in"); read(); fin.close(); fout.close();
	fin.open("test10\\archi.out"); fout.open("10.out"); read(); fin.close(); fout.close();
	fin.open("test11\\archi.inp"); fout.open("11.in"); read(); fin.close(); fout.close();
	fin.open("test11\\archi.out"); fout.open("11.out"); read(); fin.close(); fout.close();
	fin.open("test12\\archi.inp"); fout.open("12.in"); read(); fin.close(); fout.close();
	fin.open("test12\\archi.out"); fout.open("12.out"); read(); fin.close(); fout.close();
	fin.open("test13\\archi.inp"); fout.open("13.in"); read(); fin.close(); fout.close();
	fin.open("test13\\archi.out"); fout.open("13.out"); read(); fin.close(); fout.close();
	fin.open("test14\\archi.inp"); fout.open("14.in"); read(); fin.close(); fout.close();
	fin.open("test14\\archi.out"); fout.open("14.out"); read(); fin.close(); fout.close();
	fin.open("test15\\archi.inp"); fout.open("15.in"); read(); fin.close(); fout.close();
	fin.open("test15\\archi.out"); fout.open("15.out"); read(); fin.close(); fout.close();
	fin.open("test16\\archi.inp"); fout.open("16.in"); read(); fin.close(); fout.close();
	fin.open("test16\\archi.out"); fout.open("16.out"); read(); fin.close(); fout.close();
	fin.open("test17\\archi.inp"); fout.open("17.in"); read(); fin.close(); fout.close();
	fin.open("test17\\archi.out"); fout.open("17.out"); read(); fin.close(); fout.close();
	fin.open("test18\\archi.inp"); fout.open("18.in"); read(); fin.close(); fout.close();
	fin.open("test18\\archi.out"); fout.open("18.out"); read(); fin.close(); fout.close();
	fin.open("test19\\archi.inp"); fout.open("19.in"); read(); fin.close(); fout.close();
	fin.open("test19\\archi.out"); fout.open("19.out"); read(); fin.close(); fout.close();
	fin.open("Test20\\archi.inp"); fout.open("20.in"); read(); fin.close(); fout.close();
	fin.open("Test20\\archi.out"); fout.open("20.out"); read(); fin.close(); fout.close();
	return 0;
}