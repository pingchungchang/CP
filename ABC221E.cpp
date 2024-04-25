#include <bits/stdc++.h>
using namespace std;

/*void maketree(int* segtree,int s,int e,int * arr,int r){
    if(s == e){
        segtree[r] = s;
        return;
    }
    else{
        int mid = (s+e)/2;
        maketree(segtree,s,mid,arr,2*r+1);
        maketree(segtree,mid+1,e,arr,2*r+2);
        if(arr[segtree[2*r+2]]>arr[segtree[2*r+1]]){
            segtree[r] = segtree[2*r+1];
        }
        else{
            segtree[r] = segtree[2*r+2];
        }
        return;
    }
}
int segfind(int* segtree,int* arr,int s,int e,int n,int r){
    if(arr[segtree[r]]>arr[n])return -1;
    if(s==e&&e==n)return -1;
    else if(s==e)return e;
    int mid = (s+e)/2;
    if(mid>=n-1)return segfind(segtree,arr,s,mid,n,2*r+1);
    else{
        return max(segfind(segtree,arr,s,mid,n,2*r+1),segfind(segtree,arr,mid+1,e,n,2*r+2));
    }
}*/
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)cin>>arr[i];
    int former[n] = {0};
    for(int i =0;i<n;i++)former[i] = i;
    for(int i =1;i<n;i++){
        if(arr[i]>=arr[i-1])former[i] = i-1;
        else{
            int x = i-1;
            while(arr[x]>arr[i]&&former[x]!= x){
                x = former[x];
            }
            if(x != former[x]){
                former[i] = x;
            }
        }
    }
    for(int i =0;i<n;i++)cout<<former[i];
    cout<<endl;
    int ans = 0;
    for(int i =1;i<n;i++){
        if(former[i]!= i){
            ans += former[former[i]]+1;
            former[i] = 2*former[former[i]]+1;
        }
        else former[i] = 0;
    }
    cout<<ans;
    /*int segtree[4*n] = {0};
    maketree((int*)segtree,0,n-1,(int*) arr,0);
    int ans = 0;
    int value[n] = {0};
    for(int i =1;i<n;i++){
        int x =segfind((int*)segtree,(int*) arr,0,n-1,i,0);
        if(x == -1)value[i] = 0;
        else{
            ans += value[x]+1;
            value[i] = value[x]*2+1;
            //value[i] = value[i]%998244353;
            //ans = ans%998244353;
        }
    }
    cout<<ans;*/
}
//how to write segment tree????
