#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
void solve(){
    int ans;
    pii now;
    cin>>now.first>>now.second;
    cin>>ans;
    int t = 0;
    while(now.fs%2 == 0||now.sc%2 == 0){
        if(now.fs%2 == 0){
            now.fs/=2;
        }
        else now.sc /=2;
        t++;
    }
    if((1LL<<t)>=ans){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
