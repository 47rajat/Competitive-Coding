#include <bits/stdc++.h>
using namespace std;
#define rep(i,e) for(int i = 0; i < e; i++)
#define rep2(i,s,e) for(int i = s; i < e; i++)
#define rep3(i,e,x) for(int i = 0 ; i < e; i+=x)
#define rep4(i,s,e,x) for(int i = s; i < e; i+=x)

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

const int MAX = 1e5 + 10;
const int MAX_LOG = log2(MAX) + 1;
int n,q,total;
string full,p, current;
vi graph[MAX];
bool visited[MAX];
int parent[MAX];
int level[MAX];

int table[MAX][MAX_LOG];

void answer(int s){
    deque<int> queue;
    int l = 0;
    visited[s] = true;
    level[s] = l;
    queue.push_back(s);

    while(!queue.empty()){
         s = queue.front();
         queue.pop_front();
         l++;
         for(auto &i : graph[s]){
             if(!visited[i]){
                 parent[i] = s;
                 visited[i] = true;
                 level[i] = l;
                 queue.push_back(i);
             }
         }
    }
}

void preprocess(){
   for(int i = 1; i <= MAX; i++){
       for(int j = 0; (1<<j) < MAX; j++){
           table[i][j] = -1;
       }
   }

    rep2(i, 1, n+1){
        table[i][0] = parent[i];
    }
    

    for(int j = 1;  j < MAX_LOG; j++){
        rep2(i,1,n+1){
            if(table[i][j-1] != -1){
                // printf("called for j = %d\n",j);
                table[i][j] = table[table[i][j-1]][j-1];
            }
        }
    }
}


int lca(int u, int v){
    if(level[u] < level[v]) swap(u,v);

    int dist = level[u] - level[v];
    // printf("dist = %d\n", dist);

    while(dist > 0){
        int rise = log2(dist);
        u = table[u][rise];
        dist -= (1<<rise);
    }

    if(u == v) return u;

    for(int j = MAX_LOG-1; j >= 0; j--){

        if((table[u][j] != -1) && (table[u][j] != table[v][j])){
            // printf("called for u = %d, v = %d and j = %d\n",u,v,j);
            u = table[u][j];
            v = table[v][j];
        }
    }
    // printf("u = %d\n", u);
    return parent[u];

}

void find(int c, int d, int k){
    string first = "";
    string second = "";

    string both = "";

    for(int i = first.length()-1; i >= both.length(); i--) current.push_back(first[i]);
    // cout << current << endl;
    current.push_back(full[k-1]);

    for(int i = both.length()-1; i < second.length(); i++) current.push_back(second[i]);


    size_t pos = current.find(p,0);
    while(pos != string::npos){
        total++;
        pos = current.find(p,pos+1);
    }
}


int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>q;
    cin>>full;
    cin>>p;

    rep(i,n-1){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(visited,false,sizeof(visited));
    memset(parent,-1,sizeof(parent));
    memset(level, -1, sizeof(level));
    // path(a,b);
    answer(1);

    preprocess();

    rep(i,q){
        int a,b;
        cin>>a>>b;
        total = 0;
        current = "";
        // find(a,b,lca(a,b));
        cout << lca(4,3) << endl;
        // cout << current << endl;
        // cout << p << endl;
    }
    // cout << "printing table: "<< endl;
    // rep(i,n+1){
    //     rep(j,MAX_LOG){
    //         printf("table[%d][%d] = %d ", i,j,table[i][j]);
    //     }
    //     printf("\n");
    // }
}