//A:+1;
//B:*2;

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll a;
    string ans;
    cin>>a;
    while(a>1){
        if(a&1 == 1){
            a-=1;
            ans = 'A'+ans;
        }
        else{
            a/=2;
            ans = 'B'+ans;
        }
    }
    cout<<ans;
}
