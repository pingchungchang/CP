#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<int>ones;
    string s;
    cin>>s;
    int fz = -1;
    for(int i = 0;i<s.size();i++){
        if(s[i] == '0'&&ones.size()>=1){
            cout<<i-ones.back()+1<<'\n';
            return;
        }
        if(s[i] == '0'&&fz == -1)fz = i;
        if(s[i] == '1')ones.push_back(i);
    }
    if(ones.size()>=1&&fz == -1)cout<<s.size()-ones.back()<<'\n';
    else cout<<(fz == -1?s.size():fz+1)<<'\n';
    return;

}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
