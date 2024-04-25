#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    bool in[n+1] = {};
    for(auto &i:in)i = true;
    int cnt[n+1] = {};
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int k;
            cin>>k;
            cnt[k]++;
        }
        else if(t == 2){
            int k;
            cin>>k;
            in[k] = false;
        }
        else{
            int k;
            cin>>k;
            if(cnt[k]>=2)in[k] = false;
            if(in[k]){
                cout<<"No\n";
            }
            else cout<<"Yes\n";
        }
    }
    return 0;
}