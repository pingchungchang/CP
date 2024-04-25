#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxn = 1e3+10;
ll arr[mxn];
int main(){
    int n;
    cin>>n;
    ll s= 0;
    for(int i = 0;i<=n;i++){
        cin>>arr[i];
        if(s>=(1LL<<i)-1)s += arr[i]*(1LL<<i);
    }
    cout<<s+1;
    return 0;
}
