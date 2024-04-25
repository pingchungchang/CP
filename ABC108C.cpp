#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    long long   a = 0,b = 0;
    for(int i = 1;i<=n;i++){
        if(i%k == k/2&&k%2 == 0)b++;
        else if(i%k == 0)a++;
    }
    cout<<a*a*a+b*b*b;
}
