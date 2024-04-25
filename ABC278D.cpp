#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define ll long long
#define fs first
#define sc second
set<pll> st;
set<pll>::iterator split(int p){
    auto it = st.lower_bound({p,1LL*INT_MIN});
    if(it != st.end()&&it->fs == p)return it;
    it--;
    ll l = it->fs,val = it->sc;
    st.erase(it);
    st.insert({l,val});
    return st.insert({p,val}).fs;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        int k;
        cin>>k;
        st.insert({i,k});
    }
    int q;cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            ll k;
            cin>>k;
            st.clear();
            st.insert({1,k});
        }
        else if(t == 2){
            ll p,v;
            cin>>p>>v;
            split(p+1);
            auto it = split(p);
            ll val = v+it->sc;
            st.erase(it);
            st.insert({p,val});
        }
        else{
            int p;
            cin>>p;
            auto it = split(p);
            cout<<it->sc<<'\n';
        }
    }
    return 0;

}