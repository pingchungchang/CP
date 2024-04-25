#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
vector<int> pos[mxn];
set<int> block,pre;
int n;

void solve(){
	for(int i = 0;i<=n;i++)pos[i].clear();
	cin>>n;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		pos[k].push_back(i);
	}
	block.clear();
	pre.clear();
	if(pos[0].size() != 1){
		cout<<"NO\n";
		return;
	}
	pre.insert(pos[0][0]);
	block.insert(0);
	block.insert(n+1);
	for(int i = 1;i<n;i++){
		for(auto &now:pos[i]){
			bool flag = false;
			auto it = pre.upper_bound(now);
			auto bit = block.upper_bound(now);
			if(it != pre.end()&&*it<*bit)flag = true;
			bit--;
			if(it != pre.begin()){
				it--;
				if(*it>*bit)flag = true;
			}
			if(!flag){
				cout<<"NO\n";
				return;
			}
		}
		for(auto &j:pre)block.insert(j);
		pre.clear();
		for(auto &now:pos[i])pre.insert(now);
	}
	cout<<"YES\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
