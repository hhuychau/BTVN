#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    const int N = 1000000;          
    const int NUM_SEQ = 10;         
    mt19937_64 rng(2024);          
    uniform_real_distribution<double> dist(-1000000.0, 1000000.0);

    for (int i = 1; i <= NUM_SEQ; i++) {
        vector<double> a(N);
        for (auto &x : a) x = dist(rng);

        if (i == 1) sort(a.begin(), a.end());                         
        else if (i == 2) sort(a.begin(), a.end(), greater<double>()); 

        string name = "data/seq" + to_string(i) + ".txt";
        ofstream f(name);
        if (!f) {
            cerr << "Khong mo duoc file " << name << endl;
            return 1;
        }
        f << N << "\n";
        f << fixed << setprecision(6);
        for (int j = 0; j < N; j++) f << a[j] << "\n";
        f.close();
        cout << "Da tao " << name << endl;
    }
    return 0;
}