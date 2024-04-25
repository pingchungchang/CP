#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n == 0){
        cout<<0;
        return 0;
    }
    if(n == 1){
        cout<<"1\n+";
        return 0;
    }
    int x = 1;
    int times = 0;
    while(n>x){
        times++;
        x*=2;
    }
    x -=1;
    int sol = (x+n)/2;
    cout<<times<<'\n';
    string ans;
    while(sol>0){
        if(sol&1)ans +="+";
        else ans += "-";
        sol>>=1;
    }
    cout<<ans;
}