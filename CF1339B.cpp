#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    deque<int>dq;
    for(auto i:arr)dq.push_back(i);
    vector<int> ans;
    int now = 0;
    while(!dq.empty()){
        if(now){
            ans.push_back(dq.front());
            dq.pop_front();
        }
        else{
            ans.push_back(dq.back());
            dq.pop_back();
        }
        now^=1;
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans)cout<<i<<' ';
    cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
