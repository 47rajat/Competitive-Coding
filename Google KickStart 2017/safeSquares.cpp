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

int test, r, c, k;

int grid[3010][3010];
int table[3010][3010];

int main(){
    cin>>test;
    rep(t,test){
        cin>>r>>c>>k;

        memset(grid,0,sizeof(grid));
        memset(table,0,sizeof(table));

        rep(i,k){
            int a,b;
            cin>>a>>b;
            grid[a][b] = 1;
        }

        rep(i,r){
            rep(j,c){
                if(i ==  0 ||  j == 0){
                    if(grid[i][j] == 0) table[i][j] = 1;
                }
                else{
                    if(grid[i][j] == 0) table[i][j] = min(table[i][j-1], min(table[i-1][j], table[i-1][j-1])) + 1;
                    else table[i][j] = 0;
                }
            }
        }
        ll total = 0;
        rep(i,r){
            rep(j,c){
                // printf("%d ", table[i][j]);
                total += table[i][j];
            }
            // printf("\n");
        }
        printf("Case #%d: %lld",t+1, total);
        printf("\n");
    }
}