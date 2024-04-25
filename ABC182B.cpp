#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    pair<int,int> ans = {0,0};
    for(int i = 2;i<=1000;i++){
        int cnt = 0;
        for(auto &j:arr)if(j%i == 0)cnt++;
        ans = max(ans,{cnt,i});
    }
    cout<<ans.second;
}