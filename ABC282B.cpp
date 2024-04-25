#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    bitset<33> arr[n];
    for(auto &i:arr)i.reset();
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        for(int j = 0;j<m;j++){
            if(s[j] == 'o')arr[i][j] = true;
            else arr[i][j] = false;
        }
    }
    int ans =0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if((arr[i]|arr[j]).count() == m)ans++;
        }
    }
    cout<<ans;
}