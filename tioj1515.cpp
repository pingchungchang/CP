#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
#pragma GCC optimize("O2")
ll pw(ll a,ll b,ll m){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%m;
		a = a*a%m;
		b>>=1;
	}
	return re;
}
const ll p = 97;
const ll mod = 1e9+7;
const ll p2 = 83;
const ll inv = pw(p,mod-2,mod);
const ll inv2 = pw(p2,mod-2,mod);
const int mxn = 2e5+10;
ll pows[mxn];
ll pows2[mxn];
int n;
string s;

bool f(ll len){
	if(len == 0)return true;
	unordered_set<ll> st;
	ll sum = 0;
	ll sum2 = 0;
	for(int i = 0;i<len;i++){
		sum += pows[i]*(s[i]-'A'+1)%mod;
		sum2 += pows2[i]*(s[i]-'A'+1)%mod;
		if(sum>=mod)sum -= mod;
		if(sum2>=mod)sum2 -= mod;
	}
	st.insert(sum*mod+sum2);
	for(int i = len;i<n;i++){
		sum -= (s[i-len]-'A'+1);
		sum2 -= (s[i-len]-'A'+1);
		sum = sum*inv%mod;
		sum2 = sum2*inv2%mod;
		sum += pows[len-1]*(s[i]-'A'+1)%mod;
		sum2 += pows2[len-1]*(s[i]-'A'+1)%mod;
		if(sum>=mod)sum -= mod;
		if(sum2>=mod)sum2-= mod;
		if(st.find({sum*mod+sum2}) != st.end())return true;
		st.insert(sum*mod+sum2);
	}
	return false;
}
int main(){
	io
	cin>>n>>s;
	int l = 0,r = n-1;
	pows[0] = 1;
	pows2[0] = 1;
	for(int i = 1;i<mxn;i++)pows[i] = pows[i-1]*p%mod;
	for(int i = 1;i<mxn;i++)pows2[i] = pows2[i-1]*p2%mod;
	while(l != r){
		int mid = (l+r+1)>>1;
		if(f(mid))l = mid;
		else r = mid-1;
	}
//	for(int i = 0;i<n;i++)cout<<f(i);
	cout<<l;
}

