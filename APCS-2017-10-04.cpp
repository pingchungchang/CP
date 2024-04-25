#include "bits/stdc++.h"
using namespace std;
#define ll long long
typedef struct ob{
    ll w;
    ll t;
} ob;
class Compare{
public:
    bool operator()(ob a,ob b){
        return a.w*b.t>a.t*b.w;
    }
};
int main(){
    ll n;
    ll ans = 0;
    ll times = 0;
    cin>>n;
    vector<ob> v(n);
    for(int i = 0;i<n;i++){
        ll k;
        cin>>k;
        v[i].w = k;
    }
    for(int i = 0;i<n;i++){
        ll k;
        cin>>k;
        times +=k;
        v[i].t = k;
    }
    priority_queue<ob,vector<ob>,Compare> pq;
    for(int i  =0 ;i<n;i++){
        pq.push(v[i]);
    }
    while(!pq.empty()){
        ans += pq.top().w*(times-pq.top().t);
        // cout<<pq.top().w<<' '<<times<<endl;
        times -=pq.top().t;
        pq.pop();
    }
    cout<<ans;
}