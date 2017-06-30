#include <bits/stdc++.h>
using namespace std;
#define rep(i,e) for(int i = 0; i < e; i++)
#define rep2(i,s,e) for(int i = s; i < e; i++)
#define rep3(i,e,x) for(int i = 0 ; i < e; i+=x)
#define rep4(i,s,e,x) for(int i = s; i < e; i+=x)
#define pb push_back

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

const int N = 1e5 + 5;
int n,m,t;
vi graph[N];
int disc[N];
int low[N];
bool visited[N];
int parent[N];
bool aPoint[N];


void findAP(int v){
    visited[v] = true;
    //settting discovery time.
    disc[v] = low[v] = ++t;
    int child = 0;

    for(auto &i : graph[v]){
        if(!visited[i]){
            child++;
            parent[i] = v;

            findAP(i);

            //settting the lowest discovered vertex
            low[v] = min(low[v], low[i]);

            //checking articulation point condition for root of tree.
            if((parent[v] == -1) && child > 1) aPoint[v] = true;

            //checking articulation point condition for non-root node
            if((parent[v] >= 0) && low[i] >= disc[v]) aPoint[v] = true;
        } else if(parent[v] != i){
            low[v] = min(low[v], disc[i]);
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
        graph[u].pb(v);
        graph[v].pb(u);
    }

    memset(disc,-1,sizeof(disc));
    memset(low,-1,sizeof(low));
    memset(parent,-1,sizeof(parent));
    memset(visited,false,sizeof(visited));
    memset(aPoint,false,sizeof(aPoint));
    t = 0;
    findAP(1);

    rep(i,n){
        if(aPoint[i]) cout << i << endl;
    }
}