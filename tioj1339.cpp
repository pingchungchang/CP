#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
const ll mxn = 1e6+10;
const ll mod = 1000000009;
ll bit1[mxn],bit2[mxn];
pll arr[mxn];
vector<ll> allx = {-1},ally = {-1};

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
inline ll mub(ll a,ll b){
	if(!b)return a;
	else return mad(a,mod-b);
}

void modify(ll p,ll v){
	for(;p<mxn;p+=p&-p)bit1[p] = mad(bit1[p],v),bit2[p]++;
	return;
}

ll getval(int p,ll v){
	ll re = 0;
	for(;p>0;p-= p&-p)re = mad(re,mub(v*bit2[p]%mod,bit1[p]));
	return re;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>arr[i].fs>>arr[i].sc;
		allx.push_back(arr[i].fs);
		ally.push_back(arr[i].sc);
	}
	sort(allx.begin(),allx.end());allx.resize(unique(allx.begin(),allx.end())-allx.begin());
	sort(ally.begin(),ally.end());ally.resize(unique(ally.begin(),ally.end())-ally.begin());
	sort(arr,arr+n);
	ll ans = 0;
	for(int i = 0;i<n;i++){
		ll p = lower_bound(ally.begin(),ally.end(),arr[i].sc)-ally.begin();
		ans = mad(ans,getval(p,arr[i].fs*arr[i].sc%mod));
		modify(p,arr[i].fs*arr[i].sc%mod);
	}
	cout<<ans;
}
