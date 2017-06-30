
#include <bits/stdc++.h>
using namespace std;
#define rep(i,e) for(int i = 0; i < e; i++)
#define rep2(i,s,e) for(int i = s; i < e; i++)
#define rep3(i,e,x) for(int i = 0 ; i < e; i+=x)
#define rep4(i,s,e,x) for(int i = s; i < e; i+=x)
 
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
const int MAX = 1e5 + 5;
const int TREE_SIZE = 1e6 + 10;
int test, n, q;
int arr[MAX];
int maxTree[TREE_SIZE];
int minTree[TREE_SIZE];
 
 
void constructMaxTree(int start, int end, int current){
    if(start == end){
        maxTree[current] = arr[start];
        return;
    }
 
    int mid = start + (end - start)/2;
    constructMaxTree(start, mid, 2*current);
    constructMaxTree(mid+1,end, 2*current+1);
 
    int  v1 = maxTree[2*current];
    int  v2 = maxTree[2*current + 1];

    maxTree[current] = max(v1, v2);
    
}

void constructMinTree(int start, int end, int current){
    if(start == end){
        minTree[current] = arr[start];
        return;
    }
 
    int mid = start + (end - start)/2;
    constructMinTree(start, mid, 2*current);
    constructMinTree(mid+1,end, 2*current+1);
 
    int  v1 = minTree[2*current];
    int  v2 = minTree[2*current + 1];

    minTree[current] = min(v1, v2);
}
 
int getMax(int start, int end, int a, int b, int current){
 
    if(a <= start and b >= end){
        return maxTree[current];
    }
 
    if(end < a || start > b)
    return INT_MAX;
 
    int mid = start + (end - start)/2;
 
    int v1 = getMax(start,mid, a, b, 2*current);
    int v2 = getMax(mid+1, end, a, b, 2*current+1);
 
    return max(v1,v2);
}

int getMin(int start, int end, int a, int b, int current){
    if(a <= start and b >= end){
        return minTree[current];
    }
 
    if(end < a || start > b)
    return 0;
 
    int mid = start + (end - start)/2;
 
    int v1 = getMin(start,mid, a, b, 2*current);
    int v2 = getMin(mid+1, end, a, b, 2*current+1);
 
    return min(v1,v2);
}
 
int main(){
	// using these two lines for faster input/output using cin and cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin>>test;
    rep(t,test){
 
        cin>>n>>q;
 
        rep(i,n) cin>>arr[i];
 
        constructMaxTree(0,n-1,1);
        constructMinTree(0,n-1,1);

        rep(i,q){
            int a,b,c,d;
            cin>>a>>b>>c>>d;

            int allMin = getMin(0,n-1,a-1,d-1,1);
            int allMax = getMax(0,n-1,a-1,d-1,1);

            if(allMin == allMax){
                cout << "YES" << endl;
            }
 
            int diff = 0;
 
            int min1 = getMin(0,n-1,a-1,b-1,1);
            int max1 = getMax(0,n-1,a-1,b-1,1);
            int min2 = getMin(0,n-1,c-1,d-1,1);
            int max2 = getMax(0,n-1,c-1,d-1,1);

            if((min1 == min2) && (max1 == max2)){
                vi v1(arr+a-1, arr + b);
                vi v2(arr + c -1, arr + d);
    
                sort(v1.begin(), v1.end());
                sort(v2.begin(), v2.end());
    
                int diff = 0;
    
                rep(j,b-a+1){
                    if(v1.at(j) != v2.at(j)) diff++;
    
                    if(diff > 1) break;
                }
    
                if(diff > 1) cout << "NO" << endl;
                else cout << "YES" << endl;
            } else{
                cout << "NO" << endl;
            }
        }

        // rep(i,4*n){
        //     printf("Min tree at %d = %d\n",i,minTree[i]);
        //     printf("Max tree at %d = %d\n",i, maxTree[i]);
        // }
    }
 
} 