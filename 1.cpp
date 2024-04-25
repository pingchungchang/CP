#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> mp;
#define fs first
#define sc second
#define pii pair<int,int>
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    int x;
    cin>>n;
    cin>>x;
    int arr[n];
    for(auto &i:arr)cin>>i;
    vector<pair<int,int>> v;
    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(arr[i]+arr[j]>x)continue;
            v.push_back({arr[i]+arr[j],i});
        }
    }
    int p = 0;
    long long ans = 0;
    for(int i = 0;i<n;i++){
        while(p<v.size()&&v[p].second<i){
            mp[v[p].fs]++;
            p++;
        }
        for(int j = i+1;j<n;j++){
            ans += mp[x-arr[i]-arr[j]];
        }
    }
    cout<<ans;
}