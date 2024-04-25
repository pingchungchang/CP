#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    vector<pair<int,int>> ans;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(v[i][j] == 'o')ans.push_back(make_pair(i,j));
        }
    }
    cout<<abs(ans[0].first-ans[1].first)+abs(ans[0].second-ans[1].second);
}
