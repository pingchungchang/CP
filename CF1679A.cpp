#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n;
    cin>>n;
    if(n%2 != 0){
        cout<<-1<<'\n';
        return;
    }
    n/=2;
    if(n == 1){
        cout<<"-1\n";
        return;
    }
    else if(n == 2){
        cout<<"1 1\n";
        return;
    }
    else if(n == 3){
        cout<<"1 1\n";
        return;
    }
    else if(n == 4){
        cout<<"2 2\n";
        return;
    }
    ll big = (n%2 == 1?(n-3)/2+1:n/2);
    ll small = (n%3 == 0?n/3:n%3 == 1?(n-4)/3+2:n/3+1);
    cout<<small<<' '<<big<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
