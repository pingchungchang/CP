#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n+1] = {};
    for(int i = 1;i<=n;i++)cin>>arr[i];
    int total = 0;
    while(m--){
        int k;
        cin>>k;
        total += arr[k];
    }
    cout<<total;
}