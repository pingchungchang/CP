#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;
    cin>>n>>s;
    vector<int> pos;
    for(int i = 0;i<n;i++)if(s[i] == '1')pos.push_back(i);
    if(pos.size()&1){
        cout<<"-1\n";
        return;
    }
    if(pos.size() == 2&&abs(pos[0]-pos[1])<2){
        if(pos[0]>=2||(n-1-pos[1])>=2)cout<<"2\n";
        else{
            if(n<=3)cout<<-1<<'\n';
            else cout<<3<<'\n';
        }
    }
    else cout<<pos.size()/2<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}