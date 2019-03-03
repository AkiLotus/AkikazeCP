#include <iostream>
#include <cstdio>
using namespace std;

struct data {
    int i, next;
}
int n, start, x;
int arr[50001];
data list[50001];
int tmpAns = -1;
int index = -1;

bool SendAndReceive(int z) {
    printf("? %d\n", z);
    fflush(stdout);
    int val, nex;
    cin >> val >> nex;
    list[z].i = val; list[z].next = nex;
    if ((val > tmpAns && tmpAns < x) || (val < tmpAns && tmpAns > x && val >= x)) {
        tmpAns = val;
        if (list[z+1].next == 0) index = 1000000000 + z;
    }
    if (tmpAns == x) return true;
    return false;
}

int main() {
    cin >> n >> start >> x;
    if (start != n) list[start+1].next = start;
    bool firstContact = true;
    while (true) {
        if (firstContact) {
            firstContact = false;
            bool found = SendAndReceive(start);
            index = start;
            if (found) break;
        }
        else {
            // still don't know what to do here...
        }
    }
    printf("! %d", tmpAns);
    fflush(stdout);
	return 0;
}
