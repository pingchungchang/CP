#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	pll arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i].fs;
		arr[i].sc = i;
	}
	ll ans = arr[0].fs+arr[1].fs+arr[2].fs-2;
	sort(arr,arr+n);
	reverse(arr,arr+n);
	set<pll> st;
	for(auto &now:arr){
		st.insert({now.sc,now.fs});
		auto it = st.lower_bound(make_pair(now.sc,now.fs));
		auto lit = it,rit = it;
		if(lit != st.begin())lit--;
		if(lit != st.begin())lit--;
		if(rit != st.end())rit++;
		if(rit != st.end())rit++;
		if(rit != st.end())rit++;
		vector<pll> tmp;
		for(;lit != rit;lit++){
			tmp.push_back(*lit);
		}
		for(int i = 2;i<tmp.size();i++){
			ans = max(ans,tmp[i-2].sc+tmp[i-1].sc+tmp[i].sc-tmp[i].fs+tmp[i-2].fs);
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
