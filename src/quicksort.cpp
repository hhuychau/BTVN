#include "common.h"

void quicksort(vector<double>& a, long lo, long hi) {
    while (lo < hi) {
        double pivot = a[lo + (hi - lo) / 2];
        long i = lo, j = hi;
        while (i <= j) {
            while (a[i] < pivot) i++;
            while (a[j] > pivot) j--;
            if (i <= j) {
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }
        if (j - lo < hi - i) {
            quicksort(a, lo, j);
            lo = i;
        } else {
            quicksort(a, i, hi);
            hi = j;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Cach dung: quicksort.exe <file_du_lieu>" << endl;
        return 1;
    }
    string path = argv[1];
    vector<double> a;
    if (!read_data(path, a)) {
        cerr << "Khong doc duoc file " << path << endl;
        return 1;
    }

    auto t1 = chrono::steady_clock::now();
    quicksort(a, 0, (long)a.size() - 1);
    auto t2 = chrono::steady_clock::now();

    double ms = chrono::duration<double, milli>(t2 - t1).count();
    print_result("QuickSort", path, ms, check_sorted(a));
    return 0;
}