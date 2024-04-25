#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define _all(T) T.begin(),T.end()

const ll mxn = 1e6+10;
vector<ll> allx,ally;
ll cnt[mxn];
vector<pii> vx,vy;
int n,m,k;

void solve(){
	vx.clear();vy.clear();
	allx.clear();ally.clear();
	for(int i = 0;i<=n+m+k;i++)cnt[i] = 0;
	cin>>n>>m>>k;
	for(int i = 0;i<=n+m+k;i++)cnt[i] = 0;
	for(int i = 0;i<n;i++){
		int tmp;
		cin>>tmp;
		allx.push_back(tmp);
	}
	for(int i = 0;i<m;i++){
		int tmp;
		cin>>tmp;
		ally.push_back(tmp);
	}
	for(int i = 0;i<k;i++){
		pii tmp;
		cin>>tmp.fs>>tmp.sc;
		auto tx = lower_bound(_all(allx),tmp.fs)-allx.begin(),ty = lower_bound(_all(ally),tmp.sc)-ally.begin();
		if(allx[tx] == tmp.fs&&ally[ty] == tmp.sc)continue;
		if(allx[tx] == tmp.fs)vx.push_back({tx,ty});
		else vy.push_back({ty,tx});
	}

	sort(vx.begin(),vx.end());sort(vy.begin(),vy.end());
	ll ans = 0;
	int pre;
	vector<int> buf;
	for(auto &i:vx){
		if(pre != i.fs){
			for(auto &j:buf)cnt[j]++;
			buf.clear();
		}
		pre = i.fs;
		ans += cnt[i.sc];
		buf.push_back(i.sc);
	}
	/*
	cout<<endl;
	for(auto &i:vx)cout<<i.fs<<' '<<i.sc<<endl;cout<<endl;
	cout<<ans<<endl;
	for(auto &i:vy)cout<<i.fs<<' '<<i.sc<<endl;
   */
	for(int i = 0;i<=n+m+k;i++)cnt[i] = 0;
	buf.clear();
	for(auto &i:vy){
		if(pre != i.fs){
			for(auto &j:buf)cnt[j]++;
			buf.clear();
		}
		pre = i.fs;
		ans += cnt[i.sc];
		buf.push_back(i.sc);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
