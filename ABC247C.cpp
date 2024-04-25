#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

void add(vector<int> &a,vector<int> b){
    for(int i = 0;i<b.size();i++)a.push_back(b[i]);
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int> now = {1};
    int n;
    cin>>n;
    for(int i = 2;i<=n;i++){
        vector<int> vv = now;
        add(now,{i});
        add(now,vv);
    }
    for(auto i:now)cout<<i<<' ';
}

