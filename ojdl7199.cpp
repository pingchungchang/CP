#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll


const ll mod= 1e9+7;
const int mxn = 1e5+10;
const int sq = sqrt(mxn*2);
//const int sq = 0;
vector<int> paths[mxn];
ll ans[mxn];
ll tsum[mxn];
pii op[mxn];
int q;

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll inv(ll k){
	return pw(k,mod-2);
}
inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
inline ll mub(ll a,ll b){
	return mad(a,mod-b);
}


bitset<mxn> mask;
inline void prec(int id){
	mask.reset();
	for(auto &i:paths[id])mask[i] = true;
	bool b = false;
	int invn = inv(paths[id].size());
	for(int i = 1;i<=q;i++){
		if(op[i].fs == 1&&op[i].sc == id)b = true;
		if(op[i].fs == 2&&op[i].sc == id)b = false;
		if(b&&op[i].fs == 3&&mask[op[i].sc])ans[i] = mad(ans[i],invn);
	}
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if(a == b)continue;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		sort(paths[i].begin(),paths[i].end());
		paths[i].erase(unique(paths[i].begin(),paths[i].end()),paths[i].end());
	}

	cin>>q;
	for(int i = 1;i<=q;i++){
		cin>>op[i].fs>>op[i].sc;
	}

	for(int i = 1;i<=n;i++){
		if(paths[i].size()>=sq)prec(i);
	}
	for(int i = 1;i<=q;i++){
		int id = op[i].sc;
		ll invn = inv(paths[id].size());
		if(op[i].fs == 1&&paths[id].size()<sq){
			for(auto &j:paths[id])tsum[j] = mad(tsum[j],invn);
		}
		if(op[i].fs == 2&&paths[id].size()<sq){
			for(auto &j:paths[id])tsum[j] = mub(tsum[j],invn);
		}
		if(op[i].fs == 3){
			ans[i] = mad(ans[i],tsum[id]);
		}
	}
	int C = 0;
	for(int i = 1;i<=q;i++){
		if(op[i].fs == 1)C++;
		else if(op[i].fs == 2)C--;
		else{
			if(!C)ans[i] = 0;
			else ans[i] = ans[i]*inv(C)%mod;
		}
	}

	for(int i = 1;i<=q;i++){
		if(op[i].fs == 3)cout<<ans[i]<<'\n';
	}
	return 0;
}
