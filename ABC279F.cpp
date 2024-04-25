#include <bits/stdc++.h>
using namespace std;


const int mxn = 3e5+10;

map<int,int> mp,box;
int dsu[mxn*2];
int pt;
map<int,int> pos;
int root(int k){
    return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
    //combine b into a
    int ra = box[a],rb = box[b];
    dsu[rb] = ra;
    mp[++pt] = b;
    box[b] = pt;
    return;
}
//dp[i] = 

int main(){
    int n,q;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i = 1;i<mxn*2;i++)dsu[i] = i;
    for(int i = 1;i<=n;i++){
        pos[i] = i;
        box[i] = i;
        mp[i] = i;
    }
    pt = n;
    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int a,b;
            cin>>a>>b;
            onion(a,b);
        }
        else if(t == 2){
            int p;
            cin>>p;
            pos[++n] = box[p];
        }
        else{
            int k;
            cin>>k;
            cout<<mp[root(pos[k])]<<'\n';
        }
    }
    return 0;
}
