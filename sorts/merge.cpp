#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &a, int l, int r) {
    int* tmp = new int[r - l];
    int pos1 = 0, pos2 = 0;
    int m = (l + r) / 2;
    while (l + pos1 < m && m + pos2 < r) {
        if (a[l + pos1] < a[m + pos2]) {
            tmp[pos1 + pos2] = a[l + pos1];
            pos1++;
        } else {
            tmp[pos1 + pos2] = a[m + pos2];
            pos2++;
        }
    }
    while (l + pos1 < m) {
        tmp[pos1 + pos2] = a[l + pos1];
        pos1++;
    }
    while (m + pos2 < r) {
        tmp[pos1 + pos2] = a[m + pos2];
        pos2++;
    }
    for (int i = 0; i < r - l; i++) {
        a[l + i] = tmp[i];
    }
    delete[] tmp;
}

// l - включительно, r - невключительно
void mergeSort(vector<int> &a, int l, int r) {
    if (l + 1 >= r) return;
    mergeSort(a, l, (l + r) / 2);
    mergeSort(a, (l + r) / 2, r);
    merge(a, l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    mergeSort(a, 0, n);

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}
