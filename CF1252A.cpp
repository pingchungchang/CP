#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i = 1;i<=n;i++){
        arr[i] = abs(n-i+1);
    }
    vector<int>ans;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        ans.push_back(arr[k]);
    }
    for(auto i:ans)cout<<i<<' ';
}
