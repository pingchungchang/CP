#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define ll __int128

int N,M,a,b,x,y,A,B;

inline ll mad(ll a,ll b,ll mod){
	if(a>=mod)a%= mod;
	if(b>=mod)b%=mod;
	a += b;
	return a>=mod?a-mod:a;
}

vector<ll> conv(vector<ll> ta,vector<ll> tb){
	vector<ll> re(3000,0ll);
	for(int i = 0;i<ta.size();i++){
		for(int j = 0;j<tb.size();j++){
			re[i+j] += ta[i]*tb[j];
		}
	}
	ll sh = 0;
	for(int i = 0;i+1<re.size();i++){
		re[i] += sh;
		sh = re[i]/b;
		re[i] %= b;
	}
	assert(!sh);
	while(re.back() == 0)re.pop_back();
	while(re.size()>y+1){
		auto tmp = re.back();
		re.pop_back();
		re.back() = mad(re.back()%N,tmp%N*b%N,N);
	}
	return re;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	vector<ll> v;
	cin>>a>>b>>x>>y>>N>>M;
	if(b == 1){
		A = 1;
		while(x){
			if(x&1)A = A*a%N;
			a = a*a%N;
			x>>=1;
		}
		cout<<A%N<<' '<<0;return 0;
	}
	while(a){
		v.push_back(a%b);
		a/=b;
	}
	while(v.size()>y+1){
		auto tmp = v.back();
		v.pop_back();
		v.back() = mad(v.back()%N,tmp*b%N,N);
	}

	auto tmp = v;
	x--;
	while(x){
		if(x&1)v = conv(tmp,v);
		tmp = conv(tmp,tmp);
		x>>=1;
	}
	while(v.size()<=y)v.push_back(0);
	ll p = 1;
	for(int i = 0;i<y;i++)B = mad(B,v[i]%M*p%M,M),p = p*b%M;
	p = 1;
	for(int i = y;i<v.size();i++){
		A = mad(A,v[i]%N*p%N,N);
		p = p*b%N;
	}
	cout<<A<<' '<<B;
}
