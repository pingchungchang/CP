#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    if(n == 1){
        cout<<-1<<'\n';
        return;
    }
    vector<int> ans(n);
    for(int i = 0;i<n;i++){
        ans[i] = i+1;
    }
    for(int i = 1;i<n;i++){
        if(v[i-1] == v[i])swap(ans[i],ans[i-1]);
    }
    for(int i = 0;i<n;i++){
        if(ans[i] == i+1){
            cout<<-1<<'\n';
            return;
        }
    }
    for(auto i:ans)cout<<i<<' ';cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
