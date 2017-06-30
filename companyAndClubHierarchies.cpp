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

/** The problem can be reduced to having a tree with each node having a color
and a level. The task here is to find a set of nodes that satisfies given conditions.
*/

/**
The problem is solved using dyanmic programming and dfs
*/


const int N = 5e5 + 10;
const int M = 1e9 + 7;
int test,n,x;
vi graph[N];
int color[N];
int cnt[N];
int level[N];
int result[N];
vi dp[N];

void dfs(int v){
    int s = level[v] > 0 && level[v] < cnt[color[v]] ? dp[color[v]][level[v] -1] : 0;

    arep(i,graph[v]){
        dfs(i);
    }

    if(level[v] >= cnt[color[v]]){
        return;
    }
    
    if(level[v] == 0){
        result[v] = 1;
        dp[color[v]][level[v]] = (dp[color[v]][level[v]] + 1) % M;
    }else{
        result[v] = (result[v] + dp[color[v]][level[v]-1] - s + M) % M;
        dp[color[v]][level[v]] = (dp[color[v]][level[v]] + result[v]) % M;
    }
}


int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>test;

    while(test--){
        cin>>n>>x;

        memset(graph,{},sizeof(graph));
        memset(result, 0 , sizeof(result));
        memset(cnt, 0, sizeof(cnt));

        rep2(i,1,n){
            int p;
            cin>>p;
            graph[p].pb(i);
        }

        rep(i,n){
            cin>>color[i];
            cnt[color[i]]++;
        }

        rep(i,n){
            dp[i] = vi(cnt[i]);
        } 

        rep(i,n) cin>>level[i];

        dfs(0);

        rep(i,n) printf("%d\n", result[i]);
    }
}