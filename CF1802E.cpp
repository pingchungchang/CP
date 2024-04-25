#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 2e5+10;
int bit[mxn];
vector<pii> st;

void modify(int p,int v){
    for(;p<mxn;p+=p&-p)bit[p] = v;
    return;
}
int getval(int p){
    int re = 0;
    for(;p>0;p-= p&-p)re = max(re,bit[p]);
    return re;
}
bool cmp(vector<int>&a,vector<int> &b){
    return a.back()<b.back();
}
void solve(){
    int n;
    cin>>n;
    vector<int> v[n];
    for(auto &i:v){
        int k;
        cin>>k;
        while(k--){
            int x;
            cin>>x;
            if(i.empty()||i.back()<x)i.push_back(x);
        }
    }
    sort(v,v+n,cmp);
    // for(auto &i:v){
    //     for(auto &j:i)cout<<j<<',';cout<<'\n';
    // }
    int ans = 0;
    for(auto &i:v){
        int pre = 0;
        for(int j = 0;j<i.size();j++){
            int tmp = 1+max(getval(i[j]-1),pre);
            pre = tmp;
            // cout<<j<<":"<<tmp<<'\n';
            modify(i.back(),max(getval(i.back()),tmp));
            ans = max(ans,tmp);
        }
    }
    cout<<ans<<'\n';
    for(auto &i:v){
        modify(i[0],0);
        modify(i.back(),0);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}