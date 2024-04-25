#include <iostream>
using namespace std;
int bisearch(int arr[],int k,int s,int e){
    int mid = (s+e)/2;
    if(arr[s] == k)return s+1;
    else if(arr[e] == k)return e+1;
    else if(arr[mid] == k)return mid+1;
    else if(e-s<=1)return 0;
    if(arr[mid]<k)return bisearch(arr,k,mid,e);
    else return bisearch(arr,k,s,mid);
}
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    for(int i =0;i<m;i++){
        int k;
        cin>>k;
        cout<<bisearch(arr,k,0,n-1)<<'\n';
    }
}