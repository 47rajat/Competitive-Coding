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

/* The solution here will use three concepts:
i) Convert each matrix element x to 2^x. Then the pallindromic rectangle will have xor sum 
    of elements equal to zero or some power of 2. (Draw example if not clear)
ii) A table for storing xor sums, where xor-sum for submatrix <(x1,y1),(x2,y2)> (S[x1,y1][x2,y2])
    can be computed as:
    S[x1,y1][x2,y2] = S[1,1][x2,y2] xor S[1,1][x1-1,y2] xor S[1,1][x2,y1-1] xor S[1,1][x1-1,y1-1]
iii) Also use an additional table `nonzero` to keep count of nonzero elements in the submatrix, using
    a sum area table.
*/

int n,m,tr,tc,br,bc, maxArea;
vector<vi> table;
vector<vi> nonzero;

bool isPow2(int x){
    int p = log2(x);

    return int(pow(2,p)) == x;
}

bool isPal(int u, int v, int x, int y){
    int ans = table[x][y];

    if(u > 0) ans ^= table[u-1][y];
    if(v > 0) ans ^= table[x][v-1];
    if(u > 0 && v > 0) ans ^= table[u-1][v-1];

    // printf("u = %d, v = %d, x = %d, y = %d, ans = %d\n", u,v,x,y,ans);
    return (ans == 0) || isPow2(ans);

}

bool isNonZero(int u, int v, int x, int y){
    int ans = nonzero[x][y];
    
    if(u > 0) ans -= nonzero[u-1][y];
    if(v > 0) ans -= nonzero[x][v-1];
    if(u > 0 && v > 0) ans += nonzero[u-1][v-1];

    return ans > 1;
}

int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    int matrix[n][m];
    rep(i,n){
        rep(j,m){
            cin>>matrix[i][j];
        }
    }

    rep(i,n){
        //col for the xor-sum table
        vi col;
        //column for nonzero table
        vi col2;
        rep(j,m){
            int c = matrix[i][j] > 0;
            if(i > 0) c += nonzero[i-1][j];
            if(j > 0) c += col2[j-1];
            if(i > 0 && j > 0) c -= nonzero[i-1][j-1];
            col2.push_back(c);

            int b = pow(2,matrix[i][j]);
            if(i > 0) b ^= table[i-1][j];
            if(j > 0) b ^= col[j-1];
            if(i > 0 && j > 0) b ^= table[i-1][j-1];
            col.push_back(b);
        }
        table.push_back(col);
        nonzero.push_back(col2);
    }

    for(int i = n; i > 0; i--){
        for(int j = m; j > 0; j--){
            if(maxArea > i*j) continue;
            rep(u,n-i+1){
                rep(v,m-j+1){
                    int x = u + i;
                    int y = v + j;
                    
                    if(isPal(u,v,x-1,y-1) && isNonZero(u,v,x-1,y-1)){
                        maxArea = i*j;
                        tr = u;
                        tc = v;
                        br = x-1;
                        bc = y-1;
                    }
                }
            }
        }
    }

    // cout << "printing table : " << endl;
    // rep(i,n){
    //     rep(j,m){
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << max(maxArea,1);
    printf("%d %d %d %d", tr,tc,br,bc);
    cout<<endl;

}