#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define ll long long
#define fs first
#define sc second
int main(){
    int n;
    cin>>n;
    queue<pll> q;
    q.push(make_pair(0LL,0LL));
    while(q.front().sc<n){
        pll now = q.front();
        q.pop();
        q.push(make_pair(now.fs+1,now.sc+1));
        q.push(make_pair(now.fs+5,now.sc+1));
        q.push(make_pair(now.fs+10,now.sc+1));
        q.push(make_pair(now.fs+50,now.sc+1));
    }
    set<ll> st;
    while(!q.empty()){
        st.insert(q.front().fs);
        q.pop();
    }
    cout<<st.size()<<'\n';
    for(auto i:st)cout<<i<<' ';
}
//failed
