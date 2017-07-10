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


int test;
ll l, r;
string s;
int a[110];

int main(){
    cin>>test;
    rep(t,test){
        memset(a,0,sizeof(a));
        cin>>s;
        int n = s.size();
        rep(i,s.size()){
            if(s[i] == 'B') a[i] = 1;
        }

        cin>>l>>r;
        l--;
        unsigned long long cnt = 0;

        rep2(i,l%n,n){
            cnt += a[i];
        }

        rep(i,r%n) cnt += a[i];

        int tot = 0;
        rep(i,n) tot += a[i];

        l = l + n - l%n;
        r = r - r%n;

        if(r > l) cnt += tot * ((r - l)/n);

        printf("Case #%d: %lld\n", t+1, cnt);

    }
}