#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e7+10;
const int inf = 1e9+10;
int lpf[mxn];

int f(int a,int b,int tar){
    if(a%tar != b%tar)return inf;
    if(a%tar == 0)return 0;
    else return tar-a%tar;
}
void solve(){
    int a,b;
    cin>>a>>b;
    int d = abs(a-b);
    if(a>b)swap(a,b);
    if(d == 0||__gcd(a,b) != 1){
        cout<<"0\n";
        return;
    }
    int ans = inf;
    while(d!= 1){
        int now = lpf[d];
        d/=lpf[d];
        ans = min(ans,f(a,b,now));
    }
    if(ans == inf)cout<<-1<<'\n';
    else cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 2;i<mxn;i++){
        if(!lpf[i]){
            for(int j= i;j<mxn;j+=i)lpf[j] = i;
        }
    }
    int t;
    cin>>t;
    while(t--)solve();
}