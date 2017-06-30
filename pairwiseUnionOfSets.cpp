#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,s,e) for(int i = s; i < e; i++)

const int MAX = 2500 + 5;
int matrix[MAX][MAX];
int n, k, test;
int main(){
    cin>> test;
    
    rep(t,test){
        cin>>n>>k;
        memset(matrix,0,sizeof(matrix));
        rep(i,n){
            int len;
            cin>>len;
            matrix[i][0] = len;
            rep(b,len){
                int value;
                cin>>value;
                matrix[i][value] = 1;
            }
        }

        // rep(i,n){
        //     rep(j,k+1){
        //         cout << matrix[i][j];
        //     }
        //     cout <<endl;
        // }

        int result = 0;
        rep(i,n){
            rep2(j,i+1,n){
                if(matrix[i][0] + matrix[j][0] >= k){
                    int ans = 0;
                    rep2(e,1,k+1){
                        ans += matrix[i][e]|matrix[j][e];
                    }
                    if(ans == k) result += 1;

                }
            }
        }

        cout <<result << endl;
    }
	
}