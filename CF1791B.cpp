#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    pii now = {0,0};
    for(auto &i:s){
        if(i == 'U')now.fs++;
        if(i == 'D')now.fs--;
        if(i == 'R')now.sc++;
        if(i == 'L')now.sc--;
        if(now.fs == now.sc&&now.fs == 1){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();

}