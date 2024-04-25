#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,l;
    cin>>n>>l;
    int p = 2;
    bool flag = true;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int lst = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] == 2)lst = i;
    }
    int total = 0;
    for(int i = 0;i<lst;i++)total += arr[i];
    if(l-lst-total>=2)cout<<"Yes";
    else cout<<"No";
}