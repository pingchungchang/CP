#include <bits/stdc++.h>
using namespace std;
float isprime(int a,int b){
    int x = a;
    a = max(a,b);
    b = min(x,b);
    while(b>0){
        a -= (a/b)*b;
        int k = a;
        a = b;
        b=k;
    }
    if(a == 1)return 1;
    else return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int times = 0;
    while(cin>>n){
        if(times !=0){
            cout<<'\n';
        }
        else times=  1;
        if(n == 0)return 0;
        float primes = 0;
        int sets[n];
        for(int i =0;i<n;i++){
            int k;
            cin>>k;
            sets[i] = k;
        }
        float totals = n*(n-1)/2;
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                primes += isprime(sets[i],sets[j]);
            }
        }
        if(primes == 0)cout<<"No estimate for this data set.";
        else cout<<fixed<<setprecision(6)<<sqrt(6*totals/primes);
    }
}