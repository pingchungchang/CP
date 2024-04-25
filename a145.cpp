#include <bits/stdc++.h>
using namespace std;

int main(){
    string in;
    vector<int> w,v;
    getline(cin,in);
    stringstream ss(in);
    int k;
    while(ss>>k){
        w.push_back(k);
    }
    getline(cin,in);
    ss = stringstream(in);
    while(ss>>k){
        v.push_back(k);
    }
    //for(auto i:w)cout<<i<<' ';cout<<endl;for(auto i:v)cout<<i<<' ';cout<<endl;
    int n = v.size();
    int total;
    cin>>total;
    vector<int> dp(total+1,0);
    for(int i = 0;i<n;i++){
        for(int j = total;j>=w[i];j--){
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[total];
}
