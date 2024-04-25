#include <string>
#include <utility>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 1e6+10;
const ll mod = 998244353;

ll fac[mxn],ifac[mxn];
bool started = false;

ll mad(int a,int b){
	 a += b;
	 return a>=mod?a-mod:a;
}
ll mub(ll a,ll b){
	return mad(a,mod-b);
}
ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
ll inv(ll k){
	return pw(k,mod-2);
}

void init(){
	started = true;
	ifac[0] = fac[0] = 1;
	for(int i = 1;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
	ifac[mxn-1] = inv(fac[mxn-1]);
	for(int i = mxn-2;i>=0;i--)ifac[i] = ifac[i+1]*(i+1)%mod;
	return;
}

ll C(ll a,ll b){
	return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

string calc(string s){
	int n = s.size();
	vector<pii> pref(n+1,pii(0,0));
	for(int i = 1;i<=n;i++){
		pref[i] = pref[i-1];
		if(s[i-1] == 'a')pref[i].fs++;
		else pref[i].sc++;
	}
	string ans = s;
	for(int i = n/2;i<=n;i++){
		pii tmp = pii(pref[i].fs-pref[i-n/2].fs,pref[i].sc-pref[i-n/2].sc);
		if(tmp.fs*2 != pref.back().fs||tmp.sc*2 != pref.back().sc)continue;
		else{
			int l = i-n/2+1,r = i;
			l--,r--;
			for(int j = 0;j<n;j++){
				if(j<l||j>r){
					if(s[j] == 'a')ans[j] = '1';
					else ans[j] = '2';
				}
				else{
					if(s[j] == 'a')ans[j] = '2';
					else ans[j] = '1';
				}
			}
			return ans;
		}
	}
	assert(false);
	return "";
}

std::pair<int, std::vector<std::string>> count_and_partition(const std::string& S, int K) {
	if(!started)init();
	pii cnt = pii(0,0);
	int N = S.size();
	vector<int> cuts;
	for(int i = 0;i<N;i++){
		if(S[i] == 'a')cnt.fs++;
		else cnt.sc++;
		if(cnt.fs%2==0&&cnt.sc%2==0)cuts.push_back(i);
	}
	if(cuts.size()<K||cuts.back() != N-1)return make_pair(0,vector<string>());
	int pre = 0;
	vector<string> v;
	for(auto &i:cuts){
		v.push_back("");
		while(pre<=i){
			v.back() += S[pre];
			pre++;
		}
	}
	for(int i = K;i<v.size();i++){
		v[K-1] += v[i];
	}
	while(v.size()>K)v.pop_back();
	//for(auto &i:v)cout<<i<<' ';cout<<endl;
	int ans = C(cuts.size()-1,K-1);
	for(auto &i:v)i = calc(i);
	return make_pair(ans,v);
}
