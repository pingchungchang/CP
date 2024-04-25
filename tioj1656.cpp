#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n){
        if(n%27 == 0)cout<<"sad\n";
        else if(n%9 == 0)cout<<"happy\n";
        else if(n%3 == 0)cout<<"sad\n";
        else cout<<"happy\n";
    }
    return 0;
}