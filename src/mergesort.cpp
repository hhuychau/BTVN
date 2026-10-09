#include "common.h"
void merge_sort(vector<double>& a, vector<double>& tmp, long lo, long hi) {
    if (hi - lo < 2) return;
    long mid = lo + (hi - lo) / 2;
    merge_sort(a, tmp, lo, mid);
    merge_sort(a, tmp, mid, hi);

    long i = lo, j = mid, k = lo;
    while (i < mid && j < hi) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else              tmp[k++] = a[j++];
    }
    while (i < mid) tmp[k++] = a[i++];
    while (j < hi)  tmp[k++] = a[j++];
    for (long t = lo; t < hi; t++) a[t] = tmp[t];
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Cach dung: mergesort.exe <file_du_lieu>" << endl;
        return 1;
    }
    string path = argv[1];
    vector<double> a;
    if (!read_data(path, a)) {
        cerr << "Khong doc duoc file " << path << endl;
        return 1;
    }
    vector<double> tmp(a.size());

    auto t1 = chrono::steady_clock::now();
    merge_sort(a, tmp, 0, (long)a.size());
    auto t2 = chrono::steady_clock::now();

    double ms = chrono::duration<double, milli>(t2 - t1).count();
    print_result("MergeSort", path, ms, check_sorted(a));
    return 0;
}