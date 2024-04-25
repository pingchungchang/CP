#include <bits/stdc++.h>
using namespace std;

bool check(int a,int b,int tar){
    if((a+b)&1)return false;
    if((a+b)/2 != tar||(a^b)!=tar)return false;
    return true;
}
void solve(){
    int n;
    cin>>n;
    int ad = n>>1;
    if(n&ad){
        cout<<-1<<'\n';
        return;
    }
    else if(n&1){
        cout<<"-1\n";
        return;
    }
    cout<<(n|ad)<<' '<<ad<<'\n';
    if(!check(n|ad,ad,n))cout<<"ERROR\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
/*
a+b = (a^b)+((a&b)<<1) = (a^b)*2->(a&b) = (a^b)>>1
*/