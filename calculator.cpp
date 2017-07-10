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
ll n, b;

int main(){
    cin>>test;

    while(test--){
        cin>>n>>b;

        if(b> n){
            cout << 0 << endl;
        }else{
            if(b > n/2){
                cout << n - b << endl;
            } else{
                ll m = n/(2*b);
                ll m1 = m+1;
                ll m2 = m-1;
                ll ans = 0;
                ans = max(ans, (n - m*b) * m);
                ans = max(ans, (n - m1*b) * m1);
                ans = max(ans, (n - m2*b)* m2);
                cout << ans << endl;
            }
        }
    }
}