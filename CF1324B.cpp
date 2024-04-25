#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
void solve(){
    int n;
    cin>>n;
    int arr[n];
    pair<int,int> ap[n+1];
    for(auto &i:ap){
        i.first = n,i.second = -1;
    }
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        ap[arr[i]].fs = min(ap[arr[i]].fs,i);
        ap[arr[i]].sc = max(ap[arr[i]].sc,i);
    }
    for(auto &i:ap){
        if(i.second-i.first>=2){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}