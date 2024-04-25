#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
int arr[mxn];
bool ask(int l,int r){
    cout<<"? ";
    cout<<r-l+1<<' ';for(int i = l;i<=r;i++)cout<<i<<' ';cout<<endl;
    int re;
    cin>>re;
    return re != arr[r]-arr[l-1];
}

void solve(){
    int n;
    cin>>n;
    arr[0] = 0;
    for(int i =1;i<=n;i++){
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    int l = 1,r = n;
    while(l != r){
        int mid = (l+r)>>1;
        if(ask(l,mid))r = mid;
        else l = mid+1;
    }
    cout<<"! "<<l<<endl;
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}