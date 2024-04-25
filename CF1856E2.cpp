#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("avx2,popcnt")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e6+10;
int par[mxn],sz[mxn];
vector<int> childs[mxn];
int n;
ll ans = 0;
bool dp[mxn];
vector<pii> all;

inline void CALC(int id){
	all.clear();
	sz[id] = 0;
	sort(childs[id].rbegin(),childs[id].rend());
	for(auto &i:childs[id])sz[id] += i;
	if(!childs[id].empty()&&childs[id][0]*2>=sz[id]){
		ans += 1ll*childs[id][0]*(sz[id]-childs[id][0]);
	}
	else{

		for(auto &i:childs[id]){
			if(all.empty()||all.back().fs != i)all.push_back({i,1});
			else all.back().sc++;
		}
		int s = all.size();

		for(int i = 0;i<s;i++){
			int now = 1;
			while(now<all[i].sc){
				all.push_back({all[i].fs,now});
				all[i].sc -= now;
				now<<=1;
			}
		}
		for(auto &i:all)i.fs *= i.sc;
		s = sz[id]/2;
		for(int i = 0;i<=s;i++)dp[i] = 0;
		dp[0] = 1;
		for(auto &i:all){
			assert(i.fs>0);
			for(int j = s;j>=i.fs;j--){
				dp[j]|=dp[j-i.fs];
			}
		}
		for(int j = s;j>=0;j--){
			if(dp[j]){
				ans += 1ll*j*(sz[id]-j);
				break;
			}
		}
	}

	sz[id]++;
	childs[par[id]].push_back(sz[id]);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 2;i<=n;i++){
		cin>>par[i];
	}
	for(int i = n;i>=1;i--)CALC(i);
	cout<<ans;
}
