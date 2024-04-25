#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a,ll b){
    if(b>a)swap(a,b);
    while(b != 0){
        a%= b;
        swap(a,b);
    }
    return a;
}
int main(){
    srand(time(NULL));
    ll k = rand()%64 +1;
    int a,b;
    while(cin>>a>>b)cout<<gcd(a+k,b+k)<<'\n';
    string s;
/*    while(cin>>s){
        if(s == "?"){
            ll a,b;
            cin>>a>>b;
            cout<<gcd(a+k,b+k)<<'\n';
        }
        else{
            ll a;
            cin>>a;
            if(a == k)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
*/
    cout<<k<<endl;
}
