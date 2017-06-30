#include <bits/stdc++.h>
using namespace std;
#define rep(i,e) for(int i = 0; i < e; i++)
#define rep2(i,s,e) for(int i = s; i < e; i++)
#define rep3(i,e,x) for(int i = 0 ; i < e; i+=x)
#define rep4(i,s,e,x) for(int i = s; i < e; i+=x)
#define pb push_back
#define mp make_pair

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

const int N = 1e5 + 5;
int n,m,t;
int even,odd;
vi graph[N];
int disc[N];
int low[N];
bool visited[N];
int parent[N];
int cnt[N];
vii edges;

void printStack(int u, int v){
    memset(cnt,0,sizeof(cnt));
    // cout << "printing new stack" << endl;
    while(!edges.empty() && (u != edges.back().first  && v != edges.back().second)){
        ii p = edges.back();
        edges.pop_back();
        cnt[p.first] = 1;
        cnt[p.second] = 1;
        // cout << p.first << " " << p.second << endl;
    }

    if(!edges.empty()){
        ii p = edges.back();
        edges.pop_back();
        cnt[p.first] = 1;
        cnt[p.second] = 1;
        // cout << p.first << " " << p.second << endl;
    }

    int ans = 0;
    rep(i,n+1) ans += cnt[i];

    if(ans%2==0)even++;
    else odd++;
}

void biConnectUtil(int v){
    disc[v] = low[v] = ++t;
    visited[v] = true;
    int child = 0;

    for(auto &i : graph[v]){
        if(!visited[i]){
            child++;
            edges.pb(mp(v,i));
            parent[i] = v;

            biConnectUtil(i);

            low[v] = min(low[v], low[i]);

            //checking articulation point condition for root node.
            if((parent[v] == -1) && child > 1){
                printStack(v,i);
            }
            if((parent[v] >= 0) && (low[i] >= disc[v])){
                printStack(v,i);
            }
        }else if((parent[v] != i) && (disc[i] < low[v])){
            low[v] = disc[i];
            edges.pb(mp(v,i));
        }
    }
}

void findBiconnected(){
    rep2(i,1,n+1){
        if(!visited[i]){
            biConnectUtil(i);
            printStack(-1,-1);
        }
    }
}

int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    rep(i,m){
        int u,v;
        cin>>u>>v;
        u++;
        v++;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    memset(disc,-1,sizeof(disc));
    memset(low,-1,sizeof(low));
    memset(parent,-1,sizeof(parent));
    memset(visited,false,sizeof(visited));
    t = 0;
    even = odd = 0;
    findBiconnected();

    printf("%d %d\n",odd,even);
}