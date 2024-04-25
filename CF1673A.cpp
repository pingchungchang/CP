#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    string s;
    cin>>s;
    ll ans = 0;
    if(s.size()%2 == 0){
        for(auto i:s)ans += i-'a'+1;
        cout<<"Alice "<<ans<<'\n';
        return;
    }
    else{
        if(s.size()== 1){
            cout<<"Bob "<<s[0]-'a'+1<<'\n';
            return;
        }
        ll sm = min(s[0],*s.rbegin())-'a'+1;
        for(auto i:s)ans += i-'a'+1;
        ans -= sm;
        if(ans>sm)cout<<"Alice ";
        else cout<<"Bob ";
        cout<<abs(ans-sm)<<'\n';
        return;
    }
}
int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
