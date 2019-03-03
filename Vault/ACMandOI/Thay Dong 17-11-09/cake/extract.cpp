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
	fin.open("test01\\cake.inp"); fout.open("1.in"); read(); fin.close(); fout.close();
	fin.open("test01\\cake.out"); fout.open("1.out"); read(); fin.close(); fout.close();
	fin.open("test02\\cake.inp"); fout.open("2.in"); read(); fin.close(); fout.close();
	fin.open("test02\\cake.out"); fout.open("2.out"); read(); fin.close(); fout.close();
	fin.open("test03\\cake.inp"); fout.open("3.in"); read(); fin.close(); fout.close();
	fin.open("test03\\cake.out"); fout.open("3.out"); read(); fin.close(); fout.close();
	fin.open("test04\\cake.inp"); fout.open("4.in"); read(); fin.close(); fout.close();
	fin.open("test04\\cake.out"); fout.open("4.out"); read(); fin.close(); fout.close();
	fin.open("test05\\cake.inp"); fout.open("5.in"); read(); fin.close(); fout.close();
	fin.open("test05\\cake.out"); fout.open("5.out"); read(); fin.close(); fout.close();
	fin.open("test06\\cake.inp"); fout.open("6.in"); read(); fin.close(); fout.close();
	fin.open("test06\\cake.out"); fout.open("6.out"); read(); fin.close(); fout.close();
	fin.open("test07\\cake.inp"); fout.open("7.in"); read(); fin.close(); fout.close();
	fin.open("test07\\cake.out"); fout.open("7.out"); read(); fin.close(); fout.close();
	fin.open("test08\\cake.inp"); fout.open("8.in"); read(); fin.close(); fout.close();
	fin.open("test08\\cake.out"); fout.open("8.out"); read(); fin.close(); fout.close();
	fin.open("test09\\cake.inp"); fout.open("9.in"); read(); fin.close(); fout.close();
	fin.open("test09\\cake.out"); fout.open("9.out"); read(); fin.close(); fout.close();
	fin.open("test10\\cake.inp"); fout.open("10.in"); read(); fin.close(); fout.close();
	fin.open("test10\\cake.out"); fout.open("10.out"); read(); fin.close(); fout.close();
	return 0;
}