// 1. Put this file into the folder "bits"
// 2. Put this line into "bits/stdc++.h": #include "cp-debug.cpp"
// 3. Now you can cout << STL !! Modify this code as to suit your style
// Example: https://imgur.com/a/kulaD
using namespace std;

#define Akikaze 19
#define Jade 12
#define Trang 1111

#define REcheck cout << "RE here?\n"
#define tracker1(p1) cout << "working at " << p1 << endl;
#define tracker2(p1,p2) cout << "working at " << p1 << "-" << p2 << endl;
#define tracker3(p1,p2,p3) cout << "working at " << p1 << "-" << p2 << "-" << p3 << endl;
#define tracker4(p1,p2,p3,p4) cout << "working at " << p1 << "-" << p2 << "-" << p3 << "-" << p4 << endl;
#define tracker5(p1,p2,p3,p4,p5) cout << "working at " << p1 << "-" << p2 << "-" << p3 << "-" << p4 << "-" << p5 << endl;
#define tracker6(p1,p2,p3,p4,p5,p6) cout << "working at " << p1 << "-" << p2 << "-" << p3 << "-" << p4 << "-" << p5 << "-" << p6 << endl;
#define tracker7(p1,p2,p3,p4,p5,p6,p7) cout << "working at " << p1 << "-" << p2 << "-" << p3 << "-" << p4 << "-" << p5 << "-" << p6 << "-" << p7 << endl;
#define tracker8(p1,p2,p3,p4,p5,p6,p7,p8) cout << "working at " << p1 << "-" << p2 << "-" << p3 << "-" << p4 << "-" << p5 << "-" << p6 << "-" << p7 << "-" << p8 << endl;

template <class T1, class T2>
std::ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
    return os << '(' << a.first << ", " << a.second << ')';
}
 
template <class T>
std::ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    for (unsigned int i = 0; i < a.size(); i++)
        os << a[i] << (i < a.size() - 1? ", " : "");
    os << ']';
    return os;
}
 
template <class T>
std::ostream &operator<<(ostream &os, const set<T> &a) {
    os << '{';
    for(typename set<T>::iterator it = a.begin(); it != a.end(); it++) {
        typename set<T>::iterator jt = it;
        os << *it << (++jt != a.end()? ", " : "");
    }
    os << '}';
    return os;
}
 
template <class T1, class T2>
std::ostream &operator<<(ostream &os, map<T1, T2> &a) {
    os << "{\n";
    for(typename map<T1, T2>::iterator it = a.begin(); it != a.end(); it++) {
        typename map<T1, T2>::iterator jt = it;
        os << "  " << it->first << ": " << it->second << (++jt != a.end()? ",\n" : "\n");
    }
    os << '}';
    return os;
}
 
template <typename T>
void bug1D(T a, int l, int r) {
    cout << "Array[] = [";
    for (int i = l; i < r; ++i) cout << a[i] << ", ";
    if (r >= l) cout << a[r];
    cout << "];" << endl;
}
 
#define bug(args...) {string _s = #args;replace(_s.begin(), _s.end(), ',', ' ');bool isOnly = 1;for (int i = 0; i < (int)_s.size()-1; ++i) {if (_s[i] == ' ') {isOnly = 0;break;}}if(!isOnly) cout << "{" << endl;stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);if (!isOnly) cout << "}" << endl;}
void err(istream_iterator<string> it) {}
 
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << "   " << *it << " = " << a << ";" << endl;
	err(++it, args...);
}