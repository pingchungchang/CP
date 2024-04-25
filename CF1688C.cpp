#include <bits/stdc++.h>
using namespace std;

vector<string> v;

void solve(){
    int n;
    cin>>n;
    string e;
    v = vector<string>(n*2);
    for(int i = 0;i<n*2;i++)cin>>v[i];
    cin>>e;
    vector<int> cnt(27,0);
    for(auto i:v){
        for(auto j:i){
            cnt[j-'a']++;
        }
    }
    for(auto i:e)cnt[i-'a']++;
    for(int i = 0;i<26;i++){
        if(cnt[i]%2 == 1){
            cout<<(char)('a'+i)<<'\n';
            return;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
