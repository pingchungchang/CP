#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int cnt[n] = {};
    for(auto &i:arr)cin>>i;
    for(int i = 0;i<n;i++){
        int tmp = arr[i];
        while(tmp>0&&!((tmp^arr[i])&1)){
            cnt[i]++;
            tmp>>=1;
        }
        if(!((tmp^arr[i])&1))cnt[i] = 1e9;
    }
    int total = 0;
    for(auto &i:arr)total +=i;
    if(total&1){
        cout<<*min_element(cnt,cnt+n)<<'\n';
        return;
    }
    else cout<<"0\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}