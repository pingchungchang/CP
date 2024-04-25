#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++)cin>>arr[i];
    int p1 = 0,p2 = n-1;
    int ans = 0;
    long long l = 0,r = 0;
    while(p1<=p2){
        if(l == r){
            ans = (n-1-p2+p1);
        }
        if(l>r)r += arr[p2--];
        else l += arr[p1++];
    }
    if(l == r)ans = n;
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
