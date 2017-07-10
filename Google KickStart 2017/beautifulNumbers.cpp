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
ll n;

int main(){
    cin>>test;

    rep(t,test){
        cin>>n;

        ll base = 2;
        bool found = false;
        while(base < 1e6){
            ll temp = n;
            while(temp % base == 1){
                temp /= base;
            }
            if(temp == 0){
                found = true;
                break;
            }
            base++;
        }

        if(!found){
            ll root = sqrt(4*n - 3);
            if(root * root == 4*n - 3){
                ll d = root - 1;
                if(d % 2 == 0){
                    base = d/2;
                    found = true;
                }
            }
        }

        if(!found){
            base = n - 1;
        }

        // printf("%f\n", sqrt(4*1e18));
        printf("Case #%d: %lld\n", t+1,base);
    }
}