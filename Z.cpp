#include <bits/stdc++.h>
using namespace std;

vector<long long>  zfunc(string s){
    long long n=s.size();
    long long l,r;
    l=0; r=1;
    vector<long long> z(n,0);

    for (long long i=1; i<n; ++i){
        if (r>i) z[i]=min(z[i-l],r-i); //установка нижней границы
        while (z[i]+i<n && s[z[i]+i]==s[z[i]]) z[i]++; //наивный алгоритм
        if (i+z[i]>r) {l=i; r=i+z[i];} //пересчет l и r
    }
    return z;
}

int main(){
    
    string s;
    cin >> s;

    for (auto i: zfunc(s)) cout << i << ' ';
    return 0;

}