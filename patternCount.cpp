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

int q;
string s;

int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>q;

    rep(i,q){
        cin>>s;

        bool start, zero;
        start = zero = false;
        int ans = 0;

        rep(j,s.size()){
            if(s[j] == '1'){
                if(zero){
                    ans++;
                    zero = false;
                }
                start = true;
            }

            if(start && s[j] == '0') zero = true;

            if(!(s[j] == '0') && !(s[j] == '1')){
                start = false;
                zero = false;
            }
        }

        cout << ans << endl;
    }
}