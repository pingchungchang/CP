#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int arr[n+1] = {};
    bool called[n+1] = {};
    for(int i = 1;i<=n;i++)cin>>arr[i];
    for(int i = 1;i<=n;i++){
        if(!called[i]){
            called[arr[i]] = true;
        }
    }
    vector<int> v;
    for(int i = 1;i<=n;i++){
        if(!called[i])v.push_back(i);
    }
    cout<<v.size()<<'\n';
    for(auto &i:v)cout<<i<<' ';return 0;
}