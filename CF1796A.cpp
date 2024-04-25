#include <bits/stdc++.h>
using namespace std;

string s;
void solve(){
    string ss;
    int n;
    cin>>n;
    cin>>ss;
    for(int i = 0;i<s.size()-ss.size();i++){
        if(s.substr(i,ss.size()) == ss){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
    return;
}

int main(){
    for(int i = 1;i<=100;i++){
        if(i%3 == 0)s += 'F';
        if(i%5 == 0)s += 'B';
    }
    int t;
    cin>>t;
    while(t--)solve();
}