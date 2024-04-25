#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


vector<ll> v;
void solve(){
	ll n;
	cin>>n;
	if(n == 1){
		cout<<"Yes\n1\n";
		return;
	}
	else if(n == 2){
		cout<<"No\n";
		return;
	}
	queue<ll> q;
	q.push(2);
	set<ll> st;
	vector<ll> v = {2};
	int c = 0;
	while(v.size()+q.size()<n&&!q.empty()){
		c++;
		auto now = q.front();
		q.pop();
		if(now*(now+1) > 1e9||now+1>1e9){
			v.push_back(now);
			continue;
		}
		if(st.find(now+1) != st.end()||st.find(now*(now+1)) != st.end()){
			q.push(now);
			continue;
		}
		st.erase(now);
		st.insert(now+1);
		st.insert(now*(now+1));
		q.push(now+1);
		q.push(now*(now+1));
	}
	while(!q.empty()){
		v.push_back(q.front());
		q.pop();
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	assert(v.size() == n);
	cout<<"Yes\n";
	for(auto &i:v)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
