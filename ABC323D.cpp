#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	ll n;
	cin>>n;
	for(int i = 0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		pq.push({a,b});
	}
	ll ans = 0;
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		while(!pq.empty()&&pq.top().fs == now.fs){
			now.sc += pq.top().sc;
			pq.pop();
		}
		if(now.sc <= 1){
			ans += now.sc;
		}
		else{
			pq.push({now.fs*2,now.sc/2});
			ans += now.sc&1;
		}
	}
	cout<<ans;
}
