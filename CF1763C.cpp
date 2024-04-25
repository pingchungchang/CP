#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n;
    cin>>n;
    ll arr[n];
    for(auto &i:arr)cin>>i;
    if(n>=4){
        cout<<n*(*max_element(arr,arr+n))<<'\n';
        return;
    }
    if(n == 2){
        cout<<max({arr[0]+arr[1],abs(arr[1]-arr[0])*2})<<'\n';
        return;
    }
    cout<<max({arr[0]*3,arr[2]*3,arr[0]+arr[1]+arr[2],abs(arr[2]-arr[1])*3,abs(arr[1]-arr[0])*3})<<'\n';
    /*
        1 2
        2 3
        1 3
        abs(arr[0]-arr[1])+abs(abs(arr[0]-arr[1])-arr[2])*2
    */
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}