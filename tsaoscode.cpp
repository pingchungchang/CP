#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int q ;
    cin>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i] ;
    }
    int x;
    int y;
    int d;
    int c;
    int e;
    for (int r=0;r<q;r=r+1){
        cin>>x>>y ;
        c=0;
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                c=c+1;
            }
            if(arr[i]==y){
                c=c+1;
            }
        }
        int arr2[c+2];
        d=1;
        arr2[0]=-1;
        arr2[c+1]=n;
        for(int i=0;i<n;i=i+1){
            if(arr[i]==x){
                arr2[d]=i;
                d=d+1;
            }
            if(arr[i]==y){
                arr2[d]=i;
                d=d+1;
            }
        }
        int arr3[c+1];
        for(int i=0;i<c+1;i=i+1){
            arr3[i]=arr2[i+1]-arr2[i];
        }
        e=0;
        for(int i=0;i<c+1;i=i+1){
            if(e<arr[i]){
                e=arr[i];
            }
        }
        cout<<e<<"\n" ;
    }
}