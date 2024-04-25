#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
int arr[mxn],pos[mxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i = 1;i<=n;i++){
        pos[i] = arr[i] = i;
    }
    while(q--){
        int k;
        cin>>k;
        int p = pos[k];
        int np = 0;
        if(p == n)np = p-1;
        else np = p+1;
        int now = arr[p],nxt = arr[np];
        swap(arr[p],arr[np]);
        swap(pos[now],pos[nxt]);
    }
    for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';
    return 0;
}