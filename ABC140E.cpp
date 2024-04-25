#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	set<int> st2;
	ll arr[n+1];
	priority_queue<pll,vector<pll>,less<pll>> pq;
	for(int i = 1;i<=n;i++){cin>>arr[i];pq.push({arr[i],i});}
	set<ll> st;
	ll ans = 0;
	st.insert(pq.top().sc);
	st.insert(0);
	st.insert(n+1);
	pq.pop();
	while(!pq.empty()){
		auto now = pq.top().sc;
		auto val = pq.top().fs;
		pq.pop();
		auto it = st.insert(now).fs;
		auto lit = prev(it),rit = next(it);
		if(*lit != 0)ans += val*(*rit-now)*(*lit-*prev(lit));
		if(*rit != n+1)ans += val*(now-*lit)*(*next(rit)-*rit);
	}
	cout<<ans;
}
