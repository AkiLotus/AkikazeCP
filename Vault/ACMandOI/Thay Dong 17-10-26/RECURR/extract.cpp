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
	fin.open("test001\\castle.inp"); fout.open("1.in"); read(); fin.close(); fout.close();
	fin.open("test001\\castle.out"); fout.open("1.out"); read(); fin.close(); fout.close();
	fin.open("test002\\castle.inp"); fout.open("2.in"); read(); fin.close(); fout.close();
	fin.open("test002\\castle.out"); fout.open("2.out"); read(); fin.close(); fout.close();
	fin.open("test003\\castle.inp"); fout.open("3.in"); read(); fin.close(); fout.close();
	fin.open("test003\\castle.out"); fout.open("3.out"); read(); fin.close(); fout.close();
	fin.open("test004\\castle.inp"); fout.open("4.in"); read(); fin.close(); fout.close();
	fin.open("test004\\castle.out"); fout.open("4.out"); read(); fin.close(); fout.close();
	fin.open("test005\\castle.inp"); fout.open("5.in"); read(); fin.close(); fout.close();
	fin.open("test005\\castle.out"); fout.open("5.out"); read(); fin.close(); fout.close();
	fin.open("test006\\castle.inp"); fout.open("6.in"); read(); fin.close(); fout.close();
	fin.open("test006\\castle.out"); fout.open("6.out"); read(); fin.close(); fout.close();
	fin.open("test007\\castle.inp"); fout.open("7.in"); read(); fin.close(); fout.close();
	fin.open("test007\\castle.out"); fout.open("7.out"); read(); fin.close(); fout.close();
	fin.open("test008\\castle.inp"); fout.open("8.in"); read(); fin.close(); fout.close();
	fin.open("test008\\castle.out"); fout.open("8.out"); read(); fin.close(); fout.close();
	return 0;
}