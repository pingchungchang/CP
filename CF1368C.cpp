#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	vector<pii> ans;
	for(int i = 0;i<=n;i++){
		int cen = i*2;
		for(int dx = -1;dx<=1;dx++){
			for(int dy = -1;dy<=1;dy++){
				if(!dx&&!dy)continue;
				ans.push_back({cen+dx,cen+dy});
			}
		}
	}
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return 0;
}
