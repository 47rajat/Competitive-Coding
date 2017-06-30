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

const int N = 60;
int grid[N][N];
vvi row;
int test,n;

int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>test;
    rep(t,test){
        cin>>n;

        memset(grid,0,sizeof(grid));
        row.clear();
        int col[n];
        memset(col,0,sizeof(col));
        rep(i,n){
            rep(j,n){
                char c;
                cin>>c;
                if(c == '.') grid[i][j] = 0;
                else grid[i][j] = 1;
            }
        }

        rep(i,n){
            row.pb({});
            rep(j,n){
                // cout << grid[i][j] << " ";
                if(grid[i][j] == 1){
                    row.back().pb(j);
                    col[j]++;
                }
            }
            // cout << endl;
        }

        bool ans = true;
        int rowone = 0;
        int cols[n][n];
        memset(cols, 0 , sizeof(cols));

        arep(i,row){
            if(i.size() == 2){
                cols[i[0]][i[1]]++;
                continue;
            }

            if(i.size() == 1 && rowone == 0){
                cols[i[0]][i[0]]++;
                rowone++;
                continue;
            }

            ans = false;
            break;
        }

        int single = 0;
        rep(i,n){
            if(!ans) break;
            rep(j,n){
                if(i == j){
                    single += cols[i][i];
                    continue;
                }
                if(cols[i][j] == 0 || cols[i][j] == 2) continue;

                ans = false;
                break;
            }
            if(col[i] > 2) ans = false;
        }

        if(ans && single == 1) cout << "Case #" << t+1 << ": " << "POSSIBLE" << endl;
        else cout << "Case #" << t+1 << ": " << "IMPOSSIBLE" << endl;

    }
}