#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    set<int> mex;
    map<int,int> used;
    for(int i = 0;i<=n;i++)mex.insert(i);
    int ans;
    for(int i = 0;i<m;i++){
        mex.erase(v[i]);
        used[v[i]]++;
    }
    ans = *mex.begin();
    for(int i = m;i<n;i++){
        used[v[i-m]]--;
        if(used[v[i-m]] == 0){
            used.erase(v[i-m]);
            mex.insert(v[i-m]);
        }
        used[v[i]]++;
        mex.erase(v[i]);
        ans = min(ans,*mex.begin());
    }
    cout<<ans;
}
