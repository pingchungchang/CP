#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    pair<int,int> big = make_pair(-1,-1);
    for(int i = 0;i<n;i++){
        cin>>v[i];
        big = max(big,make_pair(v[i],i));
    }
    int ans = true;
    for(int i = big.second-1;i>=0;i--){
        if(v[i]>v[i+1])ans = false;
    }
    for(int i = big.second+1;i<n;i++){
        if(v[i]>v[i-1])ans = false;
    }
    if(ans)cout<<"YES";
    else cout<<"NO";
}
