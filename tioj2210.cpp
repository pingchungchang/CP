#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 1e5+10;
ll n,C;
ll inc[mxn],decr[mxn],score[mxn],total;

ll f(ll sum){
	ll tar = (sum+n*2-1)/(n*2);
	ll rest = total-sum;;
	ll re = 0;
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	for(int i = 1;i<=n;i++){
		if(score[i]<=tar){
			re += inc[i]*(tar-score[i]);
			rest+=tar-score[i];
		}
		else{
			pq.push({decr[i],score[i]-tar});
		}
	}
	int C = 0;
	while(!pq.empty()&&rest>0){
		C|=1;
		auto now = pq.top();
		pq.pop();
		re += now.fs*min(rest,now.sc);
		rest -= min(rest,now.sc);
	}

	while(!pq.empty())pq.pop();
	for(int i = 1;i<=n;i++){
		if(score[i]<=tar){
			pq.push({inc[i],C-tar});
		}
		else pq.push({inc[i],C-score[i]});
	}
	while(!pq.empty()&&rest<0){
		C|=2;
		auto now = pq.top();
		pq.pop();
		re += now.fs*min(-rest,now.sc);
		rest += min(-rest,now.sc);
	}
	assert(C != 3);
	return re;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>C;
	for(int i = 1;i<=n;i++)cin>>score[i],total += score[i];
	for(int i =1;i<=n;i++)cin>>inc[i];
	for(int i = 1;i<=n;i++)cin>>decr[i];
	ll l = 0,r = C*n;
	while(l+1<r){
		ll mid = (l+r)>>1;
		if(f(mid)<f(mid+1))r = mid;
		else l = mid;
	}
	cout<<min(f(l),f(min(C*n,l+1)));
}
