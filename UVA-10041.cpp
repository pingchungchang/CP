#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int m;
        cin>>m;
        vector<int> v(m,0);
        for(int j = 0;j<m;j++){
            int k;
            cin>>k;
            v[j] = k;
        }
        sort(v.begin(),v.end());
        int ans = 0;
        for(int j = 0;j<=(v.size()-1)/2;j++){
            ans+=v[m-1-j]-v[j];
        }
        cout<<ans<<endl;
    }
}