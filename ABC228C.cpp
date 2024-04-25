#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5+10;
int pref[mxn];
int arr[mxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    int k;
    cin>>n;
    cin>>k;
    for(int i = 0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[i] = a+b+c+1;
        pref[arr[i]]++;
    }
    for(int i = 1;i<mxn;i++)pref[i] += pref[i-1];
    for(int i = 0;i<n;i++){
        int low = max(0,arr[i]-300-1);
        int high = arr[i]+300;
        if(pref[mxn-1-1]-pref[high]+1<=k)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}