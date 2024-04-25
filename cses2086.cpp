#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

const ll mxn = 3030;
struct line{
	ll m,b;
	line(){
		m = 0;
		b = 0;
	}
	line(ll mm,ll bb){
		m = mm,b = bb;
	}
	ll operator()(ll k){
		return m*k+b;
	}
};
ll inter(line a,line b){
	return (a.b-b.b)/(b.m-a.m);
}
ll pref[mxn];
ll dp[mxn];
int main(){
	io
	short now = 0,pre = 1;
	deque<line> dq;
	ll n,k;
	cin>>n>>k;
	for(ll i = 1;i<=n;i++){
		cin>>pref[i];
		pref[i] += pref[i-1];
		dp[i] = pref[i]*pref[i];
	}
	for(ll t = 2;t<=k;t++){
		dq.push_back(line(-pref[t-1]*2,pref[t-1]*pref[t-1]+dp[t-1]));
		for(ll i = t;i<=n;i++){
//			cout<<t<<' '<<i<<": ";
//			for(auto &j:dq){
//				cout<<j.m<<' '<<j.b<<',';
//			}cout<<":";
			while(dq.size()>1&&dq[0](pref[i])>=dq[1](pref[i]))dq.pop_front();
			line tmp(-pref[i]*2,dp[i]+pref[i]*pref[i]);
			dp[i] = dq.front()(pref[i])+pref[i]*pref[i];
			
//			cout<<dp[i]<<endl;
			
			while(dq.size()>1&&inter(dq.back(),dq[dq.size()-2])>=inter(tmp,dq.back())){
				dq.pop_back();
			}
			dq.push_back(tmp);
		}
		dq.clear();
	}
	cout<<dp[n];
}

