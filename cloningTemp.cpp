#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mod 1000000007
#define vec vector<long long>
#define arl(n) array<long long,n>
#define ard(n) array<double,n>
#define sc(n) scanf("%lld",&n)
#define prn(n) printf("%lld\n",n)
#define prs(n) printf("%lld ",n)
#define pr() printf("\n")
#define pb push_back
#define mp make_pair
ll mxl;
ll segtree[100001];
void add(ll ind)
{
    for(;ind<=mxl;ind+=(ind&(-ind)))
    segtree[ind]++;
}
ll cal(ll ind)
{
    ll res=0;
    for(;ind>0;ind-=(ind&(-ind)))
    res+=segtree[ind];
    return res;
}
int main()
{
    ll t;
    sc(t);
    ll n,q,i;
    while(t--)
    {
        memset(segtree,0,sizeof(segtree));
        ll tp;
        sc(n),sc(q);
        vec vs(n+1),vs2(n+1),v(n+1),vs3(n+1);
        vector<vec> v1(n+1);
        vector<arl(6)> vq(q);
        vs[0]=0;
        vs2[0]=0;
        vs3[0]=0;
        mxl=0;
        for(i=1;i<=n;i++)
        {
            sc(v[i]);
            mxl = max(mxl,v[i]);
            vs[i] = v[i]+vs[i-1];
            vs2[i] = v[i]*v[i] + vs2[i-1];
            vs3[i] = v[i]*v[i]*v[i] + vs3[i-1];
            //cout<<vs[i]<<" "<<vs2[i]<<" "<<vs3[i]<<endl;
        }
        cout<<endl;
        ll tp1,tp2;
        map<arl(2),arl(2)> m;
        for(i=0;i<q;i++)
        {
            sc(vq[i][0]),sc(vq[i][1]),sc(vq[i][2]),sc(vq[i][3]);
            ll d1 = vs[vq[i][1]]-vs[vq[i][0]-1],d12 = vs2[vq[i][1]]-vs2[vq[i][0]-1],d13 = vs3[vq[i][1]]-vs3[vq[i][0]-1];
            ll d2 = vs[vq[i][3]]-vs[vq[i][2]-1],d22 = vs2[vq[i][3]]-vs2[vq[i][2]-1],d23 = vs3[vq[i][3]]-vs3[vq[i][2]-1];
            vq[i][4]=0;
            //cout<<d1<<" "<<d2<<" "<<d12<<" "<<d22<<" "<<d13<<" "<<d23<<endl;
            if(d1==d2 && d12==d22 && d13==d23)
            vq[i][4]=-1;
            else if(d1==d2 || d12==d22 || d13==d23)
            vq[i][4]=-2;
            else
            {
                ll cc=0;
                cc = cc+ (d1<d2?1:-1);
                cc = cc+ (d12<d22?1:-1);
                cc = cc+ (d13<d23?1:-1);
                if(cc!=3 && cc!=-3)
                vq[i][4]=-2;
                else
                {
                    if(cc==-3)
                    {
                        ll d = d1-d2,D = d12-d22,D1 = d13-d23;
                        if(D%d)
                        vq[i][4]=-2;
                        else
                        {
                            ll dd = D/d;
                            if((d+dd)%2)
                            vq[i][4]=-2;
                            else
                            {
                                tp1 = (d+dd)/2;
                                tp2 = tp1-d;
                                if(tp1<=tp2)
                                vq[i][4]=-2;
                            }
                            //cout<<tp1<<" "<<tp2<<endl;
                            if((tp1*tp1*tp1 - tp2*tp2*tp2)!=D1)
                            vq[i][4]=-2;
                        }
                    }
                    else
                    {
                        ll d = d2-d1,D = d22-d12,D1 = d23-d13;
                        if(D%d!=0)
                        vq[i][4]=-2;
                        else
                        {
                            ll dd = D/d;
                            if((d+dd)%2)
                            vq[i][4]=-2;
                            else
                            {
                                tp2 = (d+dd)/2;
                                tp1 = tp2-d;
                                if(tp2<=tp1)
                                vq[i][4]=-2;
                            }
                            //cout<<tp1<<" "<<tp2<<endl;
                            if((tp2*tp2*tp2 - tp1*tp1*tp1)!=D1)
                            vq[i][4]=-2;
                        }
                    }
                }
            }
            if(vq[i][4]==0)
            {
                //cout<<tp1<<" "<<tp2<<endl;
                if(tp1<1 || tp1>mxl || tp2<1 || tp2>mxl)
                vq[i][4]=-2;
                else
                {
                    vq[i][4]=tp1,vq[i][5]=tp2;
                    if(vq[i][0]>1)
                    v1[vq[i][0]-1].pb(tp1);
                    if(vq[i][2]>1)
                    v1[vq[i][2]-1].pb(tp2);
                    v1[vq[i][1]].pb(tp1),v1[vq[i][3]].pb(tp2);
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            add(v[i]);
            arl(2) b1,a1;
            b1[0]=i;//index first
            for(ll j=0;j<v1[i].size();j++)
            {
                b1[1] = v1[i][j]; 
                a1[0] = cal(b1[1]-1);
                a1[1] = cal(b1[1]);
                m[b1] = a1;
                //cout<<b1[0]<<" "<<b1[1]<<" "<<a1[0]<<" "<<a1[1]<<endl;
            }
        }
        for(i=0;i<q;i++)
        {
            if(vq[i][4]==-1)
            printf("YES\n");
            else if(vq[i][4]==-2)
            printf("NO\n");
            else
            {
                arl(2) a1,a2,d1,d2;
                if(vq[i][0]==1)
                d1 = m[{vq[i][1],vq[i][4]}];
                else
                {
                    a2 = m[{vq[i][1],vq[i][4]}];
                    a1 = m[{vq[i][0]-1,vq[i][4]}];
                    d1[0] = a2[0]-a1[0],d1[1]=a2[1]-a1[1];
                }
                if(vq[i][2]==1)
                d2 = m[{vq[i][3],vq[i][5]}];
                else
                {
                    a2 = m[{vq[i][3],vq[i][5]}];
                    a1 = m[{vq[i][2]-1,vq[i][5]}];
                    d2[0] = a2[0]-a1[0],d2[1]=a2[1]-a1[1];
                }
                if(d1[0]==d1[1] || d2[0]==d2[1])
                printf("NO\n");
                else
                {
                    if(vq[i][4]<vq[i][5])
                    {
                        if((d1[1]-1)!=d2[0])
                        printf("NO\n");
                        else
                        printf("YES\n");
                    }
                    else
                    {
                        if((d2[1]-1)!=d1[0])
                        printf("NO\n");
                        else
                        printf("YES\n");
                    }
                }
            }
        }
    }
    return 0;
} 