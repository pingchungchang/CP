#include <bits/stdc++.h>
using namespace std;


int n,arr[10010];
int t = 0;

int f(int tar,int l,int r){
    if(r<l)return -1;
    t++;
    int mid = l + (r-l)/2;
    if(l == r&&arr[l] != tar)return -1;
    if(arr[mid] == tar)return mid;
    if(arr[mid]>tar)return f(tar,l,mid-1);
    return f(tar,mid+1,r);
}
int main(){
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int a = f(k,0,n-1);
    if(a == -1)cout<<"not found ";
    else cout<<a<<' ';
    cout<<t;
}
