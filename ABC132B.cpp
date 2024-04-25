#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    int ans = 0;
    for(int i = 1;i<n-1;i++){
        int tmp[3] = {arr[i-1],arr[i],arr[i+1]};
        sort(tmp,tmp+3);
        if(tmp[1] == arr[i])ans++;
    }
    cout<<ans;
}