#include <bits/stdc++.h>
using namespace std;


int sum(int i){
    string s = to_string(i);
    int total = 0;
    for(auto i:s){
        total += i-'0';
    }
    return total;
}
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        if(sum(i) >=a&&sum(i)<=b)ans += i;
    }
    cout<<ans;
}
