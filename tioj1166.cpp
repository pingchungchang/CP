#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    while(cin>>a>>b){
        if(!a&&!b)return 0;
        cout<<__gcd(a,b)<<'\n';
    }
}