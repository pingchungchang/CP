#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    a -=b;
    if( a==0)cout<<1;
    else cout<<(int)pow(32,a);
}
