#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        int k;
        cin>>k;
        string now;
        for(int j =0;j<k;j++){
            now+="(";
            now+=")";
        }
        for(int j =0;j<k;j++){
            cout<<now<<'\n';
            now[2*j+1] = '(';
            now[2*k-2*j-2] = ')';
        }
    }
}
