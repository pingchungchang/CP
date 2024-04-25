#include <bits/stdc++.h>
using namespace std;


const int mxn = 1e5+10;
int bit[mxn];
int n,m,k;
void modify(int p,int v){
    for(;p<=k;p+= p&-p)bit[p] += v;
    return;
}
int getval(int p){
    int re = 0;
    for(;p>0;p -= p&-p)re += bit[p];
    return re;
}
void solve(){
    cin>>n>>m>>k;
    fill(bit,bit+k+1,0);
    int arr[k+1];
    for(int i = 1;i<=k;i++){
		cin>>arr[i];
    }
    for(int i = 1;i<=k;i++){
        int low = getval(arr[i]-1);
        if(low<n*m-3)modify(arr[i],1);
        else{
            cout<<"TIDAK\n";
            return;
        }
    }
    cout<<"YA\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
