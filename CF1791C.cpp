#include <bits/stdc++.h>
using namespace std;

void solve(){
    deque<int> dq;
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i = 0;i<n;i++){
        dq.push_back(s[i]-'0');
    }
    while(!dq.empty()&&dq.back() != dq.front()){
        dq.pop_back();
        dq.pop_front();
    }
    cout<<dq.size()<<'\n';
    return;
}
int main(){
    int t;
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin>>t;
    while(t--)solve();
}