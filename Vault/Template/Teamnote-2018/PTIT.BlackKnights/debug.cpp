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
        os << it->first << ": " << it->second << (++jt != a.end()? ", " : "");
    }
    os << '}';
    return os;
}