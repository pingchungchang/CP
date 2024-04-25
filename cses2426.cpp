#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 2e5+10;
pll arr[mxn];
priority_queue<ll,vector<ll>,greater<ll>> lpq;
multiset<ll> st1,st2;
ll lsum,rsum;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,a,b;
    cin>>a>>b>>n;
    for(int i = 1;i<=n;i++)cin>>arr[i].fs>>arr[i].sc;
    sort(arr+1,arr+n+1);
    for(int i = n;i>n-a;i--){
        lsum += arr[i].fs;
        lpq.push(arr[i].fs-arr[i].sc);
    }
    for(int i = n-a;i>=1;i--){
        st1.insert(arr[i].sc);
    }
    for(int i = 0;i<b;i++){
        st2.insert(*st1.rbegin());
        rsum += *st1.rbegin();
        st1.erase(st1.find(*st1.rbegin()));
    }
    ll ans = lsum+rsum;
    for(int i = n-a;i>n-(a+b);i--){
        if(st1.find(arr[i].sc) != st1.end())st1.erase(st1.find(arr[i].sc));
        else{
            rsum -= arr[i].sc;
            st2.erase(st2.find(arr[i].sc));
        }
        // cout<<i<<":";for(auto &i:st2)cout<<i<<',';cout<<endl;
        lsum += arr[i].fs;
        lpq.push(arr[i].fs-arr[i].sc);
        while(lpq.size()>a){
            lsum -= lpq.top();
            lpq.pop();
        }
        ll rest = n-i+1-a;
        rest = min(rest,b);
        while(st2.size()>b-rest){
            st1.insert(*st2.begin());
            rsum -= *st2.begin();
            st2.erase(st2.find(*st2.begin()));
        }
        ans = max(ans,lsum+rsum);
    }
    cout<<ans;
}