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
	fin.open("test001\\wgame.inp"); fout.open("1.in"); read(); fin.close(); fout.close();
	fin.open("test001\\wgame.out"); fout.open("1.out"); read(); fin.close(); fout.close();
	fin.open("test002\\wgame.inp"); fout.open("2.in"); read(); fin.close(); fout.close();
	fin.open("test002\\wgame.out"); fout.open("2.out"); read(); fin.close(); fout.close();
	fin.open("test003\\wgame.inp"); fout.open("3.in"); read(); fin.close(); fout.close();
	fin.open("test003\\wgame.out"); fout.open("3.out"); read(); fin.close(); fout.close();
	fin.open("test004\\wgame.inp"); fout.open("4.in"); read(); fin.close(); fout.close();
	fin.open("test004\\wgame.out"); fout.open("4.out"); read(); fin.close(); fout.close();
	fin.open("test005\\wgame.inp"); fout.open("5.in"); read(); fin.close(); fout.close();
	fin.open("test005\\wgame.out"); fout.open("5.out"); read(); fin.close(); fout.close();
	fin.open("test006\\wgame.inp"); fout.open("6.in"); read(); fin.close(); fout.close();
	fin.open("test006\\wgame.out"); fout.open("6.out"); read(); fin.close(); fout.close();
	fin.open("test007\\wgame.inp"); fout.open("7.in"); read(); fin.close(); fout.close();
	fin.open("test007\\wgame.out"); fout.open("7.out"); read(); fin.close(); fout.close();
	fin.open("test008\\wgame.inp"); fout.open("8.in"); read(); fin.close(); fout.close();
	fin.open("test008\\wgame.out"); fout.open("8.out"); read(); fin.close(); fout.close();
	fin.open("test009\\wgame.inp"); fout.open("9.in"); read(); fin.close(); fout.close();
	fin.open("test009\\wgame.out"); fout.open("9.out"); read(); fin.close(); fout.close();
	fin.open("test010\\wgame.inp"); fout.open("10.in"); read(); fin.close(); fout.close();
	fin.open("test010\\wgame.out"); fout.open("10.out"); read(); fin.close(); fout.close();
	fin.open("test011\\wgame.inp"); fout.open("11.in"); read(); fin.close(); fout.close();
	fin.open("test011\\wgame.out"); fout.open("11.out"); read(); fin.close(); fout.close();
	fin.open("test012\\wgame.inp"); fout.open("12.in"); read(); fin.close(); fout.close();
	fin.open("test012\\wgame.out"); fout.open("12.out"); read(); fin.close(); fout.close();
	fin.open("test013\\wgame.inp"); fout.open("13.in"); read(); fin.close(); fout.close();
	fin.open("test013\\wgame.out"); fout.open("13.out"); read(); fin.close(); fout.close();
	fin.open("test014\\wgame.inp"); fout.open("14.in"); read(); fin.close(); fout.close();
	fin.open("test014\\wgame.out"); fout.open("14.out"); read(); fin.close(); fout.close();
	fin.open("test015\\wgame.inp"); fout.open("15.in"); read(); fin.close(); fout.close();
	fin.open("test015\\wgame.out"); fout.open("15.out"); read(); fin.close(); fout.close();
	fin.open("test016\\wgame.inp"); fout.open("16.in"); read(); fin.close(); fout.close();
	fin.open("test016\\wgame.out"); fout.open("16.out"); read(); fin.close(); fout.close();
	fin.open("test017\\wgame.inp"); fout.open("17.in"); read(); fin.close(); fout.close();
	fin.open("test017\\wgame.out"); fout.open("17.out"); read(); fin.close(); fout.close();
	fin.open("test018\\wgame.inp"); fout.open("18.in"); read(); fin.close(); fout.close();
	fin.open("test018\\wgame.out"); fout.open("18.out"); read(); fin.close(); fout.close();
	fin.open("test019\\wgame.inp"); fout.open("19.in"); read(); fin.close(); fout.close();
	fin.open("test019\\wgame.out"); fout.open("19.out"); read(); fin.close(); fout.close();
	fin.open("Test20\\wgame.inp"); fout.open("20.in"); read(); fin.close(); fout.close();
	fin.open("Test20\\wgame.out"); fout.open("20.out"); read(); fin.close(); fout.close();
	return 0;
}