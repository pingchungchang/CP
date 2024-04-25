#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    set<int> heads;
    heads.insert(0);
    int arr[n];
    for(auto &i:arr)cin>>i;
    int now = 1;
    int cnt = 0;
    for(auto &i:arr){
        if(now == i){
            now++;
            cnt++;
        }
    }
    int total = n-cnt;
    cout<<(total+k-1)/k<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}