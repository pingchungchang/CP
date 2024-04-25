#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> arr(n+1,vector<char>(m+1,'o'));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)cin>>arr[i][j];
    }
    for(int i = 0;i<m;i++){
        int place = n-1;
        for(int j = n;j>=0;j--){
            if(arr[j][i] == 'o')place = j-1;
            if(arr[j][i] == '*'){
                arr[j][i] = '.';
                arr[place][i] = '*';
                place--;
            }
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)cout<<arr[i][j];
        cout<<'\n';
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
