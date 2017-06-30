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
const int SEQ_SIZE = 1e3 + 10;
int n,k,m;
int parent[MAX];
int size[MAX];
int dict[MAX];
int seq[SEQ_SIZE];
int dp[SEQ_SIZE][SEQ_SIZE];


int find(int i){

    while(!(parent[i] == i)){

        parent[i] = parent[parent[i]];
        i = parent[i];
    }

    return i;
}

bool connected(int i, int j){
    return dict[i] == dict[j];
}

void add(int x, int y){
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

int lps(int m){
    
    rep(i,m){
        dp[i][i] = 1;
    }

    rep2(s,2,m+1){
        rep(i,m-s+1){
           int  j = i + s -1;
           if(((seq[i] == seq[j]) || connected(seq[i],seq[j])) && s == 2) dp[i][j] = 2;

           else if((seq[i] == seq[j]) || connected(seq[i],seq[j])) dp[i][j] = dp[i+1][j-1] + 2;
           else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }

    return dp[0][m-1];

}

int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k>>m;

    rep(i,n+1){
        parent[i] = i;
    }
    memset(size, 1, sizeof(size));

    rep(i,k){
        int a,b;
        cin>>a>>b;
        add(a,b);
    }

    rep(i,m){
        cin>>seq[i];
    }

    rep(i,n+1){
        // cout <<find(i) << endl;
        dict[i] = find(i);
    }

    cout << lps(m) << endl;

    // rep(i,m+1){
    //     rep(j,m+1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

}