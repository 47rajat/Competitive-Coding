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

ll a;
int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>a;

    if(a%2){
        ll temp = a*a;
        ll b = (temp-1)/2;

        printf("%lld %lld %lld\n",a,b,b+1);
    } else{
        ll temp = a/2;
        ll b = temp*temp - 1;
        ll c = temp*temp + 1;

        printf("%lld %lld %lld\n",a,b,c);
    }

}