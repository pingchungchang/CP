#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 3e5+10;
ll arr[mxn],diff[mxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    for(int i = 0;i<n;i++)cin>>arr[i];
    for(int i = 1;i<n;i++){
        diff[i+2] = arr[i]-arr[i-1];
    }
    ll now[3] = {0,0,0},small[3] = {0,0,0};
    for(int i = 0;i<n+2;i++){
        now[i%3] += diff[i];
        diff[i] = now[i%3];
        small[i%3] = min(small[i%3],now[i%3]);
    }
    for(int i = 0;i<n+2;i++){
        diff[i] -= small[i%3];
    }
    // for(int i = 0;i<n+2;i++)cout<<diff[i]<<' ';cout<<endl;
    ll shift = arr[0]-diff[0]-diff[1]-diff[2];
    if(shift<0){
        cout<<"No";
        return 0;
    }
    for(int i = 0;i<n+2;i+=3)diff[i] += shift;
    for(int i = 0;i<n;i++){
        if(diff[i]+diff[i+1]+diff[i+2] != arr[i]){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes\n";
    for(int i = 0;i<n+2;i++)cout<<diff[i]<<' ';
}