#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 3e5+10;
int bit[mxn];
void modify(int p,int v){
    for(;p<mxn;p+= p&-p)bit[p] +=v;
    return;
}
int getval(int p){
    int re = 0;
    for(;p>0;p-= p&-p)re += bit[p];
    return re;
}
void solve(){
    int n;
    cin>>n;
    fill(bit,bit+n+10,0);
    int arr[n];
    string ans(n+1,'0');
    multiset<int> st;
    for(auto &i:arr){
        cin>>i;
    }
    deque<pii> dq;
    dq.push_back({0,-1});
    int len[n] = {};
    for(int i = 0;i<n;i++){
        while(dq.back().fs>=arr[i])dq.pop_back();
        len[i] = i-dq.back().sc;
        dq.push_back({arr[i],i});
    }
    dq.clear();
    dq.push_back({0,n});
    for(int i = n-1;i>=0;i--){
        while(dq.back().fs>=arr[i])dq.pop_back();
        len[i] += dq.back().sc-i;
        len[i]--;
        dq.push_back({arr[i],i});
    }
    int vals[n+1] = {};
    for(int i = 0;i<n;i++){
        int p = arr[i],v = len[i];
        vals[p] = max(vals[p],v);
    }
    vector<pii> vv;
    for(int i = 1;i<=n;i++)vv.push_back({vals[i],i});
    sort(vv.rbegin(),vv.rend());

}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}