#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int k;
    cin >> k;
    int l = 0; 
    int r=n;
    while (r-l>1) {
        int m = (r+l)/2;
        if (a[m]>k) {
            r=m;
        }
        else {
            l=m;
        }
    }
    cout << l << endl;
    return 0;
}