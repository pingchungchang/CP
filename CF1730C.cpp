#include <bits/stdc++.h>
using namespace std;

void solve(){
    int lst = -1;
    int cnt[10] = {};
    string s;
    cin>>s;
    for(auto &i:s){
        cnt[i-'0']++;
    }
    int n = s.size();
    int more[10] = {};
    for(int i = 0;i<10;i++){
        for(int j = lst+1;j<n;j++){
            if(i == s[j]-'0'){
                more[i] ++;
                cnt[i]--;
                lst = j;
            }
        }
    }
    for(int i = 0;i<10;i++){
        while(more[i]--)cout<<i;
        while(cnt[i]--)cout<<min(i+1,9);
    }
    cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}