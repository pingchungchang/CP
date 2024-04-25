#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
int cnt[mxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int arr[n+1] = {},brr[n+1] = {},pos1[n+1] = {},pos2[n+1] = {};
    for(int i = 1;i<=n;i++)cin>>arr[i],cnt[arr[i]]++,pos1[arr[i]] = i;
    bool flag = false;
    for(auto &i:cnt)if(i>1)flag = true;
    for(int i = 1;i<=n;i++)cin>>brr[i],cnt[brr[i]]--,pos2[brr[i]] = i;
    for(auto &i:cnt){
        if(i != 0){
            cout<<"No";
            return 0;
        }
    }
    if(flag){
        cout<<"Yes";
        return 0;
    }
    for(int i = 1;i<n-1;i++){
        if(arr[i] == brr[i])continue;
        int p = pos1[brr[i]];
        // cout<<i<<":"<<p<<endl;
        swap(arr[i],arr[p]);
        swap(pos1[arr[i]],pos1[arr[p]]);
        if(p == n){
            swap(brr[n-1],brr[n]);
            swap(pos2[brr[n]],pos2[brr[n-1]]);
        }
        else{
            swap(brr[p],brr[n]);
            swap(pos2[brr[p]],pos2[brr[n]]);
        }
    }
    // for(int i = 1;i<=n;i++)cout<<arr[i];cout<<endl;
    // for(int i = 1;i<=n;i++)cout<<brr[i];cout<<endl;
    for(int i = 1;i<=n;i++){
        if(arr[i] != brr[i]){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}

/*
*/
