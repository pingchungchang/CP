#include <bits/stdc++.h>
using namespace std;

bool eq(set<int> &a,set<int> &b){
    for(auto &i:a)if(b.find(i) == b.end())return false;
    return true;
}
void solve(){
    int m;
    cin>>m;
    set<int> st[m+1];
    for(int i = 0;i<m;i++){
        int k;
        cin>>k;
        while(k--){
            int x;
            cin>>x;
            st[i].insert(x);
       }
    }
    int ans[m] = {};
    int p = 5e4;
    map<int,int> last;
    for(int i = 0;i<m;i++){
        for(auto &j:st[i]){
            last[j] = i;
        }
    }
    for(auto &i:last){
        ans[i.second] = i.first;
    }
    for(int i = 0;i<m;i++){
        if(!ans[i]){
            cout<<-1<<'\n';
            return;
        }
    }
    for(int i = 0;i<m;i++)cout<<ans[i]<<' ';cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}