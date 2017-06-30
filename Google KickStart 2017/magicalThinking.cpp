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

int test,n,q;
int answers[3][60];
int scores[3];

int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>test;

    rep(t,test){
        cin>>n>>q;
        memset(answers,0,sizeof(answers));
        memset(scores,0,sizeof(scores));
        rep(i,n+1){
            rep(j,q){
                char c;
                cin>>c;
                if(c == 'T') answers[i][j] = 1;
            }
        }
        rep(i,n){
            cin>>scores[i];
        }

        if(n == 1){
            int p = 0;
            int right = scores[0];
            int wrong = q - right;

            rep(i,q){
                if(answers[0][i] == answers[1][i] && right > 0){
                    p++;
                    right--;
                }else if (answers[0][i] != answers[1][i] && wrong > 0){
                    p++;
                    wrong--;
                }
            }

            cout << "Case #" << t+1 << ": " << p << endl;
        }else{
            int a,b,c,d;
            int p = 0;
             a = b = c = d = 0;

            rep(i,q){
                if(answers[0][i] == answers[2][i] && answers[2][i] == answers[1][i]){
                    a++;
                    continue;
                }
                if(answers[0][i] == answers[2][i] && answers[1][i] != answers[2][i]){
                    b++;
                    continue;
                }
                if(answers[0][i] != answers[2][i] && answers[1][i] == answers[2][i]){
                    c++;
                    continue;
                }
                if(answers[0][i] != answers[2][i] && answers[1][i] != answers[2][i]){
                    d++;
                }
            }

            rep(i,a+1){
                rep(j,b+1){
                    rep(k,c+1){
                        rep(l,d+1){
                            int scoreone = i + j + c - k + d - l;
                            int scoretwo = i + b - j  + k + d - l;
                            if(scoreone == scores[0] && scoretwo == scores[1]) p = max(p, i+j+k+l);
                        }
                    }
                }
            }

            cout << "Case #" << t+1 << ": " << p << endl;
        }

    }
}