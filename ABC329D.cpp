#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
set<int> cntcnt[mxn];
int cnt[mxn];
int mx = 0;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cntcnt[0].insert(i);
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		cntcnt[cnt[k]].erase(k);
		cnt[k]++;
		cntcnt[cnt[k]].insert(k);
		mx = max(mx,cnt[k]);
		cout<<*cntcnt[mx].begin()<<'\n';
	}
	return 0;
}
