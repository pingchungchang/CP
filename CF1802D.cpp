#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
void solve(){
    int n;
    cin>>n;
    multiset<int> st2;
    set<int> st1;
    pii arr[n];
    for(auto &i:arr)cin>>i.fs>>i.sc;
    sort(arr,arr+n);
    for(int i = 0;i<n;i++){
        st2.insert(arr[i].sc);
    }
    // st2.insert(0);
    int ans = 1e9+10;
    for(auto &i:arr){
        st2.erase(st2.find(i.sc));
        int big;
        if(st2.empty())big = 0;
        else big = *st2.rbegin();
        if(big>i.fs){
            ans = min(ans,big-i.fs);
        }
        else{
            auto it = st1.upper_bound(i.fs);
            if(it != st1.begin())ans = min(ans,abs(*prev(it)-i.fs));
            if(!st2.empty())ans = min(ans,abs(i.fs-big));
            if(it != st1.end())ans = min(ans,abs(*it-i.fs));
        }
        st1.insert(i.sc);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}