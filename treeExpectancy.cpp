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
typedef vector<pair<ll,ll>> vll;

int test;
const int M1 = 1e9 + 7;
const int M2 = 1e9 + 9;
ll n;

ll  power(ll x, int y , int m){
    if(y == 0) return 1;

    ll p = power(x, y/2, m) % m;

    p = ((p%m) * (p%m)) % m;

    return (y % 2 == 0)? p : ((x%m) * (p%m)) % m;
}

int main(){
    cin>>test;
    while(test--){
        cin>> n;

        if(n == 1) cout << 0 << " " << 0 << endl;
        else{
            ll num1 = ((n%M1)*((n-1)%M1))%M1;
            ll num2 = ((n%M2)*((n-1)%M2))%M2;
            ll den = 2*(2*n-3);
            int q1 = power(den, M1 - 2, M1);
            int q2 = power(den, M2-2, M2);

            int ans1 = (num1 * q1)% M1;
            int ans2 = (num2 * q2) % M2;

            cout << ans1 << " " << ans2 << endl;
        }

        
    }
}