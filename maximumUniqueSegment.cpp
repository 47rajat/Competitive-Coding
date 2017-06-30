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

int test,n;
const int N = 1e6 + 10;
int w[N], c[N];
int idx[N];
ll sm[N];

int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>test;

    while(test--){
        cin>> n;

        rep(i,n) cin>>c[i];
        rep(i,n) cin>>w[i];

        ll maxSum = -1;

        int i = 0; 
        unordered_map<int,int> enc;
        while(i < n){
            ll sum = w[i];
            int j = i + 1;
            enc[c[i]] = i;
            while(j < n && enc.find(c[j]) == enc.end()){
                enc[c[j]] = j;
                sum += w[j];
                j++;
            }
            maxSum = max(sum,maxSum);
            // cout << "j = " << j << endl;
            if(j == n) break;
            i = enc[c[j]] + 1;
            enc.clear();
        }

        

        cout << max(maxSum,(ll)w[n]) << endl;
    }
}