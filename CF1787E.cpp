#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
int n,k,x;
bitset<mxn> done;

void solve(){
	for(int i = 0;i<=n;i++)done[i] = false;
	cin>>n>>k>>x;
	vector<vector<int>> ans;
	int sum = 0;
	for(int i = 1;i<=n;i++)sum ^= i;
	int h = 0;
	for(int i = 0;i<30;i++){
		if(x&(1<<i))h = i;
	}

	for(int i = 1;i<=n;i++){
		if(done[i])continue;
		if(i&(1<<h)){
			ans.push_back({i,x^i});
			if(ans.back().back() == 0)ans.back().pop_back();
			done[i] = done[x^i] = true;
		}
	}
	/*
	for(auto &i:ans){
		for(auto &j:i)cout<<j<<' ';cout<<'\n';
	}
	cout<<'\n';
	return;
   */
	if(sum != 0&&sum != x){
		cout<<"NO\n";
		return;
	}
	if(ans.empty()){
		cout<<"NO\n";
		return;
	}
	for(int i = 1;i<=n;i++)if(!done[i])ans.back().push_back(i);
	if(ans.size()<k)cout<<"NO\n";
	else if(ans.size()%2 == k%2){
		while(ans.size()>k){
			if(ans.end()[-1].size()>ans.end()[-2].size())swap(ans.end()[-1],ans.end()[-2]);
			while(!ans.end()[-1].empty()){
				ans.end()[-2].push_back(ans.end()[-1].back());
				ans.back().pop_back();
			}
			ans.pop_back();
		}
		cout<<"YES\n";
		for(auto &i:ans){
			cout<<i.size()<<' ';for(auto &j:i)cout<<j<<' ';cout<<'\n';
		}
	}
	else cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
