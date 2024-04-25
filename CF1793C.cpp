#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int arr[n+1] = {};
	int lpos[n+1] = {},rpos[n+1] = {};
	vector<pair<int,int>> v;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		v.push_back({arr[i],i});
		lpos[i] = rpos[i] = i;
	}
	sort(v.begin(),v.end());
	set<int> big,small;
	big.insert(0);big.insert(n+1);small.insert(0);small.insert(n+1);
	for(auto &i:v){
		int pos = i.second;
		auto it = small.upper_bound(pos);
		rpos[pos] = *it;
		lpos[pos] = *(--it);
		small.insert(pos);
	}
	reverse(v.begin(),v.end());
	for(auto &i:v){
		int pos = i.second;
		auto it = big.upper_bound(pos);
		rpos[pos] = max(rpos[pos],*it);
		lpos[pos] = min(lpos[pos],*(--it));
		big.insert(pos);
	}
	pair<int,int> suf[n+2];
	suf[n+1] = {0,-1};
	suf[n] = {lpos[n],n};
	for(int i = n-1;i>=1;i--){
		suf[i] = max(suf[i+1],make_pair(lpos[i],i));
	}
	pair<int,int> ans = {-1,-1};
	for(int i = 1;i<=n;i++){
		int r = rpos[i];
		if(suf[r].first>=i){
			ans = {i,suf[r].second};
		}
	}
	if(ans.first == -1)cout<<-1<<'\n';
	else cout<<ans.first<<' '<<ans.second<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
