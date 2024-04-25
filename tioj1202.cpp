#include <bits/stdc++.h>
using namespace std;


int n;
void solve(){
	vector<int> all;
	vector<pair<pair<int,int>,int>> v(n);
	for(int i = 0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v[i] = make_pair(make_pair(a,c),b);
		all.push_back(a);
		all.push_back(c);
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq;
	sort(v.begin(),v.end());
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	vector<int> ans(all.size(),0);
	int p = 0;
	for(int i = 0;i<all.size();i++){
		while(p<n&&v[p].first.first == all[i]){
			pq.push(make_pair(v[p].second,v[p].first.second));
			p++;
		}
		while(!pq.empty()&&pq.top().second<=all[i]){
			pq.pop();
		}
		if(!pq.empty())ans[i] = pq.top().first;
	}
	int nv = -1;
	for(int i = 0;i<ans.size();i++){
		if(nv != ans[i])cout<<all[i]<<' '<<ans[i]<<' ';
		nv = ans[i];
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>n){
		if(n == 0)return 0;
		solve();
	}
}
