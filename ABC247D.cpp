#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    queue<pll> q;
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        int t;
        cin>>t;
        if(t == 1){
            ll a,b;
            cin>>a>>b;
            q.push(make_pair(a,b));
        }
        else{
            ll k;
            cin>>k;
            ll ans = 0;
            while(k!= 0){
                if(q.front().sc>k){
                    ans += q.front().fs*k;
                    q.front().sc-=k;
                    k = 0;
                }
                else{
                    ans += q.front().fs*q.front().sc;
                    k -= q.front().sc;
                    q.pop();
                }
            }
            cout<<ans<<'\n';
        }
    }
}
