#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
ll n;
string s;

ll right(){
    if(n%2 == 1)return 0;
    else return n/2*(n-2);
}
ll obtuse(){
    ll t = n/2;
    return t*(t-1)/2*n-right();
}
int main(){
    while(cin>>n>>s){
        if(s[0] == 'R'){
            cin>>s;
            cout<<right()<<'\n';
        }
        else if(s[0] == 'A'){
            cin>>s;
            cout<<n*(n-1)/2*(n-2)/3-right()-obtuse()<<'\n';
        }
        else{
            cin>>s;
            cout<<obtuse()<<'\n';
        }
    }
}
