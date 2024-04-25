#include <bits/stdc++.h>
using namespace std;

#define ll long long
int mxn = 1e5+5;
ll pw(ll a,ll b){
    ll ans = 1;
    while(b != 0){
        if((b&1) != 0)ans *= a;
        if(a>1e5||ans>1e5)return 0;
        a = a*a;
        b >>=1;
    }
    return ans;
}
int main(){
    int cnt[mxn] = {};
    ll ans = 0LL;
    int n,kk;
    cin>>n>>kk;
    ll sq = pow(mxn,1.0/kk)+1;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(auto i:arr){
        ll num = i;
        int k = sqrt(i);
        vector<pair<int,int>> v;
        for(int j = 2;j<=k;j++){
            if(i%j == 0){
                if(v.empty()||v.back().first != j)v.push_back(make_pair(j,1));
                else v.back().second++;
                i /=j;
                k = sqrt(i);
                j = 1;
            }
        }
        //cout<<i<<endl;
        if(i > 1){
            if(!v.empty()&&v.back().first == i)v.back().second++;
            else v.push_back(make_pair(i,1));
        }
        ll tmp = 1LL;
        //for(auto j:v)cout<<j.first<<' '<<j.second<<',';cout<<'\n';
        for(auto j:v){
            ll tt = pw(j.first,(j.second%kk == 0?0LL:kk-j.second%kk));
            tmp *= tt;
        }
        //cout<<tmp<<endl;
        for(ll j = 1;j<=sq;j++){
            ll now = tmp*pw(j,kk);
            if(now>=mxn){
                break;
            }
            ans += cnt[now];
        }
        cnt[num]++;
    }
    cout<<ans<<' ';
}
