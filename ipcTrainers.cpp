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

const int N = 1e5 + 10;
int test;
int n,d;

vii day;
ll t[N];
ll s[N];
vii heap;

int main(){
    cin>>test;
    while(test--){
        cin>>n>>d;
        day.clear();
        rep(i,n){
            int di;
            cin>>di>>t[i]>>s[i];
            day.pb(mp(di,i));
        }

        sort(day.begin(), day.end());

        ll reduce = 0;
        heap.clear();
        int j;

        rep2(i,1,d+1){
            if(i == 1) j = 0;

            while(j < day.size() && day[j].first <= i){
                ii  p = day[j];
                heap.pb(mp(s[p.second], p.second));
                push_heap(heap.begin(), heap.end());
                j++;
            }

            if(heap.size() > 0){
                t[heap.front().second]--;
                if(t[heap.front().second] == 0){
                    pop_heap(heap.begin(), heap.end());
                    heap.pop_back();
                }
            }
        }


        ll ans = 0;

        rep(i,n){
            ans += s[i] * t[i]; 
        }

        cout << ans << endl;


    }
}