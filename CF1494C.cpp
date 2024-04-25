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

void solve(){
	ll n,m;
	cin>>n>>m;
	set<ll> st;
	ll ans1 = 0;
	ll cnt = 0;
	vector<ll> pos,neg,spos,sneg;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		if(k<0)neg.push_back(k);
		else pos.push_back(k);
	}
	for(int i = 0;i<m;i++){
		ll k;
		cin>>k;
		if(k>0)spos.push_back(k);
		else sneg.push_back(k);
		st.insert(k);
	}
	for(auto i:pos)if(st.find(i) != st.end())cnt++;
	ll p1 = 0,p2 = 0;
	for(int i = 0;i<spos.size();i++){
		if(p2<i)p2 = i;
		while(p1 != pos.size()&&pos[p1]<spos[i]+p1){
			if(st.find(pos[p1]) != st.end())cnt--;
			p1++;
		}
		while(p2 != spos.size()&&spos[p2]<p1+spos[i]){
			p2++;
		}
		ans1 = max(ans1,p2-i+cnt);
	}
	
	cnt = 0;
	ll ans2 = 0;
	p1 = 0,p2 = 0;
	spos = sneg;
	pos = neg;
	for(auto i:pos)if(st.find(i) != st.end())cnt++;
	for(auto &i:pos)i = abs(i);
	for(auto &i:spos)i = abs(i);
	sort(_all(pos));sort(_all(spos));
	for(int i = 0;i<spos.size();i++){
		if(p2<i)p2 = i;
		while(p1 != pos.size()&&pos[p1]<spos[i]+p1){
			if(st.find(-pos[p1]) != st.end())cnt--;
			p1++;
		}
		while(p2 != spos.size()&&spos[p2]<p1+spos[i]){
			p2++;
		}
		ans2 = max(ans2,p2-i+cnt);
	}
	cout<<ans1+ans2<<'\n';
//	cout<<ans1<<','<<ans2<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

