#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e6+10;
ll arr[mxn],pref[mxn],suf[mxn];
deque<int> dq;
pii range[mxn];
vector<pii> op;
set<int> st;
int n;

void solve(){
	st.clear();
	op.clear();
	for(int i = 0;i<=n+1;i++)pref[i] = arr[i] = suf[i] = range[i].fs = range[i].sc = 0;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		pref[i] = pref[i-1]+arr[i];
	}
	pref[n+1] = pref[n];
	suf[n+1] = 0;
	arr[n+1] = 0;
	for(int i = n;i>=1;i--)suf[i] = suf[i+1]+arr[i];
	dq.clear();
	dq.push_back(n+1);
	for(int i = n;i>=0;i--){
		while(dq.back()<=n&&pref[dq.back()]>=pref[i])dq.pop_back();
		range[i+1].sc = dq.back();
		op.push_back(make_pair(dq.back(),i));
		dq.push_back(i);
	}
	sort(op.rbegin(),op.rend());
	dq.clear();
	dq.push_back(0);
	for(int i = 1;i<=n+1;i++){
		while(dq.back()>0&&suf[dq.back()]>=suf[i])dq.pop_back();
		range[i-1].fs = dq.back();
		dq.push_back(i);
	}
	int ans = 0;
	for(int i = 1;i<=n;i++)cout<<pref[i]<<' ';cout<<endl;
	for(int i = 1;i<=n;i++)cout<<suf[i]<<' ';cout<<endl;
	for(int i = 1;i<=n;i++)cout<<range[i].fs<<' ';cout<<endl;
	for(int i = 1;i<=n;i++)cout<<range[i].sc<<' ';cout<<endl;

	/*
   */
	if(*min_element(pref+1,pref+n+1)>=0&&*min_element(suf+1,suf+n+1)>=0)ans = n;

	for(int i = 1;i<=n;i++){
		st.insert(i);
		while(!op.empty()&&op.back().fs == i){
			assert(st.find(op.back().sc) != st.end());
			st.erase(op.back().sc);
			op.pop_back();
		}
		auto it = st.upper_bound(range[i].fs);
		if(it != st.end())ans = max(ans,i-*it);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
