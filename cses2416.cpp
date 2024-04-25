#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Q{
    ll l, r, id;
    ll val;
    Q(){
        val = 0;
    }
};
ll bit[(ll)1e5*2+10];
ll n,q;
void modify(ll pos,ll v){
    for(;pos<=n;pos += (pos&-pos))bit[pos]+= v;
    return;
}
ll getval(ll s,ll e){
    ll r = 0;
    for(;e>0;e-= e&-e)r += bit[e];
    s--;
    ll l = 0;
    for(;s>0;s -= s&-s)l += bit[s];
    return r-l;
}
bool cmp(Q a,Q b){
    if(a.l != b.l)return a.l<b.l;
    else return a.r<b.r;
}
bool idcmp(Q a,Q b){
    return a.id<b.id;
}
ll pref[(ll)1e5*2+10];
ll total(ll s,ll e){
    return pref[e]-pref[s-1];
}
int main(){
    cin>>n>>q;
    vector<Q> req(q,Q());
    vector<ll> arr(n+2,INT_MAX);
    pref[0] = 0;
    for(ll i = 1;i<=n;i++){
        cin>>arr[i];
        pref[i] = arr[i]+pref[i-1];
    }
    for(ll i = 0;i<q;i++){
        req[i].id= i;
        cin>>req[i].l>>req[i].r;
    }
    sort(req.begin(),req.end(),cmp);
    vector<ll> dp(n+2,0LL);
    deque<ll> st;
    st.push_front(n+1);
    ll p = q-1;
    for(ll i = n;i>=1;i--){
        while(arr[st.front()]<=arr[i]){
            modify(st.front(),-dp[st.front()]);
            st.pop_front();
        }
        dp[i] = arr[i]*(st.front()-i);
        modify(i,arr[i]*(st.front()-i));
        st.push_front(i);
        //for(auto it:st)cout<<it<<' ';
        //cout<<endl;
        while(p>=0&&req[p].l == i){
            ll pos = upper_bound(st.begin(),st.end(),req[p].r)-st.begin()-1;
            ll sum = getval(i,st[pos]-1)+(req[p].r-st[pos]+1)*arr[st[pos]];
            //cout<<req[p].l<<' '<<req[p].r<<' '<<sum<<endl;
            req[p].val = sum-total(req[p].l,req[p].r);
            p--;
        }
    }
    sort(req.begin(),req.end(),idcmp);
    for(auto i:req){
        cout<<i.val<<'\n';
    }
    return 0;
}
