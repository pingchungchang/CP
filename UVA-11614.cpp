#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    while(cin>>n){
        double k = sqrt(8*n+1);
        k-=1;
        k/=2;
        long long m = k;
        cout<<m<<"\n";
    }
}