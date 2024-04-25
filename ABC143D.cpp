#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mxn = 2e3+10;
int bit[mxn];
void modify(int p,int v){for(;p<mxn;p+= p&-p)bit[p]+=v;}
int getval(int s,int e){
    if(s>e)return 0;
    int re = 0;
    for(;e>0;e-= e&-e)re += bit[e];
    s--;
    for(;s>0;s -= s&-s)re -= bit[s];
    return re;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    for(int i = 0;i<n;i++)modify(arr[i],1);
    ll ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            modify(arr[i],-1);modify(arr[j],-1);
            ans += getval(abs(arr[i]-arr[j])+1,abs(arr[i]+arr[j])-1);
            modify(arr[i],1);modify(arr[j],1);
        }
    }
    ans /=3;
    cout<<ans;

}