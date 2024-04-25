#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;

map<ll,int> mp,same;
set<int> st;
vector<int> v[mxn];
int n,m;

void solve(){
	for(int i = 0;i<=n+1;i++)v[i].clear();
	mp.clear();
	same.clear();
	st.clear();
	int kkkkk;
	cin>>n>>m>>kkkkk;
	for(int i = 1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		v[l].push_back(i);
		v[r+1].push_back(-i);
	}
	for(int i = 1;i<=n;i++){
		for(auto &j:v[i]){
			if(j>0)st.insert(j);
			else st.erase(-j);
		}
		if(st.empty())mp[0]++;
		else if(st.size()==2){
			ll tmp = 1ll*(*st.begin())*mxn+*st.rbegin();
			mp[tmp]++;
		}
		else if(st.size() == 1)same[*st.begin()]++;
	}
	pii big = {0,0};
	for(int i = 1;i<=m;i++){
		int tmp = same[i];
		if(tmp>big.fs){
			swap(big.fs,big.sc);
			big.fs = tmp;
		}
		else if(tmp>big.sc)big.sc = tmp;
	}
	int ans = mp[0]+big.fs+big.sc;
	int sh = mp[0];
	for(auto &i:mp){
		if(!i.fs)continue;
		int ta = i.fs/mxn,tb = i.fs%mxn;
		ans = max(ans,sh+same[ta]+same[tb]+i.sc);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
