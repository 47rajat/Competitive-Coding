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

const int N = 1e5 + 10;

/* The solution to this problem uses Minimum Spanning Tree with
a minor modification. In the final created MST we find all the
edges having the maximum weight (W) and then check if those edges
can be replaced by any other edge having weight greater than W. All
such edges will contribute to the answer.
*/

int n,m;
vector<pair<int,ii>> edges;
int parent[N];
int size[N];

int find(int i){

    while(!(parent[i] == i)){

        parent[i] = parent[parent[i]];
        i = parent[i];
    }

    return i;
}

void Union(int x, int y){
    int xset = find(x);
    int yset = find(y);
    if(xset == yset) return;
    if(size[xset] < size[yset]){
        parent[xset] = yset;
        size[yset] += size[xset];
    } else{
        parent[yset] = xset;
        size[xset] += size[yset];
    }
}




int main(){

    cin>>n>>m;

    rep(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        edges.pb(mp(c,mp(a,b)));
    }

    sort(edges.begin(), edges.end());

    // arep(e, edges){
    //     printf("%d %d %d\n",e.second.first,e.second.second, e.first);
    // }
    
    rep(i,n+1){
        size[i] = 1;
        parent[i] = i;
    }

    int W = 0;
    ll total = 0;

    arep(e, edges){
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;

        if(find(u) == find(v)) continue;

        W = max(w,W);
        total += w;
        Union(u,v);
    }

    rep(i,n+1){
        size[i] = 1;
        parent[i] = i;
    }

    int cnt = 0;

    arep(e,edges){
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;

        if(w < W) Union(u,v);
        else{
            if(find(u) != find(v)) cnt++;
        }
    }

    total -= W;

    printf("%lld %d\n", total, cnt);

}