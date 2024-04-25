#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
const ll mxn = 2e5+10;
ll bit[mxn];
void modify(int p,int v){
    for(;p<mxn;p+= p&-p)bit[p] += v;
    return;
}
ll getval(int k){
    ll re = 0;
    for(;k>0;k-=k&-k)re += bit[k];
    return re;
}
void solve(){
    ll n,c;
    cin>>n>>c;
    ll arr[n+1];
    for(int i = 1;i<=n;i++)cin>>arr[i];
    set<pair<pll,int>> st;
    for(int i = 1;i<=n;i++){
        if(i>n-i+1)st.insert({{n-i+1+arr[i],1},i});
        else st.insert({{i+arr[i],0},i});
    }
    ll ans = 0;
    int cc = c;
    bool flag = false;
    for(auto &i:st){
        if(i.fs.fs>cc)break;
        cc -= i.fs.fs;
        ans++;
        if(!i.fs.sc)flag = true;
    }
    if(flag){
//    	cout<<"HI"<<endl;
        cout<<ans<<'\n';
        return;
    }
    ans = 0;
    fill(bit,bit+n+1,0);
    int pos[n+1];
    pll vals[n+1];
    int p = 1;
    for(auto &i:st){
        pos[i.sc] = p++;
        vals[i.sc].fs = arr[i.sc] + max((ll)i.sc,n+1-i.sc);
        vals[i.sc].sc = arr[i.sc]+min((ll)i.sc,n+1-i.sc);
        modify(pos[i.sc],i.fs.fs);
    }
//    for(int i = 1;i<=n;i++)cout<<pos[i]<<' ';cout<<endl;
    for(int i = 1;i<=n;i++){
    	int tar = c-arr[i]-i;
        if(tar<0)continue;
        int l = 0,r = n;
        modify(pos[i],-vals[i].sc);
        while(l != r){
            int mid = (l+r+1)>>1;
            if(getval(mid)<=tar)l = mid;
            else r = mid-1;
        }
        if(getval(l)>tar)l--;
        if(l>=pos[i])ans = max(ans,(ll)l);
        else ans =max(ans,(ll)l+1);
//        cout<<i<<":"<<pos[i]<<' '<<tar<<' '<<l<<endl;for(int i = 1;i<=n;i++)cout<<getval(i)<<' ';cout<<endl;
        modify(pos[i],vals[i].sc);
        
        
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
