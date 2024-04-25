#include <bits/stdc++.h>
using namespace std;

struct node{
    int l,r,id;
    int v1,v2;
    node(int a,int b,int c){
        l = a;
        r = b;
        id = c;
        v1 = 0;
        v2 = 0;
    }
    node(){
        v1 = 0;
        v2 = 0;
    }
};
vector<int>segtree;

int getval(int s,int e,int now,int l,int r){
    int mid = (l+r)/2;
    if(s == l&&e == r)return segtree[now];
    if(e<=mid)return getval(s,e,now*2+1,l,mid);
    else if(mid+1<=s)return getval(s,e,now*2+2,mid+1,r);
    else return getval(s,mid,now*2+1,l,mid)+getval(mid+1,e,now*2+2,mid+1,r);
}
void addval(int pos,int val,int now,int l,int r){
    if(l == r){
        segtree[now]+=val;
        return;
    }
    int mid = (l+r)/2;
    if(mid>=pos)addval(pos,val,now*2+1,l,mid);
    else addval(pos,val,now*2+2,mid+1,r);
    segtree[now] = segtree[now*2+1]+segtree[now*2+2];
    return;
}
bool lcmp(node a,node b){
    if(a.l != b.l)return a.l<b.l;
    else return a.r>b.r;
}
bool cmp2(node a,node b){
    if(a.l != b.l)return a.l<b.l;
    else return a.r>b.r;
}
bool idcmp(node a,node b){
    return a.id<b.id;
}
int main(){
    int n;
    cin>>n;
    vector<int> all;
    vector<node> v(n,node());
    for(int i= 0;i<n;i++){
        v[i].id = i;
        cin>>v[i].l>>v[i].r;
        all.push_back(v[i].l);
        all.push_back(v[i].r);
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    for(auto &i:v){
        i.l = lower_bound(all.begin(),all.end(),i.l)-all.begin();
        i.r = lower_bound(all.begin(),all.end(),i.r)-all.begin();
    }
    sort(v.begin(),v.end(),lcmp);
    segtree = vector<int>(all.size()*4,0);
    int m = all.size();
    for(auto& i:v){
        i.v1 = getval(i.r,m-1,0,0,m-1);
        //cout<<i.l<<' '<<i.r<<' '<<i.v1<<endl;
        addval(i.r,1,0,0,m-1);
    }
    segtree = vector<int>(m*4,0);
    sort(v.begin(),v.end(),cmp2);
    for(int i = n-1;i>=0;i--){
        node& now = v[i];
        now.v2 = getval(now.l,now.r,0,0,m-1);
        //cout<<now.l<<' '<<now.r<<' '<<getval(now.r,now.r,0,0,m-1)<<' '<<now.v2<<endl;
        //cout<<getval(2,4,0,0,m-1)<<' '<<getval(5,5,0,0,m-1)<<endl;
        addval(now.r,1,0,0,m-1);
    }
    sort(v.begin(),v.end(),idcmp);
    for(auto i:v)cout<<i.v2<<' ';
    cout<<'\n';
    for(auto i:v)cout<<i.v1<<' ';
}
