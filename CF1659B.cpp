#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    string s;
    cin>>n>>k>>s;
    int use = k;
    vector<int> v(n,0);
    for(int i = 0;i<n;i++){
        if(k%2 == 0&&s[i] == '1')continue;
        else if(k%2 == 1&&s[i] == '1'&&use != 0){
            use--;
            v[i] = 1;
        }
        else if(k%2 == 1&&s[i] == '0'){
            continue;
        }
        else if(use != 0){
            use--;
            v[i] = 1;
        }
    }
    //cout<<s<<endl<<use;return;
    v[n-1] += use;
    for(int i = 0;i<n;i++){
        if((k-v[i])%2 == 1){
            if(s[i] == '1')s[i] = '0';
            else s[i] = '1';
        }
    }
    cout<<s<<'\n';
    for(auto i:v)cout<<i<<' ';
    cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
