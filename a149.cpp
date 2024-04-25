#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    int k;
    cin>>k;
    for(int j = 0;j<k;j++){
        cin>>s;
        long long ans = 1;
        int n = s.size();
        for(int i =0;i<n;i++){
            ans *= s[i]-'0';
        }
        cout<<ans<<'\n';
    }
}