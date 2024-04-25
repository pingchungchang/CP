#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 2e5+10;
int bit[mxn];
int n;
int arr1[mxn];
int pos[mxn];
void modify(int p,int v){
    for(;p<mxn;p+=p&-p)bit[p] = max(bit[p],v);
    return;
}
int getval(int p){
    int re = 0;
    for(;p>0;p -= p&-p)re = max(re,bit[p]);
    return re;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++)cin>>arr1[i];
    for(int i = 1;i<=n;i++){
        int k;
        cin>>k;
        pos[k] = i;
    }
    for(int i = 1;i<=n;i++){
        vector<pii> tmp;
        for(int j = arr1[i];j<=n;j+=arr1[i]){
            tmp.push_back({pos[j],getval(pos[j]-1)+1});
        }
        // for(int j = 0;j<=n;j++)cout<<getval(j)<<' ';cout<<endl;
        for(auto &j:tmp)modify(j.fs,j.sc);
    }
    cout<<getval(n);
}