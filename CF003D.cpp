#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 5e5+10;
string s;
pll cost[mxn];
int n;

void solve(){
	for(int i= 1;i<=n;i++){
		cost[i] = {0,0};
	}
	cin>>s;
	n = s.size();
	ll ans = 0;
	for(int i = 0;i<n;i++){
		if(s[i] == '?'){
			cin>>cost[i].fs>>cost[i].sc;
			ans += cost[i].sc;
			cost[i].fs = cost[i].fs-cost[i].sc;
		}
	}
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	int cnt = 0;
	for(int i = 0;i<n;i++){
		if(s[i] == ')')cnt--;
		else if(s[i] == '(')cnt++;
		else{
			pq.push(make_pair(cost[i].fs,1LL*i));
			cnt--;
		}
		while(cnt<0){
			if(pq.empty()){
				cout<<"-1\n";
				return;
			}
			cnt+=2;
			s[pq.top().sc] = '(';
			ans += pq.top().fs;
			pq.pop();
		}
		//cout<<i<<' '<<cnt<<' '<<ans<<',';
	}
	while(cnt>0){
		if(pq.empty()){
			cout<<"-1\n";
			return;
		}
		cnt-=2;
		s[pq.top().sc] = '(';
		ans += pq.top().fs;
		pq.pop();
	}
	while(!pq.empty()){
		s[pq.top().sc] = ')';
		pq.pop();
	}
	int C = 0;
	for(auto &i:s){
		if(i == ')')C--;
		else C++;
		if(C<0){
			cout<<-1;
			return;
		}
	}
	if(C != 0){
		cout<<"QAQ\n";
		return;
	}
	cout<<ans<<'\n';
	cout<<s;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
