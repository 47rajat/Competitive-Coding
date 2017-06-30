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

/* The solution here is to find the period which allows for substring 
rotation. If `d` is the period for rotation of a substring [l,r] then
the total number of rotation is given by phi(r-l+1/d), where phi is the 
Euler's totient function. To find `l` and `r` we will use two pointers.

The solution take O(|s|^2) time.
*/

const int N = 6000 + 10;
string s;
int phi[N];


int main(){
    cin>>s;

    int n = s.size();

    rep2(i,1,n+1) phi[i] = i;

    rep2(i,2,n+1){
        if(phi[i] == i){
            rep4(j,i,n+1,i) phi[j] -= phi[j]/i;
        }

        phi[i] += phi[i-1]; //cumulative sum
    }

    ll total = 0;

    rep2(d,1,n+1){
        for(int l = 0, r = d; l + d <= n; l++){
            for(r = max(r,l+d); s[r-d] == s[r]; r++);

            total += phi[(r-l)/d];
        }
    }

    printf("%lld\n", 2*total - (n*(n+1))/2);

}