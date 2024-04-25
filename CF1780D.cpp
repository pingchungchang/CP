#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
int ask(ll k){
    cout<<"- "<<k<<endl;
    int re;
    cin>>re;
    assert(re>=0);
    return re;
}

void solve(){
    int shift = 0;
    int cnt = 0;
    cin>>cnt;
    int ans = 0;
    int pre = cnt;
    for(int i =0;i<30;i++){
        // cout<<(1<<i)<<' '<<shift<<' '<<ans<<endl;
        cnt = ask((1<<i)-shift);
        if(pre-1==cnt){
            ans ^= (1<<i);
            shift = 0;
        }
        else shift += (1<<i)-shift;
        pre = min(pre,cnt);
        if(!cnt)break;
    }
    cout<<"! "<<ans<<endl;
}

main(){
    int t;
    cin>>t;
    while(t--)solve();
}
/*
13:1011

*/
