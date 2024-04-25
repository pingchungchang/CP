#include <bits/stdc++.h>
using namespace std;
void solve(){
    map<int,int> mp;
    int n;
    cin>>n;
    for(int i =0 ;i<n;i++){
        int k;
        cin>>k;
        if(!mp.count(k))mp[k] = 1;
        else mp[k]++;
    }
    for(auto it:mp){
        if(it.second>=3){
            cout<<it.first<<'\n';
            return;
        }
    }
    cout<<-1<<'\n';
    return;

}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
