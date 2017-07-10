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

const int N = 5e5 + 10;
int test;
ll l1,r1, a,b, c1,c2,n,m;
vll points;
ll contrib[N];

void printContrib(int n){
    cout << "Contrib" << endl;
    rep(i,n){
        cout << contrib[i] << " ";
    }
    cout << endl;
}

int main(){

    cin>>test;

    rep(t,test){

        cin>>n>>l1>>r1>>a>>b>>c1>>c2>>m;

        a = a % m;
        b = b % m;
        c1 = c1 % m;
        c2 = c2 % m;
        points.clear();
        points.pb(mp(l1,r1));
        memset(contrib, 0 , sizeof(contrib));

        ll  x,y;
        rep2(i,1,n){
            x = ((a * l1) % m + (b * r1) % m + c1) % m;
            y = ((b * l1) % m + (a * r1) % m + c2) % m;

            points.pb(mp(min(x,y), max(x,y)));
            l1 = x;
            r1 = y;
        }

        sort(points.begin(), points.end());

        ll total = 0;
        vector<ll> maxr;
        maxr.pb(0);
        int index;
        rep(i,n){
            if(i ==0){
                contrib[i] = points[i].second - points[i].first + 1;
                total += contrib[i];
                maxr.pb(points[i].second);
                index = i;
                // cout << " i = " << i << endl;
                // printContrib(n);
                continue;
            }

            if(points[i].second > maxr.back()){
                if(points[i].first <= maxr.back()){
                    contrib[i] = points[i].second - maxr.back();
                    total += contrib[i];
                    ll z = maxr[maxr.size()-2];
                    if(points[i].first > z) contrib[index] -= (maxr.back() - points[i].first + 1);
                    else contrib[index] -= (maxr.back() - z);
                } else{
                    contrib[i] = (points[i].second - points[i].first + 1);
                    total += contrib[i];
                }
                maxr.pb(points[i].second);
                index = i;
            } else{
                contrib[i] = 0;
                if(maxr.size() > 1){
                    ll z = maxr[maxr.size() - 2];
                    if(z < points[i].second){
                        if(points[i].first > z) contrib[index] -= (points[i].second - points[i].first + 1);
                        else contrib[index] -= (points[i].second - z);
                        maxr[maxr.size()-2] = points[i].second;
                    } 
                }
            }
            // cout << " i = " << i << endl;
            // printContrib(n);
        }

        ll reduce = 0;

        // cout << "Points " << endl;
        // rep(i,n){
        //     cout << points[i].first << ", " << points[i].second << endl;
        // }

        // printContrib(n);

        rep(i,n){
            reduce = max(contrib[i], reduce);
        }

        // cout << total << " - " << reduce << endl;

        printf("Case #%d: %lld\n",t+1,total - reduce);
        // printf("Case #%d: %lld - %lld\n",t+1,total, reduce); 
        
    }
}