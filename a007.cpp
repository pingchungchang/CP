#include <bits/stdc++.h>

using namespace std;
vector<int> primes;
bool arr[50000] = {};
bool isprime(int n){
    int k = sqrt(n);
    for(auto i:primes){
        if(i>k)return true;
        if(n%i == 0)return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    for(int i = 2;i<1e4*4.7;i++){
        if(arr[i] == true)continue;
        primes.push_back(i);
        for(int j = 2*i;j<1e4*4.7;j+=i){
            arr[j]  = true;
        }
    }
    while(cin>>n){
        if(isprime(n))cout<<"質數\n";
        else cout<<"非質數\n";
    }

}
