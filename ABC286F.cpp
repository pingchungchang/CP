#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
// vector<int> primes = {2,3,4,5,6,7,8,9,10,11,12,13,14};
vector<int> primes = {4,5,7,9,11,13,17,19,23};
// vector<int> primes = {2,3,4,5};
main(){
    // ll ttt = 1;
    // for(auto &i:primes)ttt *= i;
    // cout<<ttt/1e9<<endl;return 0;
    int now = 0;
    int len = 0;
    for(auto &i:primes)len += i;
    int tmp[len+1] = {};
    for(int i = 0;i<=len;i++)tmp[i] = i;
    for(auto i:primes){
        int tt = i;
        while(i--){
            now++;
            tmp[now] = now+1;
        }
        tmp[now] = now-tt+1;
    }
    cout<<len<<endl;
    for(int i = 1;i<=len;i++)cout<<tmp[i]<<' ';cout<<endl;
    for(int i = 1;i<=len;i++)cin>>tmp[i];
    // return 0;
    now = 1;
    auto remain = primes;
    for(int i = 0;i<primes.size();i++){
        remain[i] = tmp[now]-now;
        now += primes[i];
    }

    //CRT
    ll total = 1;
    for(auto &i:primes)total = total*i/__gcd(total,i);
    ll ans = 0;
    for(int i = 0;i<primes.size();i++){
        // cout<<primes[i]<<endl;
        // return 0;
        ll tmpp = total/primes[i];
        while(ans%primes[i] != remain[i])ans = (ans+tmpp)%total;
    }
    ans %= total;
    cout<<ans<<endl;
    return 0;
}