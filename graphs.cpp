#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


vector<int> used;
vector<vector<int>> g;
vector<int> tops;


void dfs(int v){
    used[v]=1;
    for (int u: g[v])
        if (!used[u]) dfs(u);
}

vector<int> dist;

void bfs_dist(int s){
    queue<int> q;
    dist[s]=0;
    q.push(s);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int u: g[v])
            if (dist[u]==-1){
                dist[u]=dist[v]+1;
                q.push(u);
            }
    }
}

bool cycled=false;
vector<int> color;

void dfs_topsort_with_cycles(int v){
    color[v]=1;
    for (int i: g[v]) {
        if (color[i]==0) dfs(i);
        else if (color[i]==1) cycled=true;
    }
    color[v]=2;
    tops.push_back(v);
}

int main(){

    return 0;
}