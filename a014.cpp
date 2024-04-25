#include <bits/stdc++.h>
using namespace std;

int n,y;
void solve(){
	vector<pair<int,int>> v(n);
	vector<int> all;
	for(int i = 0;i<n;i++){
		cin>>v[i].second>>v[i].first;
		all.push_back(v[i].first);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	priority_queue<int,vector<int>,greater<int>> pq;
	sort(v.begin(),v.end());
	vector<pair<int,pair<int,int>>> ans;
	int p =0;
	for(int i = 0;i<n;i++){
		int k = all[i];
		while(p != v.size()&&v[p].first == k){
			pq.push(v[p].second);
			p++;
		}
		while(!pq.empty()&&pq.top()<k-y)pq.pop();
		if(k-y<=0)k = y+1;
		ans.push_back(make_pair(pq.size(),make_pair(pq.top()+y,k)));
	}
	sort(ans.begin(),ans.end());
//	cout<<ans[ans.size()-1].first<<endl<<endl;
	int x = 0;
	int now = -1;
	int val = -1;
	vector<pair<int,int>> vv;
	for(int i = ans.size()-1;i>=0;i--){
		if(val == -1)val = ans[i].first;
		if(ans[i].first == val)vv.push_back(make_pair(ans[i].second.second,ans[i].second.first));
		else break;
	}
	if(vv.size()==0){
		cout<<0<<'\n';
		return;
	}
	sort(vv.begin(),vv.end());
	x += vv[vv.size()-1].second-vv[vv.size()-1].first+1;
	now = vv[vv.size()-1].first-1;
	for(int i = vv.size()-2;i>=0;i--){
		if(now>vv[i].second){
			now = vv[i].first-1;
			x+= vv[i].second-vv[i].first+1;
		}
		else if(now<vv[i].first){
			continue;
		}
		else{
			x += now-vv[i].first+1;
			now = vv[i].first-1;
		}
	}
	cout<<x<<' '<<ans[ans.size()-1].first<<'\n';
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>n>>y){
		if(n == 0||y==0)return 0;
		solve();
	}
}
