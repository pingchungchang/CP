#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n],b[n];
    for(auto &i:a)cin>>i;
    for(auto &i:b)cin>>i;
    int c1 = 0,c2 = 0;
    for(int i = 0;i<n;i++){
        if(a[i] == b[i])c1++;
        for(int j = 0;j<n;j++){
            if(a[i] == b[j]){
                c2++;
            }
        }
    }
    cout<<c1<<'\n'<<c2-c1;
}