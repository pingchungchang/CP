#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct node{
    node* pl;
    node* pr;
    ll l;
    ll r;
    ll val;
    ll tag;
    node(){
        pl = nullptr;
        pr = nullptr;
        tag = 0;
        val = 0;
        l = 0;
        r = 0;
    }
    node(ll a,ll b){
        l = a,r = b,val = 0,pr = nullptr,pl = nullptr;tag = 0;
    }
};

node* segtree = new node(0,(ll)1e6+10);

void upd(node* now,int t){
    if(now->pl == nullptr)return;
    if(now->tag>0){
        now->val = now->r-now->l+1;
        return;
    }
    ll x = min(now->pl->tag,now->pr->tag);
    now->tag += x;
    now->pl->tag -= x;
    now->pr->tag -= x;
    if(t == 0)upd(now->pl,1);
    if(t == 0)upd(now->pr,1);
    now->val = now->pl->val+now->pr->val;
}
void addval(node* now,ll s,ll e,ll val){
    //cout<<now->l<<' '<<now->r<<' '<<s<<' '<<e<<' '<<endl;
    ll mid = (now->l+now->r)/2;
    if(now->pl == nullptr)now->pl = new node(now->l,mid);
    if(now->pr == nullptr)now->pr = new node(mid+1,now->r);
    if(now->l == s&&now->r == e){
        if(now->tag+val >0){
            now->val = now->r-now->l+1;
            now->tag += val;
        }
        else{
            now->tag += val;
            now->val = now->pl->val+now->pr->val;
        }
        return;
    }
    now->pr->tag += now->tag;
    now->pl->tag += now->tag;
    now->tag =0;
    if(mid>=e)addval(now->pl,s,e,val);
    else if(mid+1<=s)addval(now->pr,s,e,val);
    else{
        addval(now->pl,s,mid,val);
        addval(now->pr,mid+1,e,val);
    }
    upd(now,0);
    return;
}
void pv(node* now){
    if(now == nullptr)return;
    cout<<now->l<<' '<<now->r<<' '<<now->val<<endl;
    pv(now->pr);
    pv(now->pl);
}
int main(){
    int n;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    vector<vector<ll>> req(n,vector<ll>(4));
    for(int i = 0;i<n;i++)for(int j = 0;j<4;j++)cin>>req[i][j];
    vector<vector<ll>> mvs;
    vector<ll> allx;
    for(int i = 0;i<n;i++){
        allx.push_back(req[i][2]);
        allx.push_back(req[i][3]);
        mvs.push_back({req[i][2],req[i][0],req[i][1]-1,1});
        mvs.push_back({req[i][3],req[i][0],req[i][1]-1,-1});
    }
    //LRDU
    sort(mvs.begin(),mvs.end());
    sort(allx.begin(),allx.end());
    for(auto &i:mvs){
        i[0] = lower_bound(allx.begin(),allx.end(),i[0])-allx.begin();
    }
    ll ans = 0;
    int p = 0;
    for(int i = 0;i<allx.size()-1;i++){
        while(p<mvs.size()&&mvs[p][0] == i){
            addval(segtree,mvs[p][1],mvs[p][2],mvs[p][3]);
            p++;
        }
        ans += segtree->val*(allx[i+1]-allx[i]);
        //cout<<ans<<endl;
    }
    //pv(segtree);
    cout<<ans;
}
