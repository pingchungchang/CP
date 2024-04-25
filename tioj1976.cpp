#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 4e5+10;
int ans = 0;
vector<int> all;
struct node{
    int pl,pr;
    int val;
};
node segtree[mxn*10];
int pt = 0;
int newnode(){
    pt++;
    segtree[pt].pl = segtree[pt].pr = segtree[pt].val = 0;
    return pt;
}
int pers[mxn],pre[mxn],suf[mxn];
pair<pii,int> arr[mxn];
void cpy(int ref,int now){
    segtree[now].pl = segtree[ref].pl;
    segtree[now].pr = segtree[ref].pr;
    segtree[now].val = segtree[ref].val;
    return;
}
void modify(int now,int l,int r,int p,int v,bool flag){
    if(l == r){
        segtree[now].val += v;
        return;
    }
    int mid = (l+r)>>1;
    if(mid>=p){
        if(flag){
            auto tmp = newnode();
            cpy(segtree[now].pl,tmp);
            segtree[now].pl = tmp;
        }
        modify(segtree[now].pl,l,mid,p,v,flag);
    }
    else{
        if(flag){
            auto tmp = newnode();
            cpy(segtree[now].pr,tmp);
            segtree[now].pr = tmp;
        }
        modify(segtree[now].pr,mid+1,r,p,v,flag);
    }
    segtree[now].val = segtree[segtree[now].pl].val+segtree[segtree[now].pr].val;
    return;
}

void build(int now,int l,int r){
    if(l == r)return;
    int mid = (l+r)>>1;
    segtree[now].pl = newnode();
    segtree[now].pr = newnode();
    build(segtree[now].pl,l,mid);
    build(segtree[now].pr,mid+1,r);
    return;
}
int getval(int now,int l,int r,int s,int e){
    if(l>=s&&e>=r)return segtree[now].val;
    int mid = (l+r)>>1;
    if(mid>=e)return getval(segtree[now].pl,l,mid,s,e);
    else if(mid<s)return getval(segtree[now].pr,mid+1,r,s,e);
    else return getval(segtree[now].pl,l,mid,s,e)+getval(segtree[now].pr,mid+1,r,s,e);
}

int calc(int a,int b){
    if(b<a)return -1e9;
    if(a == b){
        return pre[a];
    }
    return pre[a]+suf[b]+
    (b-a>1?getval(pers[b-1],0,all.size(),a+1,b-1)-getval(pers[a],0,all.size(),a+1,all.size()):-getval(pers[a],0,all.size(),b,all.size()));
}

void dc(int ql,int qr,int l,int r){
    if(l == r){
        for(int i = ql;i<=qr;i++){
            ans = max(ans,calc(r,i));
        }
        return;
    }
    int qmid = (ql+qr)>>1;
    pii p = {-1e9,0};
    for(int i = l,I = min(qmid,r);i<=I;i++){
        p = max(p,{calc(i,qmid),i});
    }
    ans = max(ans,p.first);
    if(ql == qr)return;
    if(ql<qmid)dc(ql,qmid-1,l,p.second);
    dc(qmid+1,qr,p.second,r);
}
void pv(int now,int l,int r){
    if(!now)return;
    cout<<l<<' '<<r<<":"<<segtree[now].val<<' '<<now<<endl;
    int mid = (l+r)>>1;
    pv(segtree[now].pl,l,mid);
    pv(segtree[now].pr,mid+1,r);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>arr[i].fs.fs>>arr[i].fs.sc>>arr[i].sc;
        all.push_back(arr[i].fs.fs);
        // all.push_back(arr[i].fs.sc);
        all.push_back(arr[i].fs.sc+1);
    }
    all.push_back(-2);
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    sort(arr+1,arr+n+1);
    pers[0] = newnode();
    build(pers[0],0,all.size());
    int last = 0;
    for(int i = 1;i<=n;i++){
        auto l = lower_bound(all.begin(),all.end(),arr[i].fs.fs)-all.begin();
        auto r = lower_bound(all.begin(),all.end(),arr[i].fs.sc)-all.begin();
        pre[l]+= arr[i].sc;
        pre[r+1] -= arr[i].sc;
        if(last == l)modify(pers[l],0,all.size(),r,arr[i].sc,1);
        else{
            while(last < l){
                last++;
                pers[last] = pers[last-1];
            }
            pers[l] = newnode();
            cpy(pers[l-1],pers[l]);
            modify(pers[l],0,all.size(),r,arr[i].sc,1);
        }
    }
    while(last < all.size()-1){
        last++;
        pers[last] = pers[last-1];
    }
    for(int i = 1;i<all.size();i++){
        pre[i] += pre[i-1];
        suf[i] = pre[i];
    }
    dc(1,all.size()-1,1,all.size()-1);
    cout<<ans;
    return 0;
}