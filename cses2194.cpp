#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#pragma GCC optimize("O3,unroll-loops")
const ll inf = 1e18;
ll dist(pll a,pll b){
    return (a.fs-b.fs)*(a.fs-b.fs)+(a.sc-b.sc)*(a.sc-b.sc);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    pll arr[n];
    set<pll> st;
    for(auto &i:arr){
        cin>>i.fs>>i.sc;
    }
    sort(arr,arr+n);
    int p = 0;
    ll ans = 8e18;
    ll d = sqrt(ans);
    if(d*d != ans)d++;
    for(int i= 0;i<n;i++){
        while(p<i&&(arr[i].fs-arr[p].fs)*(arr[i].fs-arr[p].fs)>=ans){
            st.erase({arr[p].sc,arr[p].fs});
            p++;
        }
        auto pl = st.lower_bound({arr[i].sc-d,-inf});
        auto pr = st.upper_bound({arr[i].sc+d+1,0});
        for(auto it = pl;it != pr;it++){
            ans = min(ans,dist({it->sc,it->fs},arr[i]));
        }
        st.insert({arr[i].sc,arr[i].fs});
        d = sqrt(ans);
        if(d*d != ans)d++;
    }
    cout<<ans;
}
