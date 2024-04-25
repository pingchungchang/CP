#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i = 0;i<n;i++)cin>>v[i].first;
    for(int i = 0;i<n;i++)cin>>v[i].second;
    auto vv = v;
    sort(vv.begin(),vv.end());
    for(int i = 1;i<n;i++){
        if(vv[i].second<vv[i-1].second){
            cout<<-1<<'\n';
            return;
        }
    }
    vector<pair<int,int>> ans;
    for(int i = 0;i<n;i++){
        for(int j = 1;j<n;j++){
            if(v[j].first<v[j-1].first){
                ans.push_back(make_pair(j-1,j));
                swap(v[j],v[j-1]);
            }
            else if(v[j].first == v[j-1].first&&v[j].second<v[j-1].second){
                ans.push_back(make_pair(j-1,j));
                swap(v[j],v[j-1]);
            }
        }
    }
    cout<<ans.size()<<'\n';
    for(auto i:ans)cout<<i.first+1<<' '<<i.second+1<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
