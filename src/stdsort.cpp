#include "common.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Cach dung: stdsort.exe <file_du_lieu>" << endl;
        return 1;
    }
    string path = argv[1];
    vector<double> a;
    if (!read_data(path, a)) {
        cerr << "Khong doc duoc file " << path << endl;
        return 1;
    }

    auto t1 = chrono::steady_clock::now();
    sort(a.begin(), a.end());
    auto t2 = chrono::steady_clock::now();

    double ms = chrono::duration<double, milli>(t2 - t1).count();
    print_result("std::sort", path, ms, check_sorted(a));
    return 0;
}