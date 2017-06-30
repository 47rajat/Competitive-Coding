#include <bits/stdc++.h>
using namespace std;
#define arep(i,arr) for(auto &i : arr)
#define rep(i,e) for(int i = 0; i < e; i++)
#define rep2(i,s,e) for(int i = s; i < e; i++)
#define rep3(i,e,x) for(int i = 0 ; i < e; i+=x)
#define rep4(i,s,e,x) for(int i = s; i < e; i+=x)
#define SZ(a) (int)(a.size())
#define pb push_back
#define mp make_pair

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef long long ll;

const int N = 1e5 + 10;

/*
The solution here uses biconnected components, block cut tree, lca and 
disjoint sets.
There is a method odl about which I don't understand anything.
*/
int n,m,q,t;
vi graph[N];
int u,v,w;
int parent[N];
bool visited[N];
bool art[N];
int disc[N];
int low[N];
vvi components;
vi stk;
int id[N];
vi tree[N];

void printStack(int u, int v){
    components.pb({u});

    while(components.back().back() != v){
        components.back().pb(stk.back());
        stk.pop_back();
    }
}

void biConnectUtil(int v){
    disc[v] = low[v] = ++t;
    visited[v] = true;
    int child = 0;
    stk.pb(v);

    for(auto &i : graph[v]){
        if(!visited[i]){
            child++;
            parent[i] = v;

            biConnectUtil(i);

            low[v] = min(low[v], low[i]);

            //checking articulation point condition for root node.
            if((parent[v] == -1) && child > 1){
                art[v] = true;
            }
            if((parent[v] > 0) && (low[i] >= disc[v])){
                art[v] = true;
            }
            if(low[i] >= disc[v]){
                printStack(v,i);
            }
        }else if((parent[v] != i) && (disc[i] < low[v])){
            low[v] = disc[i];
        }
    }
}

void findBiconnected(){
    rep2(i,1,n+1){
        if(!visited[i]){
            biConnectUtil(i);
        }
    }
}

int buildBlockCutTree(){
    int s = 1;
    rep2(v,1,n+1){
        if(art[v]) id[v] = s++;
    }

    arep(c,components){
        arep(v,c){
            if(!art[v]) id[v] = s;
            else{
                tree[s].pb(id[v]);
                tree[id[v]].pb(s);
            }
        }
        s++;
    }

    return s;

}

int p[N];
int size[N];
int find(int i){

    while(!(p[i] == i)){

        p[i] = p[p[i]];
        i = p[i];
    }

    return i;
}

void add(int x, int y){
    int xset = find(x);
    int yset = find(y);
    if(xset == yset) return;
    if(size[xset] < size[yset]){
        p[xset] = yset;
        size[yset] += size[xset];
    } else{
        p[yset] = xset;
        size[xset] += size[yset];
    }
}

const int NLOG = 19;
int table[N][NLOG];
int level[N];

void dfs(int v,int l, int par){
    visited[v] = true;
    level[v] = l;
    table[v][0] = par;

    rep2(i,1,NLOG){
        table[v][i] = table[table[v][i-1]][i-1];
    }

    arep(x, tree[v]){
        if(!visited[x]) dfs(x,l+1,v);
    }

}

int lca(int x, int y){
    if(level[x] > level[y]) swap(x,y);

    for(int q = NLOG-1; q > -1; q--){
        if(level[y] > level[x] && level[table[y][q]] >= level[x]){
            y = table[y][q];
        }
    }
    assert(level[x] == level[y]);
    
    if(x == y) return x;

    for(int q = NLOG -1; q > -1; q--){
        if(table[x][q] != table[y][q]){
            x = table[x][q];
            y = table[x][q];
        }
    }
    // cout << x << " " <<  table[x][0] << endl;
    // cout << y << " " <<  table[y][0] << endl;
    assert(table[x][0] == table[y][0]);
    return table[x][0];

}

//Figure out what is going on here.
int odl(int x, int y){
    int l = lca(x,y);
    return level[x] + level[y] - 2 * level[l];
}



int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>q;

    rep2(i,1,n+1){
        p[i] = i;
        size[i] = 1;
    }

    rep(i,m){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        add(a,b);
    }

    memset(disc,-1,sizeof(disc));
    memset(low,-1,sizeof(low));
    memset(parent,-1,sizeof(parent));
    memset(visited,false,sizeof(visited));
    memset(art, false, sizeof(art));

    t = 0;
    findBiconnected();

    int s = buildBlockCutTree();

    memset(visited,false,sizeof(visited));
    memset(table,-1,sizeof(table));
    rep2(i,1,s){
        if(!visited[i]) dfs(i,1,i);
    }

    rep(i,0){
        cin>>u>>v>>w;

        if(find(u) != find(v) || find(u) != find(w) || (u == v && u != w)){
            cout << "NO" << endl;
            continue;
        }

        //Figure out what is going on here.
        int leeway = 2 * int(art[w] != 0);

        u = id[u];
        v = id[v];
        w = id[w];

        if(odl(u,v) + leeway >= odl(u,w) + odl(v,w)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }


    rep2(i,1,s){
        rep(j,NLOG) cout << table[i][j]-1 << " ";
        cout << endl;
    }

    // rep2(i,1,2){
    //     cout << s << endl;
    // }

    // arep(c,tree){
    //     if(c.size() == 0) continue;
    //     arep(i,c) cout << i - 1<< " ";
    //     cout << endl;
    // }
}