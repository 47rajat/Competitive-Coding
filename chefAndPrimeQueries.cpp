#include <bits/stdc++.h>
using namespace std;
#define rep(i,e) for(int i = 0; i < e; i++)
#define rep2(i,s,e) for(int i = s; i < e; i++)
#define rep3(i,e,x) for(int i = 0 ; i < e; i+=x)
#define rep4(i,s,e,x) for(int i = s; i < e; i+=x)


typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAX = 1e6 + 5;
const int PRIME_SIZE = 80000;
int mark[MAX];
int primes[PRIME_SIZE];
int n, q;
const int SIZE = 1e5 + 5;
int a[SIZE];
vi tree[2*SIZE + 100];
vi table[SIZE];



void getPrimes(){
    int index = 0;
    rep2(i,2,MAX){
        if (mark[i] == 0){
            primes[index++] = i;
            rep4(j,i,MAX,i){
                if (mark[j] == 0) mark[j] = i;
            }
        }
    }
}

void constructTree(int start, int end, int current){

    if(start == end){
        tree[current] = table[start];
        return;
        // printf("setting table element %d to tree element %d\n",start,current);
    }

    int mid = start + (end - start)/2;
    constructTree(start,mid,2*current);
    constructTree(mid+1,end,2*current+1);
    vi v1 = tree[2*current];
    vi v2 = tree[2*current + 1];
    tree[current].insert(tree[current].end(), v1.begin(),v1.end());
    tree[current].insert(tree[current].end(), v2.begin(),v2.end());
    sort(tree[current].begin(),tree[current].end());

}

int getAnswer(int start, int end, int l, int r, int current, int x, int y){

    if (l <= start && r >= end){
        int low = distance(tree[current].begin(), lower_bound(tree[current].begin(), tree[current].end(),x));
        int high = distance(tree[current].begin(), upper_bound(tree[current].begin(), tree[current].end(), y));
        return high-low;
    }

    if(end < l || start > r){
        return 0;
    }

    int mid = start + (end - start)/2;

    return getAnswer(start,mid,l,r,2*current,x,y) + getAnswer(mid+1,end,l,r,2*current+1,x,y);
}

int main(){
    // using these two lines for faster input/output using cin and cout
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

	getPrimes();

    scanf("%d",&n);

    int i = 0;
    while(i < n) scanf("%d", &a[i++]);
    rep(i,n){
        int t = a[i];
        vi powers;
        int curr = mark[t];

        while(t > 1){
            t /= curr;

            if(curr == mark[t]){
                powers.push_back(curr);
                continue;
            }
            powers.push_back(curr);
            curr = mark[t];
        }
        // printf("for index = %d, size = %lu",i,powers.size());
        // cout<<endl;
        table[i] = powers;
    }

    
    constructTree(0,n-1,1);
    scanf("%d",&q);
    rep(i,q){
        int l,r,x,y;
        scanf("%d%d%d%d",&l,&r,&x,&y);
        int total = 0;
        // vi v = getVector(0,n-1,l-1,r-1,1);
        // int ans = 0;
        // for(auto &p : v){
        //     if(p >= x && p <=y) ans++;
        // }
        int ans = getAnswer(0,n-1,l-1,r-1,1,x,y);
        printf("%d\n", ans);
    }

    


}