#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int l1,l2,r1,r2;
    cin>>n;
    cin>>l1>>r1>>l2>>r2;
    l2--;
    int arr[n];
    for(auto &i:arr)cin>>i;
    for(int i = l1-1;i < r1;i++){
        swap(arr[i],arr[l2++]);
    }
    for(auto &i:arr)cout<<i<<' ';
}