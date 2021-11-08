// task15.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
using namespace std;
bool umova(int mm, int ii) { //перевірка на парність числа
    int k = mm / ii;
    bool l;
    if (k % 2 == 0) {
        l = true;
    }
    else l = false;
    return l;
}
void vyvid(double* X, int nn, int l, int kk) { //вивід результату
    cout << fixed << setprecision(2) << X[1];
    int i = kk;
    int j = 2;
    while (i > 1) {
        i = i / 2;
        if (umova(l, i)) cout << " + ";
        else cout << " - ";
        cout << X[j];
        j = j + 1;
    }
    cout << " = 0" << endl;
}
int main()
{
    int n;
    cout << "vvedit kilkist chisel poslidovnosti: ";
    cin >> n;
    int k = pow(2, n - 1);
    double* A = new double[n + 1];
    double* B = new double[k + 1];
    for (int h = 1; h <= n; h++) {
        cout << "vvedit " << h << " chlen: ";
        cin >> A[h];
    }
    for (int m = 1; m <= k; m++) {
        B[m] = A[1];
    }
    int j = 2;
    int i = k;
    while (i > 1) { //перебір усіх варіантів і знаходження усіх можливих значень виразу
        i = i / 2;
        for (int m = 1; m <= k; m++) {
            if (umova(m, i)) {
                B[m] = B[m] + A[j];
            }
            else B[m] = B[m] - A[j];
        }
        j = j + 1;
    }
    int p = 0;
    for (int m = 1; m <= k; m++) { //пошук результату рівного 0 і вивід виразу
        if (B[m] == 0) {
            vyvid(A, n, m, k);
            p = 1;
        }
    }
    if (p == 0) cout << "takoyi kombinatii nemae";
}

