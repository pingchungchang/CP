#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct pt{
    ll x,y;
    pt(){}
    pt(ll a,ll b){
        x = a,y =b;
    }
    pt operator+(pt b)const{
        return pt(x+b.x,y+b.y);
    }
    pt operator-(pt b)const{
        return pt(x-b.x,y-b.y);
    }
    ll operator^(pt b)const{
        return x*b.y-y*b.x;
    }
};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    pt arr[n+1];
    for(int i = 0;i<n;i++)cin>>arr[i].x>>arr[i].y;
    arr[n] = arr[0];
    ll A = 0;
    for(int i = 0;i<n;i++){
        A += (arr[i]^arr[i+1]);
    }
    A = abs(A);
    A += 2;
    ll cnt = 0;
    for(int i=0;i<n;i++){
        if((arr[i]-arr[i+1]).y == 0||(arr[i]-arr[i+1]).x == 0)cnt += max(abs((arr[i]-arr[i+1]).x),abs((arr[i]-arr[i+1]).y));
        else{
            cnt += __gcd(abs((arr[i]-arr[i+1]).x),abs((arr[i]-arr[i+1]).y));
        }
    }
    cout<<(A-cnt)/2<<' '<<cnt;
}
//picks theorem:A = i+b/2-1
//A*2 = i*2+b-2