#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 1e5+10;

string s;
string ts;
ll ans,cost[2];
ll suf[mxn],pref[mxn];
ll n;

ll calc(string &ss){
	ll p = 0;
	ll re = 0;
	for(int i = 1;i<=n;i++){
		if(ss[i] == '0')re += cost[1]*p;
		else re += cost[0]*(i-1-p),p++;
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s>>cost[0]>>cost[1];
	n = s.size();
	s = "#"+s;
	ts = s;
	for(auto &i:ts)if(i == '?')i = '0';
	ll tans = calc(ts);
	for(int i = n;i>=1;i--){
		suf[i] = suf[i+1] +(ts[i] == '1');
	}
	for(int i = 1;i<=n;i++)pref[i] = pref[i-1]+(ts[i] == '1');
	ll ans = tans;
	ll p = 0;
	//cost[0]:01;cost[1]:10
	for(int i = 1;i<=n;i++){
		if(s[i] == '1')p++;
		if(s[i] == '?'){
			tans = tans-cost[1]*p-cost[0]*suf[i+1];
			p++;
			tans = tans+cost[0]*(i-p)+cost[1]*(n-i-suf[i+1]);
		}
		ans = min(ans,tans);
	}
	p = 0;
	tans = calc(ts);
	for(int i = n;i>=1;i--){
		if(s[i] == '1')p++;
		if(s[i] == '?'){
			tans = tans-cost[0]*p-cost[1]*pref[i-1];
			tans = tans+cost[1]*(n-i-p)+cost[0]*(i-1-pref[i-1]);
			p++;
		}
		ans = min(ans,tans);
	}
	cout<<ans;
}
