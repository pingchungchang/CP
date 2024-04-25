#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mid =0;
ll* arr;
int n;
ll rec(int now,ll val){
    if(now ==n){
        //cout<<val<<endl<<endl;
        return abs(2*val-mid);
    }
    if(val>mid/2+1){
        return abs(2*val-mid);
    }
    return min(rec(now+1,val+arr[now]),rec(now+1,val));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    arr = new ll(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
        mid += arr[i];
        //cout<<arr[i];
    }
    sort(arr,arr+n);
    cout<<rec(0,0);
}
