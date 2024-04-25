#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int k = b*c/a;
    if(k*a == b*c)k--;
    cout<<k;
}