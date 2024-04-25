#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n;
	cin>>n;
	vector<deque<int>> ans(n+1);
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		ans[i] = ans[i-1];
		if(k == 1){
			ans[i].push_back(1);
			continue;
		}
		while(!ans[i].empty()&&ans[i].back() != k-1){
			ans[i].pop_back();
		}
		if(!ans[i].empty())ans[i].pop_back();
		ans[i].push_back(k);
	}
	for(int i = 1;i<=n;i++){
		auto tmp = ans[i];
		cout<<tmp.front();
		tmp.pop_front();
		while(!tmp.empty()){
			cout<<"."<<tmp.front();
			tmp.pop_front();
		}
		cout<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

