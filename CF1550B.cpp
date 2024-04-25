#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    if(b>=0){
        cout<<(a+b)*n<<'\n';
        return;
    }
    else{
        vector<int> v;
        for(auto &i:s){
            if(v.empty()||v.back() != i-'0')v.push_back(i-'0');
        }
        cout<<a*n+b*(int)(v.size()/2+1)<<'\n';
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}