#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> v(n+1);
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        v[k].push_back(i);
    }
    int q;
    cin>>q;
    for(int i = 0;i<q;i++){
        int l,r,val;
        cin>>l>>r>>val;
        l--,r--;
        int pl = lower_bound(v[val].begin(),v[val].end(),l)-v[val].begin();
        int pr = upper_bound(v[val].begin(),v[val].end(),r)-v[val].begin();
        cout<<pr-pl<<'\n';
    }
}
