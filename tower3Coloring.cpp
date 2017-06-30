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

const int MOD = 1e9 + 7;

ll n;

int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    ll ans = 1;
    ll x = 3;
    while(n>0){
        if(n&1) ans = (ans*x) % (MOD-1);

        n = n>>1;
        x = (x*x) % (MOD-1);
    }

    ll res = 1;
    ll y = 3;
    while(ans > 0){
        if(ans&1) res = (res*y) % MOD;
        ans = ans>>1;
        y = (y*y)% MOD;
    }

    cout << res << endl;
}