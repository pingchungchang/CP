#include <bits/stdc++.h>
using namespace std;

#define ll long long
int cnt(ll k){
    int re =0;
    while(k){
        if(k&1)re++;
        k>>=1;
    }
    return re;
}
int main(){
    __int128_t ans = 0;
    ll inp;
    cin>>inp;
    __int128_t n = inp;
    int k;
    cin>>k;
    __int128_t arr[k];
    for(int i = 0;i<k;i++){
        cin>>inp;
        arr[i] = inp;
    }
    for(ll i = 1;i<(1LL<<k);i++){
        __int128_t tmp = 1;
        bool flag = true;
        for(int j= 0;j<k;j++){
            if(i&(1LL<<j)){
                if(tmp*arr[j]<=n)tmp *= arr[j];
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(!flag)continue;
        ans += (cnt(i)%2 == 1?1LL:-1LL)*(n/tmp);
    }
    cout<<(ll)ans;
}