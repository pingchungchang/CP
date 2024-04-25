#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int firstgate = INT_MAX;
    int lastgate = 0;
    vector<int> v(n,-1);
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        if(k == 1){
            if(i<firstgate) firstgate = i;
            lastgate = max(lastgate,i);
        }
        if(k != 0||v[i] != -2){
            v[i] = k;
        }
        if(i != n-1&&i != 0&&k == 9){
            if(v[i-1] == 0) v[i-1] = -2;
            v[i+1] = -2;
        }
    }
    int ans = 0;
    for(int i = firstgate;i<=lastgate;i++){
        if(v[i] == 0) ans++;
        //cout<<v[i]<<' ';
    }
    cout<<ans;
}
