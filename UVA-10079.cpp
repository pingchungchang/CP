#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;

    while(cin>>n){
        if(n<0) return 0;
        cout<<1+(n+1)*n/2<<endl;
    }
}
