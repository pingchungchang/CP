#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n = 600851475143;
int main(){
    ll big = 0;
    while(n != 1){
        for(ll i = 2;i<=sqrt(n);i++){
            if(n%i == 0){
                big = max(big,i);
                n/=i;
                break;
            }
            if(i == (int)sqrt(n)){
                big = max(big,i);
                n = 1;
                break;
            }
        }
    }
    cout<<big;
}
