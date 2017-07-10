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
string seq;

int main(){
    cin>>test;
    while(test--){
        cin>>seq;

        int p = 0;
        int q = 0;
        int large = 0;
        rep(i,seq.size()){
           if(seq[i] == '<'){
               p++;
               q = 0;
           }
           if(seq[i] == '>'){
               q++;
               p = 0;
           }

           large = max(p,large);
           large = max(q, large);
        }

        cout << large + 1<< endl;
    }
}