#include <bits/stdc++.h>
using namespace std;

const int mxn = 1024;
int segtree[mxn*4][mxn*4];

void modify2(int now,int now2,int l,int r,int rr,int c,int v){
    if(l == r){
        segtree[now][now2] = v;
        return;
    }
    int mid = (l+r)>>1;
    if(mid>=c)modify2(now,now2*2+1,l,mid,rr,c,v);
    else modify2(now,now2*2+2,mid+1,r,rr,c,v);
    segtree[now][now2] = max(segtree[now][now2*2+1],segtree[now][now2*2+2]);
    return;
}
void modify1(int now,int l,int r,int rr,int c,int v){
    if(l == r){
        modify2(now,0,0,mxn,rr,c,v);
    }
    int mid = (l+r)>>1;
    if(mid>=rr)modify(now*2+1,l,mid,rr,c,v);
    else modify(now*2=2,mid+1,r,rr,c,v);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int h,w,h1,h2,w1,w2;
    cin>>h>>w>>h1>>w1>>h2>>w2;
}