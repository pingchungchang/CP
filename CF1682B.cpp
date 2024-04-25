#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    int ans = -1;
    for(int i = 0;i<n;i++){
        if(v[i] != i){
            int tmp = i;
            int now = i;
            while(v[now] != now){
                int nxt = v[now];
                v[now] = now;
                tmp = (tmp&nxt);
                now = nxt;
            }
            if(ans == -1)ans = tmp;
            else ans = (ans&tmp);
        }
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
