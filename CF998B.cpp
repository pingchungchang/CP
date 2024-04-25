#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    vector<int> v(n);
    for(int i = 0;i<n;i++)cin>>arr[i];
    if(arr[0]%2 == 0)v[0] = -1;
    else v[0] = 1;
    for(int i = 1;i<n;i++){
        v[i] = v[i-1];
        if(arr[i]%2 == 0)v[i]--;
        else v[i]++;
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0;i<n-1;i++){
        if(v[i] == 0)pq.push(abs(arr[i+1]-arr[i]));
    }
    int ans= 0;
    while(!pq.empty()&&pq.top()<=k){
        k -= pq.top();
        ans++;
        pq.pop();
    }
    cout<<ans;
}

