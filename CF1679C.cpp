#include <bits/stdc++.h>
using namespace std;


struct node{
    int tag;
    int val;
    node(){
        tag = 0;
        val = 0;
    }
};
int n,q;
vector<vector<node>> segtree;
void changeval(int t,int pos,int v,int now,int l,int r){
    if(l == r){
        segtree[t][now].val+= v;
        if(segtree[t][now].val>0)segtree[t][now].tag = 1;
        else segtree[t][now].tag = 0;
        return;
    }
    int mid = (l+r)/2;
    if(mid>=pos)changeval(t,pos,v,now*2+1,l,mid);
    else changeval(t,pos,v,now*2+2,mid+1,r);
    segtree[t][now].tag = segtree[t][now*2+1].tag+segtree[t][now*2+2].tag;
    return;
}
int getval(int t,int s,int e,int now,int l,int r){
    if(s<=l&&e>=r)return segtree[t][now].tag;
    int mid = (l+r)/2;
    if(mid>=e)return getval(t,s,e,now*2+1,l,mid);
    else if(mid<s)return getval(t,s,e,now*2+2,mid+1,r);
    else return getval(t,s,e,now*2+1,l,mid)+getval(t,s,e,now*2+2,mid+1,r);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    segtree = vector<vector<node>>(2,vector<node>((n+1)*4,node()));
    for(int i = 0;i<q;i++){
        int t;
        cin>>t;
        if(t == 1){
            int r,c;
            cin>>r>>c;
            changeval(0,r,1,0,1,n);
            changeval(1,c,1,0,1,n);
        }
        else if(t == 2){
            int r,c;
            cin>>r>>c;
            changeval(0,r,-1,0,1,n);
            changeval(1,c,-1,0,1,n);
        }
        else{
            int r1,r2,c2,c1;
            cin>>r1>>c1>>r2>>c2;
            if(getval(0,r1,r2,0,1,n) == r2-r1+1||getval(1,c1,c2,0,1,n) == c2-c1+1){
                cout<<"Yes\n";
            }
            else cout<<"No\n";
        }
        //for(int j = 1;j<=n;j++)cout<<getval(0,j,j,0,1,n)<<' ';cout<<'\n';
        //for(int j = 1;j<=n;j++)cout<<getval(1,j,j,0,1,n)<<' ';cout<<'\n';
    }
}
