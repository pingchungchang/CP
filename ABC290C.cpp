#include <bits/stdc++.h>
using namespace std;

const int mxn = 3e5+10;
int arr[mxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        int tmp;
        cin>>tmp;
        if(tmp>=mxn)continue;
        arr[tmp] = 1;
    }
    for(int i = 1;i<mxn;i++)arr[i] += arr[i-1];
    for(int i = 0;i<k;i++){
        if(arr[i] != i+1){
            cout<<i;
            return 0;
        }
    }
    cout<<k;
}