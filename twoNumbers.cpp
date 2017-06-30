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
ll a,b,n;

int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>test;

    while(test--){
        cin>>a>>b>>n;

        ll fa = ceil(n/(double)2);
        ll fb = floor(n/double(2));

        ll fact = pow(2,fa-fb);

        double la = log2(a);
        double lb = log2(b);

        if(la + fa > lb + fb){
            cout << (fact*a)/b << endl;
        }else{
            cout << b/(fact*a) << endl;
        }
    }
}