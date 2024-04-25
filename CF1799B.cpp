#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    vector<pair<int,int>> ans;
    if(*max_element(arr,arr+n) != 1&&*min_element(arr,arr+n) == 1){
        cout<<"-1\n";
        return;
    }
    while(*max_element(arr,arr+n) != *min_element(arr,arr+n)){
        auto p1 = max_element(arr,arr+n)-arr;
        auto p2 = min_element(arr,arr+n)-arr;
        ans.push_back({p1,p2});
        arr[p1] = (arr[p1]+arr[p2]-1)/arr[p2];
    }
    cout<<ans.size()<<'\n';
    for(auto &i:ans)cout<<i.first+1<<' '<<i.second+1<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}