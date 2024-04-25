#include <bits/stdc++.h>
using namespace std;

int main(){
    int s,e;
    int x;
    cin>>s>>e>>x;
    if(e>s){
        if(x<e&&x>=s)cout<<"Yes\n";
        else cout<<"No\n";
        return 0;
    }
    else{
        if(x>=s||e>x)cout<<"Yes\n";
        else cout<<"No\n";
        return 0;
    }
}