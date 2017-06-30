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
string w;
int idx[100];
int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>test;

    rep(t,test){
        cin>> w;
        int n = w.size();
        memset(idx,-1,sizeof(idx));
        bool amb = true;
        string ans;
        if(n%2 == 0){
            amb = false;
            idx[1] = int(w[0]) - int('A');
            idx[n-2] = int(w[n-1]) - int('A');

            rep4(i,3,n,2){
                int v = int(w[i-1]) - int('A');
                if(v - idx[i-2] >= 0){
                    idx[i] = v - idx[i-2];
                    continue;
                }
                if(v + 26 - idx[i-2] < 26) idx[i] = v + 26 - idx[i-2];
            }

            for(int i = n-3; i >= 0; i--){
                int v = int(w[i+1]) - int('A');

                if(v - idx[i+2] >= 0){
                    idx[i] = v - idx[i+2];
                    continue;
                }

                if(v+26 - idx[i+2]) idx[i] = v+ 26 - idx[i+2];
            }

           
            rep(i,n){
                ans.push_back(char(idx[i] + int('A')));
            }
        }
        

        if(amb){
            cout << "Case #"<<t+1 << ": "<< "AMBIGUOUS" << endl;
        } else{
            cout << "Case #"<<t+1 << ": "<< ans << endl;
        }


    }
}