#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define ll long long
#define fs first
#define sc second
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    vector<pll> v(n);
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    for(int i = 0;i<n;i++){
        cin>>v[i].fs;
    }
    for(int i =0;i<n;i++)cin>>v[i].sc;
    for(int i = 0;i<n;i++){
        pq.push(make_pair(v[i].sc,i));
    }
    for(int i = 0;i<q;i++){
        ll a,b;
        ll ans =0;
        cin>>a>>b;
        a--;
        if(v[a].fs>=b){
            v[a].fs -= b;
            ans = b*v[a].sc;
            b= 0;
        }
        else{
            ans += v[a].fs*v[a].sc;
            b -= v[a].fs;
            v[a].fs = 0;
            while(b != 0&&!pq.empty()){
                ll now = pq.top().sc;
                if(v[now].fs>=b){
                    v[now].fs -= b;
                    ans += v[now].sc*b;
                    b = 0;
                }
                else{
                    ans += v[now].fs*v[now].sc;
                    b -= v[now].fs;
                    v[now].fs = 0;
                    pq.pop();
                }
            }
        }
        if(b == 0)cout<<ans<<'\n';
        else cout<<0<<'\n';
    }
}
