#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;
int root(int k){
    if(mp[k] == 0){
        mp[k] = k;
        return k;
    }
    else return k == mp[k]?k:mp[k] = root(mp[k]);
}
void onion(int a,int b){
    int ra = root(a),rb = root(b);
    mp[ra] = rb;
}
int main(){
    int n;
    cin>>n;
    mp[1] = 1;
    while(n--){
        int a,b;
        cin>>a>>b;
        onion(a,b);
    }
    int ans= 1;
    for(auto &i:mp){
        if(root(i.first) == root(1))ans = max(ans,i.first);
    }
    cout<<ans;

}