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
	fin.open("Test01\\trans.inp"); fout.open("1.in"); read(); fin.close(); fout.close();
	fin.open("Test01\\trans.out"); fout.open("1.out"); read(); fin.close(); fout.close();
	fin.open("Test02\\trans.inp"); fout.open("2.in"); read(); fin.close(); fout.close();
	fin.open("Test02\\trans.out"); fout.open("2.out"); read(); fin.close(); fout.close();
	fin.open("Test03\\trans.inp"); fout.open("3.in"); read(); fin.close(); fout.close();
	fin.open("Test03\\trans.out"); fout.open("3.out"); read(); fin.close(); fout.close();
	fin.open("Test04\\trans.inp"); fout.open("4.in"); read(); fin.close(); fout.close();
	fin.open("Test04\\trans.out"); fout.open("4.out"); read(); fin.close(); fout.close();
	fin.open("Test05\\trans.inp"); fout.open("5.in"); read(); fin.close(); fout.close();
	fin.open("Test05\\trans.out"); fout.open("5.out"); read(); fin.close(); fout.close();
	fin.open("Test06\\trans.inp"); fout.open("6.in"); read(); fin.close(); fout.close();
	fin.open("Test06\\trans.out"); fout.open("6.out"); read(); fin.close(); fout.close();
	fin.open("Test07\\trans.inp"); fout.open("7.in"); read(); fin.close(); fout.close();
	fin.open("Test07\\trans.out"); fout.open("7.out"); read(); fin.close(); fout.close();
	fin.open("Test08\\trans.inp"); fout.open("8.in"); read(); fin.close(); fout.close();
	fin.open("Test08\\trans.out"); fout.open("8.out"); read(); fin.close(); fout.close();
	fin.open("Test09\\trans.inp"); fout.open("9.in"); read(); fin.close(); fout.close();
	fin.open("Test09\\trans.out"); fout.open("9.out"); read(); fin.close(); fout.close();
	fin.open("Test10\\trans.inp"); fout.open("10.in"); read(); fin.close(); fout.close();
	fin.open("Test10\\trans.out"); fout.open("10.out"); read(); fin.close(); fout.close();
	fin.open("Test11\\trans.inp"); fout.open("11.in"); read(); fin.close(); fout.close();
	fin.open("Test11\\trans.out"); fout.open("11.out"); read(); fin.close(); fout.close();
	fin.open("Test12\\trans.inp"); fout.open("12.in"); read(); fin.close(); fout.close();
	fin.open("Test12\\trans.out"); fout.open("12.out"); read(); fin.close(); fout.close();
	fin.open("Test13\\trans.inp"); fout.open("13.in"); read(); fin.close(); fout.close();
	fin.open("Test13\\trans.out"); fout.open("13.out"); read(); fin.close(); fout.close();
	fin.open("Test14\\trans.inp"); fout.open("14.in"); read(); fin.close(); fout.close();
	fin.open("Test14\\trans.out"); fout.open("14.out"); read(); fin.close(); fout.close();
	fin.open("Test15\\trans.inp"); fout.open("15.in"); read(); fin.close(); fout.close();
	fin.open("Test15\\trans.out"); fout.open("15.out"); read(); fin.close(); fout.close();
	fin.open("Test16\\trans.inp"); fout.open("16.in"); read(); fin.close(); fout.close();
	fin.open("Test16\\trans.out"); fout.open("16.out"); read(); fin.close(); fout.close();
	fin.open("Test17\\trans.inp"); fout.open("17.in"); read(); fin.close(); fout.close();
	fin.open("Test17\\trans.out"); fout.open("17.out"); read(); fin.close(); fout.close();
	fin.open("Test18\\trans.inp"); fout.open("18.in"); read(); fin.close(); fout.close();
	fin.open("Test18\\trans.out"); fout.open("18.out"); read(); fin.close(); fout.close();
	fin.open("Test19\\trans.inp"); fout.open("19.in"); read(); fin.close(); fout.close();
	fin.open("Test19\\trans.out"); fout.open("19.out"); read(); fin.close(); fout.close();
	fin.open("Test20\\trans.inp"); fout.open("20.in"); read(); fin.close(); fout.close();
	fin.open("Test20\\trans.out"); fout.open("20.out"); read(); fin.close(); fout.close();
	return 0;
}