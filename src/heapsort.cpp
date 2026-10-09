#include "common.h"

void sift_down(vector<double>& a, long n, long i) {
    while (true) {
        long l = 2 * i + 1, r = l + 1, largest = i;
        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;
        if (largest == i) return;
        swap(a[i], a[largest]);
        i = largest;
    }
}

void heapsort(vector<double>& a) {
    long n = a.size();
    for (long i = n / 2 - 1; i >= 0; i--) sift_down(a, n, i);  
    for (long end = n - 1; end > 0; end--) {
        swap(a[0], a[end]);
        sift_down(a, end, 0);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Cach dung: heapsort.exe <file_du_lieu>" << endl;
        return 1;
    }
    string path = argv[1];
    vector<double> a;
    if (!read_data(path, a)) {
        cerr << "Khong doc duoc file " << path << endl;
        return 1;
    }

    auto t1 = chrono::steady_clock::now();
    heapsort(a);
    auto t2 = chrono::steady_clock::now();

    double ms = chrono::duration<double, milli>(t2 - t1).count();
    print_result("HeapSort", path, ms, check_sorted(a));
    return 0;
}