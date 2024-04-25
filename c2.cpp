#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 1e6+10;
const ll mod = 1e9+7;

ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}

int bit[mxn];
ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
ll mub(ll a,ll b){
	if(!b)return a;
	else return mad(a,mod-b);
}

void modify(int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] = mad(bit[p],v);
	return;
}
ll getval(int s,int e){
	int re = 0;
	for(;e>0;e-= e&-e)re = mad(bit[e],re);
	s--;
	for(;s>0;s-= s&-s)re = mub(re,bit[s]);
	return re;
}

ll www[mxn],sigma[mxn];
int lpf[mxn];

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	lpf[1] = 1;
	for(int i = 2;i<mxn;i++){
		if(!lpf[i]){
			for(int j = i;j<mxn;j+=i)lpf[j] = i;
		}
	}
	ll n,q,k;
	cin>>n>>q>>k;
	for(int i = 1;i<=n;i++){
		ll tmp;
		cin>>tmp;
		unordered_map<int,int> mp;
		ll tt = tmp;
		while(tmp != 1){
			mp[lpf[tmp]]++;
			tmp/=lpf[tmp];
		}
		vector<ll> all;
		all.push_back(1);
		for(auto &j:mp){
			ll p = j.fs;
			int s = all.size();
			for(int k = 0;k<j.sc;k++){
				for(int l = 0;l<s;l++)all.push_back(all[l]*p);
				p*=j.fs;
			}
		}
		ll total = 0;
		//cout<<tt<<":";for(auto &j:all)cout<<j<<',';cout<<endl;
		for(auto &j:all)total = mad(total,pw(j,k));
		www[i] = total;
		sigma[i] = mp.size();
		modify(i,www[i]*sigma[i]%mod);
	}
	while(q--){
		int t;
		cin>>t;
		if(!t){
			int l,r;
			cin>>l>>r;
			cout<<getval(l,r)%mod<<'\n';
		}
		else{
			int p,t;
			cin>>p>>t;
			if(www[p]*sigma[p]%mod != 0)modify(p,mod-www[p]*sigma[p]%mod);
			unordered_map<ll,ll> mp;
			//cout<<t<<":";
			while(t != 1){
				mp[lpf[t]]++;
				t/=lpf[t];
			}
			for(auto &i:mp){
				ll total = 0;
				ll pp = 1;
				for(int j = 0;j<=i.sc;j++){
					total = mad(total,pw(pp,k));
					pp = pp*i.fs%mod;
				}
				www[p] = www[p]*total%mod;
				sigma[p] = mad(sigma[p],1);
				//cout<<i.fs<<','<<i.sc<<":"<<total<<endl;
			}
			modify(p,sigma[p]*www[p]%mod);
		}
	}
}
