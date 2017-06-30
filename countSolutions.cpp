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
ll a,b,c,d;

int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>q;

    rep(i,q){
        cin>>a>>b>>c>>d;

        int ans = 0;
        for(ll y = 1; y <= d; y++){
            ll d2 = a*a - 4*(y*y - b*y);
            ll d = sqrt(d2);

            if(d2 < 0 || !(d*d == d2)) continue;

            ll x1 = a+d;
            ll x2 = a-d;

            if(x1 % 2 == 0){
                x1 /= 2;
                if(x1 >= 1 && x1 <=c){
                    // printf("x = %lld, y = %lld\n", x1,y);
                    // printf("d2 = %lld\n",d2);
                    // printf("d = %lld\n",d);
                    ans++;
                }
            }

            if(d > 0 && x2 % 2 == 0){
                x2 /= 2;
                if(x2 >= 1 && x2 <= c){
                    // printf("x = %lld, y = %lld\n", x2,y);
                    // printf("d2 = %lld\n",d2);
                    // printf("d = %lld\n",d);
                    ans++;
                }
            }

        }

        cout << ans << endl;

    }
}