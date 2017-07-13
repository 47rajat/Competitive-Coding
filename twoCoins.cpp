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

int test, n;
vi graph[N];

int main(){
    cin>>test;

    while(test--){
        cin>>n;
        graph.clear()

        rep(i,n-1){
            int u, v;
            cin>>u>>v;
            graph[u].pb(v);
            graph[v].pb(u);
        }

        
    }
}