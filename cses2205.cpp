#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<string> ans = {"0","1"};
    for(int i =1;i<n;i++){
        for(int j = ans.size()-1;j>=0;j--){
            ans.push_back(ans[j]);
        }
        for(int j =0;j<ans.size()/2;j++){
            ans[j] = '0'+ans[j];
        }
        for(int j =ans.size()/2;j<ans.size();j++){
            ans[j] = '1'+ans[j];
        }
    }
    for(int i =0;i<ans.size();i++)cout<<ans[i]<<'\n';
}
