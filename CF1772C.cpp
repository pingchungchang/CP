#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>k>>n;
    int arr[k];
    int l = 1,r = k;
    while(l != r){
        int mid = (l+r+1)>>1;
        if(1+mid*(mid+1)/2+(k-mid-1)>n)r = mid-1;
        else l = mid;
    }
    int now = l;
    arr[k-1] = n;
    for(int i = k-2;i>=0;i--){
        arr[i] = arr[i+1]-now;
        now = max(now-1,1);
    }
    for(int i = 0;i<k;i++)cout<<arr[i]<<' ';cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}