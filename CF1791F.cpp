#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
int bit[mxn];
void modify(int p,int v){
    for(;p<mxn;p+=p&-p)bit[p] += v;
    return;
}
int getval(int p){
    int re = 0;
    for(;p>0;p -= p&-p)re += bit[p];
    return re;
}
int calc(int k){
    int total = 0;
    while(k){
        total += k%10;
        k/=10;
    }
    return total;
}
void solve(){
    int n,q;
    cin>>n>>q;
    fill(bit,bit+n+1,0);
    int arr[n+1];
    for(int i =1;i<=n;i++)cin>>arr[i];
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int l,r;
            cin>>l>>r;
            modify(l,1);
            modify(r+1,-1);
        }
        else{
            int p;
            cin>>p;
            int x = getval(p);
            int xx = x;
            while(x>0&&arr[p]/10){
                arr[p] = calc(arr[p]);
                x--;
            }
            modify(p,x-xx);
            modify(p+1,xx-x);
            cout<<arr[p]<<'\n';
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}