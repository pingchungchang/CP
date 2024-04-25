#include <bits/stdc++.h>
using namespace std;

int f(int now){
    int tmp = now;
    int cnt = 0;
    while(tmp != 0){
        if((tmp&1) != 0)cnt++;
        tmp>>=1;
    }
    if(cnt>1)return 0;
    else{
        if((now&1) != 0)return 2;
        else return 1;
    }
}
void solve(){
    int k;
    cin>>k;
    cout<<(k&-k)+f(k)<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
