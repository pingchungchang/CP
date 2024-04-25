#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    int arr[100] = {};
    for(int i = 0;i<n;i++){
        int s,e;
        cin>>s>>e;
        if(s>k||e<k)continue;
        arr[s]++;
        arr[e+1]--;
    }
    for(int i = 1;i<100;i++)arr[i] += arr[i-1];
    for(int i = 1;i<100;i++){
        if(i == k)continue;
        if(arr[i] == arr[k]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}