#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

set<ll> st;

void add(ll a,ll b){
    st.insert(a+b);
    st.insert(a-b);
}
ll getans(ll a,ll b){
    auto lit = st.lower_bound(a),rit = st.lower_bound(b);
    if((*lit)>=a&&(*lit)<=b)return 0;
    else{
        lit--;
        return min(a-*lit,*rit-b);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    st.insert(1e18);
    st.insert(-1e18);
    int q;
    cin>>q;
    int x,y;
    cin>>x>>y;
    add(x,y);
    while(q--){
        int t;
        cin>>t;
        int a,b;
        cin>>a>>b;
        if(t == 1)add(a,b);
        else cout<<getans(a,b)<<'\n';
    }
    return 0;
}

/*
if a+b>=x>=a : abs(x-a-b) = b-x+a
if a+b < x : abs(x-a-b) = x-a-b
if a > x : abs(a-x-b) = b-a+x
*/
