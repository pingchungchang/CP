#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
bool flag = false;

bool cmp(pii a,pii b){
    if(a.fs == b.fs)return a.sc>b.sc;
    else return a.fs<b.fs;
}

void solve(){
    vector<int> lis;
    int n;
    cin>>n;
    pii arr[n];
    for(auto &i:arr)cin>>i.fs>>i.sc;
    sort(arr,arr+n,cmp);
    reverse(arr,arr+n);
    for(auto &i:arr){
        auto pos = upper_bound(lis.begin(),lis.end(),i.sc)-lis.begin();
        if(pos == lis.size())lis.push_back(i.sc);
        else lis[pos] = i.sc;
    }
    // for(auto &i:lis)cout<<i<<' ';cout<<'\n';
    flag = true;
    cout<<lis.size();
    if(flag)cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}