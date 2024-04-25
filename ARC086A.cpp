#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1,0);
    for(int i = 0;i<n;i++){
        int a;
        cin>>a;
        v[a]++;
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0;i<=n;i++){
        if(v[i] != 0)pq.push(v[i]);
    }
    int ans = 0;
    while(pq.size() > k){
        ans += pq.top();
        pq.pop();
    }
    cout<<ans;
}
