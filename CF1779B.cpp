#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    if(n == 3){
        cout<<"NO\n";
    }
    else if(n&1){
        cout<<"YES\n";
        int a = n/2-1,b = n/2;
        for(int i = 0;i<n;i++){
            if(i&1)cout<<-b<<' ';
            else cout<<a<<' ';
        }
        cout<<'\n';
    }
    else{
        cout<<"YES\n";
        for(int i = 0;i<n;i++){
            if(i&1)cout<<-1<<' ';
            else cout<<1<<' ';
        }
        cout<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
// 1 -2 1 -2 1
// 1 -3 1 -3 1
//i k i . i . i
/*
total = i*n/2+i-k*n/2 = i-k
i*n/2 = k*(n/2-1)
*/
//1 -k 1 -k 1 -k...
//n/2-k*n/2+1