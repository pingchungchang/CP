#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    string s;
    cin>>n>>k>>s;
    n = s.size();
    int cnt = 0;
    for(auto &i:s)if(i == 'X')cnt++;
    if(k>cnt){
        k = n-k;
        for(auto &i:s){
            if(i == 'Y')i = 'X';
            else i = 'Y';
        }
    }
    cnt = 0;
    for(auto &i:s)if(i == 'X')cnt++;
    if(cnt == n){
        cout<<max(k-1,0);
        return 0;
    }
    int len = 0;
    int ans = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    bool flag = false;
    for(int i = 0;i<n;i++){
        if(i != 0&&s[i-1] == s[i]&&s[i] == 'Y')ans++;
        if(s[i] == 'Y'){
            if(flag == false)flag = true;
            else if(len>0)pq.push(len);
            len = 0;
        }
        else{
            len++;
        }
    }
    while(!pq.empty()&&pq.top()<=k){
        k -= pq.top();
        ans += pq.top()+1;
        pq.pop();
    }
    cout<<ans+k;
}
/*
10 10
XYXXYYXYXY

*/