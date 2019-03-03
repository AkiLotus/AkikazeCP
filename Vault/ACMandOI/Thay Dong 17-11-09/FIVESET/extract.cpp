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
	fin.open("test01\\FIVESET.inp"); fout.open("1.in"); read(); fin.close(); fout.close();
	fin.open("test01\\FIVESET.out"); fout.open("1.out"); read(); fin.close(); fout.close();
	fin.open("test02\\FIVESET.inp"); fout.open("2.in"); read(); fin.close(); fout.close();
	fin.open("test02\\FIVESET.out"); fout.open("2.out"); read(); fin.close(); fout.close();
	fin.open("test03\\FIVESET.inp"); fout.open("3.in"); read(); fin.close(); fout.close();
	fin.open("test03\\FIVESET.out"); fout.open("3.out"); read(); fin.close(); fout.close();
	fin.open("test04\\FIVESET.inp"); fout.open("4.in"); read(); fin.close(); fout.close();
	fin.open("test04\\FIVESET.out"); fout.open("4.out"); read(); fin.close(); fout.close();
	fin.open("test05\\FIVESET.inp"); fout.open("5.in"); read(); fin.close(); fout.close();
	fin.open("test05\\FIVESET.out"); fout.open("5.out"); read(); fin.close(); fout.close();
	fin.open("test06\\FIVESET.inp"); fout.open("6.in"); read(); fin.close(); fout.close();
	fin.open("test06\\FIVESET.out"); fout.open("6.out"); read(); fin.close(); fout.close();
	fin.open("test07\\FIVESET.inp"); fout.open("7.in"); read(); fin.close(); fout.close();
	fin.open("test07\\FIVESET.out"); fout.open("7.out"); read(); fin.close(); fout.close();
	fin.open("test08\\FIVESET.inp"); fout.open("8.in"); read(); fin.close(); fout.close();
	fin.open("test08\\FIVESET.out"); fout.open("8.out"); read(); fin.close(); fout.close();
	fin.open("test09\\FIVESET.inp"); fout.open("9.in"); read(); fin.close(); fout.close();
	fin.open("test09\\FIVESET.out"); fout.open("9.out"); read(); fin.close(); fout.close();
	fin.open("test10\\FIVESET.inp"); fout.open("10.in"); read(); fin.close(); fout.close();
	fin.open("test10\\FIVESET.out"); fout.open("10.out"); read(); fin.close(); fout.close();
	fin.open("test11\\FIVESET.inp"); fout.open("11.in"); read(); fin.close(); fout.close();
	fin.open("test11\\FIVESET.out"); fout.open("11.out"); read(); fin.close(); fout.close();
	fin.open("test12\\FIVESET.inp"); fout.open("12.in"); read(); fin.close(); fout.close();
	fin.open("test12\\FIVESET.out"); fout.open("12.out"); read(); fin.close(); fout.close();
	fin.open("test13\\FIVESET.inp"); fout.open("13.in"); read(); fin.close(); fout.close();
	fin.open("test13\\FIVESET.out"); fout.open("13.out"); read(); fin.close(); fout.close();
	fin.open("test14\\FIVESET.inp"); fout.open("14.in"); read(); fin.close(); fout.close();
	fin.open("test14\\FIVESET.out"); fout.open("14.out"); read(); fin.close(); fout.close();
	fin.open("test15\\FIVESET.inp"); fout.open("15.in"); read(); fin.close(); fout.close();
	fin.open("test15\\FIVESET.out"); fout.open("15.out"); read(); fin.close(); fout.close();
	fin.open("test16\\FIVESET.inp"); fout.open("16.in"); read(); fin.close(); fout.close();
	fin.open("test16\\FIVESET.out"); fout.open("16.out"); read(); fin.close(); fout.close();
	fin.open("test17\\FIVESET.inp"); fout.open("17.in"); read(); fin.close(); fout.close();
	fin.open("test17\\FIVESET.out"); fout.open("17.out"); read(); fin.close(); fout.close();
	fin.open("test18\\FIVESET.inp"); fout.open("18.in"); read(); fin.close(); fout.close();
	fin.open("test18\\FIVESET.out"); fout.open("18.out"); read(); fin.close(); fout.close();
	fin.open("test19\\FIVESET.inp"); fout.open("19.in"); read(); fin.close(); fout.close();
	fin.open("test19\\FIVESET.out"); fout.open("19.out"); read(); fin.close(); fout.close();
	fin.open("test20\\FIVESET.inp"); fout.open("20.in"); read(); fin.close(); fout.close();
	fin.open("test20\\FIVESET.out"); fout.open("20.out"); read(); fin.close(); fout.close();
	return 0;
}