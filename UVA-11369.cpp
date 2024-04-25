#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int s;
        cin>>s;
        vector<int> v(s,0);
        for(int j = 0;j<s;j++){
            int k;
            cin>>k;
            v[j] = k;
        }
        sort(v.begin(),v.end());
        int x = s/3;
        int ans = 0;
        for(int j = 0;j<x;j++){
            ans+= v[s-3-3*j];
        }
        cout<<ans<<endl;
    }
}