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


int test,mx,mn,me,md;

void impossible(int t){
    cout << "Case #" << t + 1<< ": IMPOSSIBLE" <<endl;
}

void possible(int t, int x){
    cout << "Case #" << t + 1<< ": " << x << endl;
}

int main(){
    cin>>test;
    rep(t,test){
        cin>>mn>>mx>>me>>md;

        if(mn > mx || mn > me || mn > md || me > mx || md > mx){
            impossible(t);
        }else if(mn == mx && mx == me && me == md){
            possible(t,1);
        } else if(2 * me == (mn + mx) && md == me){
            possible(t,2);
        } else{
            int sur1 = mn + mx + md - 3*me;
            int l1 = 3;
            int diff1;
            if(sur1 > 0) diff1 = 2*me - mn - md;
            else if(sur1 == 0){
                possible(t,l1);
                continue;
            } else{
                sur1 *= -1;
                diff1 = mx + md - 2*me;
            }

            int sur2 = mn + mx + md + md - 4 * me;
            int l2 = 4;
            int diff2;
            if(sur2 > 0) diff2 = 2*me - mn - md;
            else if(sur2 == 0){
                possible(t,l2);
                continue;
            } else{
                sur2 *= -1;
                diff2 = mx + md - 2*me;
            }

            if(diff1 <= 0 && diff2 <= 0){
                impossible(t);
                continue;
            }

            if(diff1 <=0){
                l2 += 2 * ceil(double(sur2)/double(diff2));
                possible(t,l2);
                continue;
            }

            if(diff2 <= 0){
                l1 += 2* ceil(double(sur1)/double(diff1));
                possible(t,l1);
                continue;
            }

            l2 += 2* ceil(double(sur2)/double(diff2));
            l1 += 2 * ceil(double(sur1)/double(diff1));

            possible(t, min(l1,l2));
        }
    }
}