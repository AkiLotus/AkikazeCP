#include <iostream>
#include <vector>
#include <set>
#include "testlib.h"
using namespace std;
    
vector<vector<int>> adj;
vector<int> vis;

bool passedAll = true;

int main(int argc, char* argv[])
{
    registerValidation(argc, argv);

    int M = inf.readInt(1, 100000, "M"); inf.readEoln();

    for (int i=0; i<M; i++) {
    	string N = inf.readToken("[0-9]{1,33}", "M"); inf.readEoln();
        ensuref((N.size() == 1) || (N.size() < 33 && N[0] != '0') || (N.size() == 33 && N == "100000000000000000000000000000000"), "Invalid numeral format!");
    }

    inf.readEof();
}