#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    for(int i = 0;i<n;i++){
        for(int k = 0;k<a;k++){
            for(int j = 0;j<n;j++){
                for(int l = 0;l<b;l++){
                    if((i+j)&1)cout<<"#";
                    else cout<<".";
                }
            }
            cout<<'\n';
        }
    }
}