#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e6+10;
vector<int> paths[mxn];
int lpf[mxn];
int n;

void solve(){
	for(int i = 0;i<=n;i++)paths[i].clear();
	unordered_map<int,int> mp;
	cin>>n;
	int tn = n;
	while(tn != 1){
		mp[lpf[tn]]++;
		tn/=lpf[tn];
	}
	vector<int> fac = {1};
	int sq;
	for(sq = 1;sq*sq<=n;sq++);
	for(auto &i:mp){
		int s = fac.size();
		int tmp = i.fs;
		while(i.sc--){
			for(int j = 0;j<s;j++)fac.push_back(fac[j]*tmp);
			tmp *= i.fs;
		}
	}
	string ans(n,'a');
	for(int i = 0;i<n;i++){
		for(auto &j:fac){
			if(i+j<n&&ans[i+j] == ans[i])ans[i+j]++;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	lpf[0] = lpf[1] = 1;
	for(int i = 2;i<mxn;i++){
		if(!lpf[i]){
			for(int j = i;j<mxn;j+=i)lpf[j] = i;
		}
	}
	int t;cin>>t;
	while(t--)solve();
}
