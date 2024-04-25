#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    n = s.size();
    if(n <=2){
        if(k>=1)cout<<min(10*(s[0]-'0')+s[1]-'0',10*(s[1]-'0')+s[0]-'0')<<'\n';
        else cout<<stoi(s)<<'\n';
        return;
    }
    int tofront = INT_MAX,toback = INT_MAX;
    for(int i = 0;i<n;i++){
        if(s[i] == '1'){
            tofront = min(tofront,i);
            toback = min(toback,n-i-1);
        }
    }
    if(toback<=k){
        k -= toback;
        s[n-1-toback] = '0';
        s.back()= '1';
    }
    if(tofront<=k&&s[tofront] == '1'&&tofront != n-1){
        k -= tofront;
        s[tofront] = '0';
        s[0] = '1';
    }
    int ans = 0;
    for(int i = 0;i<n-1;i++){
        ans += 10*(s[i]-'0')+s[i+1]-'0';
    }
    //cout<<tofront<<' '<<toback<<' '<<s<<'\n';
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
