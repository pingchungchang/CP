#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> odd,even;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        if(i%2)odd.push_back(k);
        else even.push_back(k);
    }
    for(int i = 1;i<odd.size();i++){
        if((odd[i]-odd[i-1])%2 != 0){
            cout<<"NO\n";
            return;
        }
    }
    for(int i = 1;i<even.size();i++){
        if((even[i]-even[i-1])%2 != 0){
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
    for(int i = 0;i<t;i++)solve();
}
