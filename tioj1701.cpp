#include <bits/stdc++.h>
using namespace std;

string s;
int n;
bool test(int now){
    for(int i = 0;i<now;i++){
        for(int j = now+i;j<n;j+=now){
            if(s[j] != s[j-now])return false;
        }
    }
    return true;
}
void solve(){
    n = s.size();
    int ans = n;
    for(int i = 1;i*i<=n;i++){
        if(n%i == 0){
            if(test(i))ans = min(ans,i);
            if(test(n/i))ans = min(ans,n/i);
        }
    }
    cout<<n/ans<<'\n';
}
int main(){
    while(cin>>s)solve();
}
