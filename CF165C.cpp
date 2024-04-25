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
int main(){
	io
	ll n;
	string s;
	cin>>n>>s;
	int p = 0;
	ll ans = 0;
	ll cnt = 0;
	deque<ll> dq;
	for(ll i = 0;i<s.size();i++){
		if(i>p){
			p = i;
			dq.clear();
		}
		while(!dq.empty()&&dq.front()<i)dq.pop_front();
		while(p<s.size()&&dq.size()<=n){
			if(s[p] == '1')dq.push_back(p);
			p++;
		}
//		p--;
		if(dq.size() < n)break;
		while(dq.size()>n){
			p = dq.back();
			dq.pop_back();
		}
//		cout<<i<<":";for(auto &i:dq)cout<<i<<',';cout<<p<<"\n";cout<<endl;
		if(dq.empty()){
			ans += p-i;
		}
		else ans += p-dq.back();
	}
	cout<<ans;
}

