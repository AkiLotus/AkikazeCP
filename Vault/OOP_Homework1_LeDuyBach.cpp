#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

class Student{
    private:
        string name;
        float Math, Phys, Chem;
    public:
        Student() {
            // it's a constructor
        }

        ~Student() {
            // it's a destructor
        }

        void nameInput(string param) {
            name = param;
        }

        void mathInput(float param) {
            Math = param;
        }

        void physInput(float param) {
            Phys = param;
        }

        void chemInput(float param) {
            Chem = param;
        }

        void scoreInput(float param1, float param2, float param3) {
            // Nhap theo thu tu: Toan, Ly, Hoa
            Math = param1; Phys = param2; Chem = param3;
        }

        void fullInput(string param0, float param1, float param2, float param3) {
            // Nhap theo thu tu: Ten, diem Toan, diem Ly, diem Hoa
            name = param0; Math = param1; Phys = param2; Chem = param3;
        }

        float totalPoint() {
            return Math + Phys + Chem;
        }

        void infoShow() {
            cout << "Ho va ten: " << name << endl;
            cout << "Diem thi Toan: " << fixed << setprecision(2) << Math << endl;
            cout << "Diem thi Vat ly: " << fixed << setprecision(2) << Phys << endl;
            cout << "Diem thi Hoa hoc: " << fixed << setprecision(2) << Chem << endl;
            cout << "Tong diem: " << fixed << setprecision(2) << totalPoint() << endl;
            cout << endl;
        }
};

int main() {
	int N;
	cin >> N;
	Student input[N];
	for (int i=0; i<N; i++) {
        string z;
        float z1, z2, z3;
        fflush(stdin);
        getline(cin, z);
        cin >> z1 >> z2 >> z3;
        input[i].fullInput(z, z1, z2, z3);
	}
	cout << "\n\nDANH SACH TRUNG TUYEN:\n\n-------------------\n\n";
	for (int i=0; i<N; i++) {
        if (input[i].totalPoint() >= 20) input[i].infoShow();
	}
	return 0;
}
