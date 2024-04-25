#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	ll total = 0;
	for(auto &i:arr){
		cin>>i;
		total += i;
	}
	int c = 0;
	k = n-k;
	multiset<ll> lp,rp,sl,sr;
	ll tl = 0,tr = total;
	for(auto &i:arr)rp.insert(i);
	while(sr.size()<k){
		sr.insert(*rp.rbegin());
		tr -= *rp.rbegin();
		rp.erase(rp.find(*rp.rbegin()));
	}
	ll ans = max(tl,tr);
	for(auto &i:arr){
		if(rp.find(i) != rp.end()){
			rp.erase(rp.find(i));
			tr -= i;
		}
		else{
			sr.erase(sr.find(i));
		}
		tl += i;
		lp.insert(i);
		for(int j = 0;j<2&&!sr.empty();j++){
			rp.insert(*sr.begin());
			tr += *sr.begin();
			sr.erase(sr.find(*sr.begin()));
		}
		for(int j = 0;j<2&&!sl.empty();j++){
			lp.insert(*sl.begin());
			tl += *sl.begin();
			sl.erase(sl.find(*sl.begin()));
		}
		while(sl.size()+sr.size()<k){
			if(tl<tr){
				assert(!rp.empty());
				tr -= *rp.rbegin();
				sr.insert(*rp.rbegin());
				rp.erase(rp.find(*rp.rbegin()));
			}
			else{
				assert(!lp.empty());
				tl -= *lp.rbegin();
				sl.insert(*lp.rbegin());
				lp.erase(lp.find(*lp.rbegin()));
			}
		}
		ans = min(ans,max(tl,tr));
		/*
		cout<<i<<":"<<tl<<','<<tr<<endl;
		cout<<"lp:";for(auto &j:lp)cout<<j<<',';
		cout<<"sl:";for(auto &j:sl)cout<<j<<',';
		cout<<"rp:";for(auto &j:rp)cout<<j<<',';
		cout<<"sr:";for(auto &j:sr)cout<<j<<',';
		cout<<endl;
	   */
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
