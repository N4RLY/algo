#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll>  zfunc(string s){
    ll n=s.size();
    ll l,r;
    l=0; r=1;
    vector<ll> z(n,0);

    for (ll i=1; i<n; ++i){
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