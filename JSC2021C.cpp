#include <bits/stdc++.h>
using namespace std;

bool f(int d,int a,int b){
    int small = a/d*d;
    if(small<a)small += d;
    int big = b/d*d;
    if(big<a)big += d;
    if(big != small)return true;
    else return false;
}
int main(){
    int a,b;
    cin>>a>>b;
    int ans = 0;
    for(int i = 1;i<=b-a;i++){
        if(f(i,a,b))ans = i;
    }
    cout<<ans;
}