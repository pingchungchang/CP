#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    map<int,int> mp;
    while(n--){
        int k;
        cin>>k;
        mp[k]++;
    }
    if(mp.size() == 1)cout<<"NO\n";
    else{
        cout<<"YES\n";
        cout<<mp.rbegin()->first<<' ';mp.rbegin()->second--;
        for(auto &i:mp){
            while(i.second){
                i.second--;
                cout<<i.first<<' ';
            }
        }
        cout<<'\n';
    }
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}