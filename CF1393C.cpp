#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

map<int,int> mp;
int n;

bool f(int k){
	vector<pii> v;
	for(auto &i:mp)v.push_back({i.sc,i.fs});
	sort(v.rbegin(),v.rend());
	set<int> st;
	for(int i = 0;i<n;i++)st.insert(i);
	int now = 0;
	for(auto &i:v){
		while(st.find(now) == st.end())now++;
		int tmp = now;
		if(k == 2){
			cout<<i.fs<<":";
		}
		while(now<n&&i.fs){
			st.erase(now);
			auto it = st.upper_bound(now+k);
			if(k == 2)cout<<i.fs<<' '<<now<<',';
			i.fs--;
			if(!i.fs)break;
			if(it == st.end())return false;
			now = *it;
		}
		if(k == 2)cout<<endl;
		now = tmp;
		if(i.fs != 0)return false;
	}
	return true;
}

void solve(){
	mp.clear();
	cin>>n;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		mp[k]++;
	}
	int l = 0,r = n-2;
	while(l != r){
		int mid = (l+r+1)>>1;
		if(f(mid))l = mid;
		else r = mid-1;
	}
	cout<<l<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
