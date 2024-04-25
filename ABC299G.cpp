#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(auto &i:arr)cin>>i;
	map<int,int> mp;
	priority_queue<pii,vector<pii>,greater<pii>> choice;
	for(int i = n-1;i>=0;i--){
		mp[arr[i]]++;
	}
	set<int> done;
	vector<int> ans;
	int id = -1;
	for(int i = 0;i<n;i++){
		if(done.find(arr[i])!=done.end())continue;
		mp[arr[i]]--;
		choice.push(make_pair(arr[i],i));
		if(!mp[arr[i]]){
			mp.erase(arr[i]);
			while(!choice.empty()&&choice.top().fs<=arr[i]){
				auto now = choice.top().sc;
				choice.pop();
				if(done.find(arr[now])!=done.end())continue;
				if(id>now)continue;
				id = now;
				ans.push_back(arr[now]);
				mp.erase(arr[now]);
				done.insert(arr[now]);
			}
		}
	}
	for(auto &i:ans)cout<<i<<' ';return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
