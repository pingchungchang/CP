#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,n;
    cin>>a>>b>>c>>n;
    if(c>a||c>b||a+b-c+1>n){
        cout<<-1;
        return 0;
    }
    int total = a+b-c;
    if(total<=n-1){
        cout<<n-total;
    }
}
