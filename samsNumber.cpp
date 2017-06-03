#include <stdio.h>
#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <sstream>
#include <cstring>
using namespace std ;

#define ft first
#define sd second
#define pb push_back
#define all(x) x.begin(),x.end()

#define ll long long int
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define plii pair<pair<ll, int>, int>
#define piii pair<pii, int>
#define viii vector<pair<pii, int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)

#define sc1(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define scll1(x) scanf("%lld",&x)
#define scll2(x,y) scanf("%lld%lld",&x,&y)
#define scll3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

#define pr1(x) printf("%d\n",x)
#define pr2(x,y) printf("%d %d\n",x,y)
#define pr3(x,y,z) printf("%d %d %d\n",x,y,z)

#define prll1(x) printf("%lld\n",x)
#define prll2(x,y) printf("%lld %lld\n",x,y)
#define prll3(x,y,z) printf("%lld %lld %lld\n",x,y,z)

#define pr_vec(v) for(int i=0;i<v.size();i++) cout << v[i] << " " ;

#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)

#define fr(i, a, b) for(i=a; i<=b; i++)
#define fb(i, a, b) for(i=a; i>=b; i--)`
#define ASST(x, l, r) assert( x <= r && x >= l )

const int mod = 1e9 + 9;

int ADD(int a, int b, int m = mod) {
    int s = a;
    s += b;
    if( s >= m )
      s -= m;
    return s;
}

int MUL(int a, int b, int m = mod) {
    return (1LL * a * b % m);
}

int power(int a, int b, int m = mod) {
    int res = 1;
    while( b ) {
        if( b & 1 ) {
            res = 1LL * res * a % m;
        }
        a = 1LL * a * a % m;
        b /= 2;
    }
    return res;
}

ll nC2(ll x) {
    return ( x * ( x - 1 ) / 2 );
}

const int MAXN = 110000;
int f[25][25], m, d, t[105][105], res[105][105];
ll n;
void mult(int a[][105], int b[][105], int m) {
    int tmp[105][105];
    for(int i=1; i<=m * m; i++) {
        for(int j=1; j<=m * m; j++) {
            tmp[i][j] = 0;
            for(int k=1; k<=m * m; k++) {
                tmp[i][j] += 1LL * a[i][k] * b[k][j] % mod;
                if( tmp[i][j] >= mod ) tmp[i][j] -= mod;
            }
        }
    }
    for(int i=1; i<=m*m; i++) {
        for(int j=1; j<=m*m; j++) {
            a[i][j] = tmp[i][j];
        }
    }
}
void solve(int z) {
        cin >> n >> m >> d;     
        ASST(n, 1, 1000000000000000000LL);
        ASST(m, 1, 10);
        ASST(d, 0, m-1);
        ms(f, 0);
        ms(t, 0);
        ms(res, 0);
        for(int i=1; i<=m; i++) f[i][i] = 1;
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=m; j++) {
                for(int k=1; k<=m; k++) {
                    if(abs(j - k) <= d) f[i+k][k] += f[i][j];
                    if(f[i+k][k] >= mod) f[i+k][k] -= mod;
                }
            }
        }
        
        int ans = 0;
        if(n <= m) {
            for(int i=1; i<=m; i++) {
                ans += f[n][i];
                if( ans >= mod ) ans -= mod;
            }
            cout << ans << "\n";
            return;
        }

        n -= m;
        for(int i=1; i<=m * m; i++) {
            res[i][i] = 1;
            int ind1 = ( i - 1 ) % m + 1;
            int val1 = m + 2 - (( i - 1 ) / m + 1);
            for(int j=1; j<=m * m; j++) {
                int ind2 = ( j - 1 ) % m + 1;
                int val2 = m + 1 - (( j - 1 ) / m + 1);
                if( val1 <= m && ind1 == ind2 && val1 == val2 ) {
                    t[i][j] = 1;
                }
                if( val1 > m && abs(ind1 - ind2) <= d && val1 - val2 == ind1) {
                    t[i][j] = 1;
                }
            }
        }

        //My code starts 
        for(int i =0; i <= m*m; i++){
            for(int j = 0; j <= m*m; j++){
                cout << t[i][j] << " ";
            }
            cout << endl;
        }

        //My code ends.
        
        while( n ) {
            if(n & 1) {
                mult(res, t, m);
            }
            mult(t, t, m);
            n /= 2;
        }

        for(int i=1; i<=m; i++) {
            for(int j=1; j<=m * m; j++) {
                int idx = ( j - 1 ) % m + 1;
                ans += 1LL * res[i][j] * f[m - (j - 1) / m][idx] % mod;
                if( ans >= mod ) ans -= mod;
            }
        }
        cout << ans << "\n";

}

int main() {
    int t = 1; // cin >> t;
    for(int i=1; i<=t; i++) solve(t);
    return 0;
}