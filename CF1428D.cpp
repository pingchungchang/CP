#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n;
	cin>>n;
	vector<int> v(n+1);
	for(int i = 1;i<=n;i++)cin>>v[i];
	vector<pii> ans;
	vector<int> done(n+1,0);
	vector<set<int>> nums(4);
	for(int i = 1;i<=n;i++){
		nums[v[i]].insert(i);
	}
	int t = n;
	for(auto i:nums[2]){
		auto it = nums[1].upper_bound(i);
		if(it == nums[1].end()){
			cout<<-1;
			return 0;
		}
		ans.push_back(make_pair(t,i));
		ans.push_back(make_pair(t--,*it));
		nums[1].erase(it);
	}
	for(auto i:nums[3]){
		auto it = nums[1].upper_bound(i);
		if(it == nums[1].end()){
			cout<<-1<<'\n';
			return 0;
		}
		ans.push_back(make_pair(t--,*it));
		ans.push_back(make_pair(t,*it));
		ans.push_back(make_pair(t--,i));
		nums[1].erase(it);
	}
	for(auto i:nums[1]){
		ans.push_back(make_pair(t--,i));
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
}

