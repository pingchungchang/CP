#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

pll dir[] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
int main(){
    pll a,b;
    cin>>a.fs>>a.sc>>b.fs>>b.sc;
    set<pll> st;
    for(auto &i:dir){
        st.insert({a.fs+i.fs,a.sc+i.sc});
    }
    for(auto &i:dir){
        if(st.find({b.fs+i.fs,b.sc+i.sc}) != st.end()){
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
    return 0;
}