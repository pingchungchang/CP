#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(b == 0&&c == 0&&1LL*a*d != 0)cout<<"No";
    else if(abs(c-b)>1)cout<<"No";
    else cout<<"Yes";
}