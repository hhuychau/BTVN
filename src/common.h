#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
using namespace std;

inline bool read_data(const string& path, vector<double>& a) {
    ifstream f(path);
    if (!f) return false;
    size_t n;
    f >> n;
    a.resize(n);
    for (size_t i = 0; i < n; i++) f >> a[i];
    return (bool)f;
}


inline bool check_sorted(const vector<double>& a) {
    return is_sorted(a.begin(), a.end());
}
inline void print_result(const string& algo, const string& file,
                         double ms, bool ok) {
    cout << algo << "," << file << "," << ms << "," << (ok ? "OK" : "SAI") << endl;
}