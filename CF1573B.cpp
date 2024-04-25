#include <bits/stdc++.h>
using namespace std;
int bisearch(int target,int* segtree,int s,int e,int root){
    if(s ==e)return s;
    if(segtree[2*root+1]>target) return bisearch(target,segtree,s,(s+e)/2,2*root+1);
    else return bisearch(target,segtree,(s+e)/2+1,e,2*root+2);
}

int maketree(int* segtree,int* b,int s,int e,int pos){
    if(s == e){
        segtree[pos] = b[s];
        return segtree[pos];
    }
    else{
        int mid = (s+e)/2;
        maketree(segtree,b,s,mid,2*pos+1);
        maketree(segtree,b,mid+1,e,2*pos+2);
        segtree[pos] = max(segtree[2*pos+1],segtree[2*pos+2]);
        return segtree[pos];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int asd=0;asd<t;asd++){
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i =0;i<n;i++)cin>>a[i];
        for(int i =0;i<n;i++)cin>>b[i];
        int segtree[4*n] = {0};
        maketree((int*)segtree,(int*) b,0,n-1,0);
        if(a[0]<b[0]){
            cout<<0<<'\n';
            continue;
        }
        int ans = INT_MAX;
        for(int i =0;i<n;i++){
            int k = bisearch(a[i],(int*)segtree,0,n-1,0);
            //cout<<k<<'\n';
            ans = min(ans,i+k);
        }
        //cout<<'\n';
        cout<<ans<<'\n';
    }
}
