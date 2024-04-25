#include <bits/stdc++.h>
using namespace std;

int calc(int k){
    string s = to_string(k);
    return *max_element(s.begin(),s.end())-*min_element(s.begin(),s.end());
}
void solve(){
    int l,r;
    cin>>l>>r;
    pair<int,int> ans = {calc(l),l};
    for(int i = l;i<=r;i++){
        ans = max(ans,make_pair(calc(i),i));
        if(ans.first == 9)break;
    }
    cout<<ans.second<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}