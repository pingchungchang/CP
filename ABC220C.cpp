#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    long long arr[n];
    long long sum =0;
    for(long long i =0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    long long x;
    cin>>x;
    long long ans = n*(x/sum);
    x =x%sum;
    for(long long i =0;i<n;i++){
        if(x<0)break;
        ans++;
        x -= arr[i];
    }
    cout<<ans;
}
