#include <bits/stdc++.h>
using namespace std;


int a;
const int mxn = 1<<15;
int bit[mxn];
int ccc = 0;
bool flag = false;

void solve(){
    vector<int> lds;
    lds.push_back(-a);
    while(cin>>a&&a != -1){
        a = -a;
        auto pos = upper_bound(lds.begin(),lds.end(),a)-lds.begin();
        if(pos == lds.size())lds.push_back(a);
        else lds[pos] = a;
    }
    // for(auto &i:lds)cout<<i<<",";cout<<endl;
    if(flag)cout<<'\n';
    cout<<"Test #"<<++ccc<<":\n";
    cout<<"  maximum possible interceptions: "<<lds.size()<<'\n';
    flag = true;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>a){
        if(a == -1)return 0;
        solve();
    }
}