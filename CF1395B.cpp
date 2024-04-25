#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 191;
bool done[mxn][mxn];

void solve(){
	int n,m;
	pii now;
	vector<pii> ans;
	cin>>n>>m>>now.fs>>now.sc;
	ans.push_back(now);
	done[now.fs][now.sc] = true;
	int c = 1;
	while(c != n*m){
		bool flag = false;
		for(int i = 1;i<=m;i++){
			if(!done[now.fs][i]){
				now.sc = i;
				ans.push_back(now);
				done[now.fs][now.sc] = true;
				c++;
				flag = true;
				break;
			}
		}
		if(!flag){
			for(int i = 1;i<=n;i++){
				if(!done[i][now.sc]){
					now.fs = i;
					ans.push_back(now);
					done[now.fs][now.sc] = true;
					flag = true;
					c++;
					break;
				}
			}
		}
		if(!flag)break;
	}
	for(auto &i:ans)cout<<i.fs<<' '<<i.sc<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
