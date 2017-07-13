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
int weight[N];
int idx[N];
bool visited[N];
int xr[N];

void dfs0(int u, int curr, int e){
    visited[u] = true;
    xr[u] = curr;

    arep(p, graph[u]){
        if(!visited[p.first]){
            curr ^= weight[p.second];
            dfs0(p.first, curr, max(e,weight[p.second]));
            curr ^= weight[p.second]; 
        }
    }
}

void preprocess(){
    memset(xr, 0, sizeof(xr));
    memset(visited, false, sizeof(visited));
    
    dfs0(1, 0, 0);
}


int main(){

    cin>>test;


    while(test--){
        cin>>n;

        memset(graph, {}, sizeof(graph));
        memset(weight, 0, sizeof(weight));
        rep(i,n-1){
            int u,v;
            cin>>u>>v>>weight[i];
            graph[u].pb(mp(v,i));
            graph[v].pb(mp(u,i));
        }
        vii weightIndex(n-1);
        rep(i,n-1){
            weightIndex[i] = mp(weight[i], i);
        }

        sort(weightIndex.begin(), weightIndex.end());
        reverse(weightIndex.begin(), weightIndex.end());

        memset(idx, -1, sizeof(idx));

        rep(i,n-1){
            idx[i] = weightIndex[i].second;
        }

        preprocess();

        cin>>m;

        vector<pair<int,ii>> query;
        rep(i,m){
            int u,v,k;
            cin>>u>>v>>k;
            query.pb(mp(k,mp(u,v)));
        }

        sort(query.begin(), query.end());
        reverse(query.begin(), query.end());

        int curr = 0;
        arep(p,query){
            int k = p.first;
            int u = p.second.first;
            int v = p.second.second;

            bool change = false;
            while(curr < n-1 && k < weight[idx[curr]]){
                weight[idx[curr]] = 0;
                curr++;
                change = true;
            }
            if(change) preprocess();
            // cout << u << " " << v << endl;
            cout << int(xr[u] ^ xr[v]) << endl;
        }
    }

}