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
	fin.open("test01\\castle.inp"); fout.open("1.in"); read(); fin.close(); fout.close();
	fin.open("test01\\castle.out"); fout.open("1.out"); read(); fin.close(); fout.close();
	fin.open("test02\\castle.inp"); fout.open("2.in"); read(); fin.close(); fout.close();
	fin.open("test02\\castle.out"); fout.open("2.out"); read(); fin.close(); fout.close();
	fin.open("test03\\castle.inp"); fout.open("3.in"); read(); fin.close(); fout.close();
	fin.open("test03\\castle.out"); fout.open("3.out"); read(); fin.close(); fout.close();
	fin.open("test04\\castle.inp"); fout.open("4.in"); read(); fin.close(); fout.close();
	fin.open("test04\\castle.out"); fout.open("4.out"); read(); fin.close(); fout.close();
	fin.open("test05\\castle.inp"); fout.open("5.in"); read(); fin.close(); fout.close();
	fin.open("test05\\castle.out"); fout.open("5.out"); read(); fin.close(); fout.close();
	fin.open("test06\\castle.inp"); fout.open("6.in"); read(); fin.close(); fout.close();
	fin.open("test06\\castle.out"); fout.open("6.out"); read(); fin.close(); fout.close();
	fin.open("test07\\castle.inp"); fout.open("7.in"); read(); fin.close(); fout.close();
	fin.open("test07\\castle.out"); fout.open("7.out"); read(); fin.close(); fout.close();
	fin.open("test08\\castle.inp"); fout.open("8.in"); read(); fin.close(); fout.close();
	fin.open("test08\\castle.out"); fout.open("8.out"); read(); fin.close(); fout.close();
	fin.open("test09\\castle.inp"); fout.open("9.in"); read(); fin.close(); fout.close();
	fin.open("test09\\castle.out"); fout.open("9.out"); read(); fin.close(); fout.close();
	fin.open("test10\\castle.inp"); fout.open("10.in"); read(); fin.close(); fout.close();
	fin.open("test10\\castle.out"); fout.open("10.out"); read(); fin.close(); fout.close();
	return 0;
}