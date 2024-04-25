#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int odd= 0,ev = 0;
    for(int i =0;i<n;i++){
        int k;
        cin>>k;
        if(k%2)odd++;
        else ev++;
    }
    cout<<min(odd,ev)<<'\n';
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
