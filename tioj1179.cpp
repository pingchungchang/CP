#include <bits/stdc++.h>
using namespace std;

void solve(int s){
    long long total = s;
    int cnt = 1;
    int t;
    while(cin>>t){
        if(!t){
            cout<<s<<' '<<cnt<<' '<<total<<'\n';
            return;
        }
        cnt++;
        total += t;
    }
    return;
}
int main(){
    int n;
    while(cin>>n){
        if(!n)return 0;
        solve(n);
    }
}