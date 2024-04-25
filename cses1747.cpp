#include <bits/stdc++.h>
using namespace std;

#define _all(T) T.begin(),T.end()
const int mxn = 2e5+10;
#define ll long long
int bit[mxn];
int arr[mxn];
ll lsum[mxn],rsum[mxn];
vector<int> all;
void modify(int p,int v){
    for(;p<mxn;p+=p&-p)bit[p] += v;
    return;
}
int getval(int s,int e){
    int re = 0;
    for(;e>0;e-= e&-e)re += bit[e];
    s--;
    for(;s>0;s-= s&-s)re -= bit[s];
    return re;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    long long ans = 1e18;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
        all.push_back(arr[i]);
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    for(int i = 1;i<=n;i++){
        arr[i] = lower_bound(all.begin(),all.end(),arr[i])-all.begin()+1;
    }
    for(int i = 1;i<=n;i++){
        lsum[i] = lsum[i-1]+getval(arr[i]+1,mxn-1);
        modify(arr[i],1);
    }
    memset(bit,0,sizeof(bit));
    for(int i = n;i>=1;i--){
        rsum[i] = rsum[i+1]+getval(arr[i]+1,mxn-1);
        modify(arr[i],1);
    }
    for(int i = 0;i<=n;i++){
        ans =  min(ans,lsum[i]+rsum[i+1]);
        cout<<i<<":"<<lsum[i]<<' '<<rsum[i+1]<<endl;
    }
    for(int i = 0;i<=n;i++)cout<<lsum[i]<<' ';cout<<endl;
    for(int i = 0;i<=n;i++)cout<<rsum[i]<<' ';cout<<endl;
    cout<<ans;
}