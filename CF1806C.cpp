#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int x = 4;

void dfs(){
    if(v.size() == x){
        for(int i = 0;i<(1<<x);i++){
            if(__builtin_popcount(i) != x/2)continue;
            int p = 1,s = 0;
            for(int j= 0;j<x;j++){
                if((1<<j)&i)p *= v[j];
                else s += v[j];
            }
            if(s != p)return;
        }
        for(auto &i:v)cout<<i<<' ';cout<<endl;
        return;
    }
    for(int i = (v.empty()?-x:v.back());i<=x;i++){
        v.push_back(i);
        dfs();
        v.pop_back();
    }
    return;
}
void solve(){
    int n;
    cin>>n;
    int arr[n*2];
    for(auto &i:arr)cin>>i;
    if(n == 1){
        cout<<abs(arr[0]-arr[1])<<'\n';
        return;
    }
    long long ans = 1e18;
    long long tmp = 0;
    for(auto &i:arr)tmp += abs(i);
    ans = tmp;
    if(!(n&1)){
        long long total = 0;
        for(auto &i:arr)total += abs(-1-i);
        for(auto &i:arr)ans = min(ans,total-abs(-1-i)+abs(n-i));
    }
    if(n == 2){
        tmp = 0;
        for(auto &i:arr)tmp += abs(i-2);
        ans = min(ans,tmp);
    }
    cout<<ans<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}