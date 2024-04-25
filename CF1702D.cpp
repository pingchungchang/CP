#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	string s;
	cin>>s;
	ll p;
	cin>>p;
	ll total = 0;
	priority_queue<pll,vector<pll>,less<pll>> pq;
	priority_queue<ll,vector<ll>,greater<ll>> del;
	for(int i = 0;i<s.size();i++){
		pq.push(make_pair(s[i]-'a'+1,i));
		total += s[i]-'a'+1;
	}
	while(total > p&&!pq.empty()){
		del.push(pq.top().sc);
		total -= pq.top().fs;
		pq.pop();
	}
	string ans;
	for(int i= 0;i<s.size();i++){
		if(del.empty()||del.top() != i){
			ans += s[i];
		}
		else del.pop();
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

