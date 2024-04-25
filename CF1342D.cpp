#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> all;
vector<int> res;
vector<vector<int>> ans;

bool f(int now){
    ans.clear();
    ans = vector<vector<int>>(now);
    for(int i = 0;i<n;i++){
        ans[i%now].push_back(all[i]);
    }
    for(auto tmp:ans){
        int cnt = 0;
        for(int j = tmp.size()-1;j>=0;j--){
            int ii = tmp[j];
            cnt++;
            if(res[ii]<cnt)return false;
        }
    }
    return true;
}
int main(){
    cin>>n>>k;
    all = vector<int>(n);
    for(int i = 0;i<n;i++)cin>>all[i];
    res = vector<int>(k+1);
    sort(all.begin(),all.end());
    for(int i = 1;i<=k;i++)cin>>res[i];
    int l = 1,r = n;
    while(l != r){
        int mid = (l+r)/2;
        //cout<<l<<' '<<r<<' '<<f(mid)<<endl;
        if(f(mid))r = mid;
        else l = mid+1;
    }
    f(l);
    cout<<l<<'\n';
    for(auto tmp:ans){
        cout<<tmp.size()<<' ';
        for(auto j:tmp)cout<<j<<' ';
        cout<<'\n';
    }
}
