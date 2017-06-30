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

const int N = 2e5;
int t,n,m;
vi graph[N];
bool nodes[N];
vii edges;

bool visited[N];
bool reStack[N];
bool mark[N];


bool isCyclic(int v){
    if(!visited[v]){
        visited[v] = true;
        reStack[v] = true;

        arep(i,graph[v]){
            if(!visited[i] && isCyclic(i)){
                nodes[v] = true;
                return true;
            }
            else if(reStack[i]){
                nodes[v] = true;
                return true;
            }
        }
    }

    reStack[v] = false;
    return false;
}



int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>t;

    rep(p,t){
        cin>>n>>m;
        memset(graph,{},sizeof(graph));
        edges.clear();
        rep(i,m){
            int a,b;
            cin>>a>>b;
            graph[a].pb(b);
            edges.pb(mp(a,b));
        }

        memset(visited,false,sizeof(visited));
        memset(reStack,false,sizeof(reStack));
        memset(nodes, false, sizeof(nodes));

        rep2(i,1,n+1){
            isCyclic(i);
        }

        memset(mark, false, sizeof(mark));
        int answer = 0;
        int new_answer = 0;
        do{
            int i = 0;
            answer = new_answer;
            arep(e,edges){
                i++;
                if(!mark[i] && nodes[e.second]){
                    new_answer++;
                    nodes[e.first] = true;
                    mark[i] = true;
                }
            }
        } while(new_answer > answer);
        assert(new_answer == answer);
        cout << new_answer << endl;

    }
}