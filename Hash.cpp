#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int mod = 1e9+7;
const int base = 29; //число должно быть больше размера алфавита

//просто массив степеней, чтобы не считать их заново
vector<int>  init_p(int n){
    vector<int> p(n+1);
    p[0]=1;
    for (int i = 1; i <= n; i++) 
        p[i] = 1ll * p[i-1] * base % mod;
    return p;
}

//сама хэш-функция (вычисление хэша каждого префикса)
vector<int> init_h(int n, string s){
    vector<int> h(n+1);
    for (int i = 1; i <= n; i++) 
        h[i] = (1ll * h[i-1] * base + (s[i-1] - 'a' + 1)) % mod;
    return h;
}

//вычисление хэша подстроки с границами l,r
int get(int l, int r, vector<int>& h, vector<int>& p){
    return (h[r] - 1ll * h[l-1] * p[r-l+1] % mod + mod) % mod;
}

int main(){
    
    string s;
    cin >> s;

    int n = s.size();
    vector<int> p = init_p(n); //массив степеней
    vector<int> h_s = init_h(n,s); //хэши

    //пример: поиск подстроки в строке
    string pat;
    cin >> pat;
    int m = pat.size();
    vector<int> h_pat = init_h(m,pat);

    for (int i = 0; i <= n-m; i++){
        if (get(i, i+m, h_s, p)==pat.back())
            cout << i << ' ';
    }
    
    return 0;

}