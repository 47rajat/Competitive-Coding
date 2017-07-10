#include <bits/stdc++.h>
using namespace std;
#define arep(i,arr) for(auto &i : arr)
#define rep(i,e) for(int i = 0; i < e; i++)
#define rep2(i,s,e) for(int i = s; i < e; i++)
#define rep3(i,e,x) for(int i = 0 ; i < e; i+=x)
#define rep4(i,s,e,x) for(int i = s; i < e; i+=x)
#define pb push_back
#define mp make_pair

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<pair<ll,ll>> vll;

const int N = 1e5 + 10;

int test, n, m;
vii graph[N];
bool visited[N];
int ans;
bool found;

void dfs(int u, int dest, int k){
    visited[u] = true;
    if(u == dest){
        found = true;
        return;
    }

    arep(p,graph[u]){
        if(!visited[p.first]){
            if(p.second <= k) ans ^= p.second;
            dfs(p.first, dest, k);
            if(found) return;
            if(p.second <= k) ans ^= p.second;
        }
    }
    
}


int main(){

    cin>>test;

    while(test--){
        cin>>n;

        memset(graph, {}, sizeof(graph));
        
        rep(i,n-1){
            int u,v,c;
            cin>>u>>v>>c;
            graph[u].pb(mp(v,c));
            graph[v].pb(mp(u,c));
        }

        cin>>m;

        rep(i,m){
            int u,v,k;
            cin>>u>>v>>k;
            memset(visited, false, sizeof(visited));
            ans = 0;
            found = false;
            dfs(u,v,k);
            cout << ans << endl;

        }
    }

}