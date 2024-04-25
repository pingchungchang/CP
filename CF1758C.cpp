#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    int n,x;
    cin>>n>>x;
    int ans[n+1] = {};
    for(int i = 1;i<=n;i++)ans[i] = i;
    swap(ans[1],ans[n]);
    if(x == n){
        for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<'\n';
        return;
    }
    swap(ans[x],ans[1]);
    bool flag = false;
    for(int i = x+1;i<n;i++){
        if(i%x == 0&&n%i == 0){
            swap(ans[x],ans[i]);
            flag = true;
            x = i;
        }
    }
    if(n%x == 0)flag = true;
    if(!flag){
        cout<<"-1\n";
        return;
    }
    for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}