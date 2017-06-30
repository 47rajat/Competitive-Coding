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

int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>q;

    rep(i,q){
        int n;
        cin>>n;
        int box[n];
        rep(b,n) cin>>box[b];

        int error = 0;
        int error_one = 0;
        long total = 0;
        rep(b,n){
            if(!((b%2) == (box[b]%2))){
                if(box[b] == 1) error_one++;
                else error++;
            }
            total += box[b];
        }

        if(total < 2*ceil(n/(double)2) + floor(n/(double)2)){
            cout << -1 << endl;
        }else{
            if((error + error_one) % 2 == 1) cout << -1 << endl;
            else{
                if(error >= error_one) cout << (error + error_one)/2 << endl;
                else cout << error_one << endl;
            }
        }
    }
}