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
	fin.open("Test 01\\zero.inp"); fout.open("1.in"); read(); fin.close(); fout.close();
	fin.open("Test 01\\zero.out"); fout.open("1.out"); read(); fin.close(); fout.close();
	fin.open("Test 02\\zero.inp"); fout.open("2.in"); read(); fin.close(); fout.close();
	fin.open("Test 02\\zero.out"); fout.open("2.out"); read(); fin.close(); fout.close();
	fin.open("Test 03\\zero.inp"); fout.open("3.in"); read(); fin.close(); fout.close();
	fin.open("Test 03\\zero.out"); fout.open("3.out"); read(); fin.close(); fout.close();
	fin.open("Test 04\\zero.inp"); fout.open("4.in"); read(); fin.close(); fout.close();
	fin.open("Test 04\\zero.out"); fout.open("4.out"); read(); fin.close(); fout.close();
	fin.open("Test 05\\zero.inp"); fout.open("5.in"); read(); fin.close(); fout.close();
	fin.open("Test 05\\zero.out"); fout.open("5.out"); read(); fin.close(); fout.close();
	fin.open("Test 06\\zero.inp"); fout.open("6.in"); read(); fin.close(); fout.close();
	fin.open("Test 06\\zero.out"); fout.open("6.out"); read(); fin.close(); fout.close();
	fin.open("Test 07\\zero.inp"); fout.open("7.in"); read(); fin.close(); fout.close();
	fin.open("Test 07\\zero.out"); fout.open("7.out"); read(); fin.close(); fout.close();
	fin.open("Test 08\\zero.inp"); fout.open("8.in"); read(); fin.close(); fout.close();
	fin.open("Test 08\\zero.out"); fout.open("8.out"); read(); fin.close(); fout.close();
	fin.open("Test 09\\zero.inp"); fout.open("9.in"); read(); fin.close(); fout.close();
	fin.open("Test 09\\zero.out"); fout.open("9.out"); read(); fin.close(); fout.close();
	return 0;
}