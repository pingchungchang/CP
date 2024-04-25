#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    string a,b;
    cin>>a>>b;
    if(b == "a"){
        cout<<1<<'\n';
        return;
    }
    for(auto i:b){
        if(i == 'a'){
            cout<<-1<<'\n';
            return;
        }
    }
    cout<<(1LL<<(a.size()))<<'\n';
    return;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
