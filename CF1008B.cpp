#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(2));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<2;j++)cin>>v[i][j];
        sort(v[i].begin(),v[i].end());
    }
    int now = v[0][1];
    for(int i = 1;i<n;i++){
        if(now>=v[i][1]){
            now = v[i][1];
        }
        else if(now>=v[i][0]){
            now = v[i][0];
        }
        else{
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}
