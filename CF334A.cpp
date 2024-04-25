#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int p1 = 1,p2 = n*n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n/2;j++){
            cout<<p1<<' ';
            p1++;
        }
        for(int j = 0;j<n/2;j++){
            cout<<p2<<' ';
            p2--;
        }
        cout<<'\n';
    }
}
