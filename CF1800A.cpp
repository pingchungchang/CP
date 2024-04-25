#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    while(n--){
        char c;
        cin>>c;
        if(c>='A'&&c<='Z'){
            c = c-'A'+'a';
        }
        if(s.empty()||s.back() != c)s += c;
    }
    if(s != "meow")cout<<"NO\n";
    else cout<<"YES\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}