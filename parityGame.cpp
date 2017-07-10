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

const int N = 1e3 + 10;
int a[N];
int n;


int main(){

    cin>>n;
    int total = 0;
    int odd = -1;
    rep(i,n){
        cin>>a[i];
        total += a[i];
        if(a[i] % 2 == 1 && odd < 0) odd = a[i]; 
    }

    if(total % 2 == 0) cout << 0 << endl;
    else{
        if( n> 1) cout << 1 << endl;
        else cout << -1 << endl;
    }
}