#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxn = 'k'-'a'+1;
void solve(){
    int n;
    cin>>n;
    ll ans = 0;
    int fs[mxn] = {};
    int sc[mxn] = {};
    int arr[mxn][mxn] = {};
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        int a= s[0]-'a';
        int b= s[1]-'a';
        ans += fs[a];
        ans  += sc[b];
        ans -= arr[a][b];
        ans -= arr[a][b];
        fs[a]++;
        sc[b]++;
        arr[a][b]++;
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
