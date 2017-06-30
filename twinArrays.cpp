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

const int MAX = 1e5;

int n;
int a[MAX], b[MAX];


int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    rep(i,n) cin>>a[i];
    rep(i,n) cin>>b[i];

    int min1, min2,min3,min4;
    min1 = min2 = min3 = min4 = INT_MAX;
    int idx1, idx3;
    idx1 = idx3 = -1;

    rep(i,n){

        if(a[i] < min1){
            min1 = a[i];
            idx1 = i;
        }
        if(b[i] < min3){
            min3 = b[i];
            idx3 = i;
        }
    }

    rep(i,n){
        if((a[i] < min2) && !(i==idx1)){
            min2 = a[i];
        }
        if((b[i] < min4) && !(i==idx3)){
            min4 = b[i];
        }
    }

    // cout << min1 << endl;
    // cout << min2 << endl;
    // cout << min3 << endl;
    // cout << min4 << endl;

    if(idx1 == idx3){
        cout << min(min1 + min4, min2 + min3) << endl;
    } else{
        cout << min1 + min3 << endl;
    }
    
}