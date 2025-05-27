#include <iostream>
#include <string>
using namespace std;

void mergepass(int x[], int y[], int s, int n);
void Merge(int c[], int d[], int l, int m, int r);
void mergeSort(int a[], int n);

void mergepass(int x[], int y[], int s, int n) {
    int i = 0;
    while (i <= n - 2 * s) {
        Merge(x, y, i, i + s - 1, i + 2 * s - 1);
        i = i + 2 * s;
    }
    if (i + s < n)
        Merge(x, y, i, i + s - 1, n - 1);
    else
        for (int j = i; j <= n - 1; j++)
            y[j] = x[j];
}

void Merge(int c[], int d[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while ((i <= m) && (j <= r)) {
        if (c[i] <= c[j])
            d[k++] = c[i++];
        else
            d[k++] = c[j++];
    }
    if (i > m)
        for (int q = j; q <= r; q++)
            d[k++] = c[q];
    else
        for (int q = i; q <= m; q++)
            d[k++] = c[q];
}

void mergeSort(int a[], int n) {
    int* temp = new int[n];
    int s = 1;
    while (s < n) {
        mergepass(a, temp, s, n);
        s *= 2;
        mergepass(temp, a, s, n);
        s *= 2;
    }
    delete[] temp;
}

int main() {
    const int MAXN = 100;
    int sum[MAXN];
    int nn = 0;

    string input;
    cout<<"ÊäÈë";
    while (cin >> input) {
        if (input == "a") {
            break;
        }
        sum[nn++] = stoi(input);
    }

    mergeSort(sum, nn);

    for (int i = 0; i < nn; i++) {
        cout << sum[i] << " ";
    }

    return 0;
}
