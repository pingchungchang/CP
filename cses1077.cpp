#include <bits/stdc++.h>
using namespace std;

#define ll long long


int n,k;
vector<ll> v;
struct node{
    node* pl;
    node* pr;
    ll l,r;
    ll sum;
    ll val;
    node(){
        pl = nullptr,pr = nullptr;
    }
    node(ll a,ll b){
        pl = nullptr;
        pr = nullptr;
        l = a,r = b;
        sum = 0LL,val = 0LL;
    }
};
void addval(node* now,ll pos,ll asum,ll aval){
    if(now->l == now->r){
        now->val+=aval;
        now->sum += asum;
        return;
    }
    ll mid = (now->l+now->r)/2;
    if(now->pl == nullptr){
        now->pl = new node(now->l,mid);
    }
    if(now->pr == nullptr){
        now->pr = new node(mid+1,now->r);
    }
    if(mid>=pos){
        addval(now->pl,pos,asum,aval);
    }
    else addval(now->pr,pos,asum,aval);
    now->val = now->pl->val+now->pr->val;
    now->sum = now->pl->sum+now->pr->sum;
    return;
}
ll getval(node* now,ll tar){
    if(now->l == now->r)return now->l;
    if(now->pl->val>=tar)return getval(now->pl,tar);
    else return getval(now->pr,tar-now->pl->val);
}
ll gettotall(node* now,ll tar){
    if(now->l == now->r)return now->l*tar;
    if(now->val<=tar)return now->sum;
    if(now->pl->val>=tar)return gettotall(now->pl,tar);
    else{
        return now->pl->sum+gettotall(now->pr,tar-now->pl->val);
    }
}
ll gettotalr(node* now,ll tar){
    if(now->r == now->l){
        return now->l*tar;
    }
    if(now->val<=tar)return now->sum;
    if(now->pr->val>=tar)return gettotalr(now->pr,tar);
    else return now->pr->sum+gettotalr(now->pl,tar-now->pr->val);
}
node* segtree = new node((ll)0,(ll)1e9);
ll getans(ll x){
    return gettotalr(segtree,k/2)-gettotall(segtree,k/2);
}
int main(){
    cin>>n>>k;
    v = vector<ll>(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    for(int i = 0;i<k;i++){
        addval(segtree,v[i],v[i],1LL);
    }
    ll mid = getval(segtree,(k+1)/2);
    vector<ll>ans;
    ans.push_back(getans(mid));
    for(int i = k;i<n;i++){
        ll out = v[i-k],in = v[i];
        addval(segtree,out,-out,-1LL);
        addval(segtree,in,in,1LL);
        mid = getval(segtree,(k+1)/2);
        if(k%2 != 0)addval(segtree,mid,-mid,-1LL);
        ans.push_back(getans(mid));
        if(k%2 != 0)addval(segtree,mid,mid,1LL);
        //cout<<mid<<endl;
    }
    for(auto i:ans)cout<<i<<' ';
    return 0;
}
