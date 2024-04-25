#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 1e6+10;
pll arr[mxn];
vector<int> shiro,kuro;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	while(cin>>n){
		if(!n)return 0;
		shiro.clear();kuro.clear();
		pll s = {0,0};
		for(int i = 1;i<=n;i++){
			cin>>arr[i].fs>>arr[i].sc;
			s.fs += arr[i].fs,s.sc += arr[i].sc;
			if(arr[i].fs<arr[i].sc)shiro.push_back(i);
			else kuro.push_back(i);
		}
		if(n == 1&&arr[1].fs*arr[1].sc != 0){
			cout<<"-1\n";
			continue;
		}
		if(!s.fs||!s.sc){
			cout<<"0\n";
			continue;
		}

		if(!shiro.empty()&&!kuro.empty()){
			ll ans = 0;
			for(auto &i:shiro)ans += arr[i].fs;
			for(auto &i:kuro)ans += arr[i].sc;
			cout<<ans<<'\n';
			continue;
		}

		if(shiro.empty()){
			assert(kuro.size() == n);
			ll sum = 0;
			for(int i = 1;i<=n;i++)sum += arr[i].sc;
			ll ans = 1e18;
			for(int i = 1;i<=n;i++){
				ans = min(ans,sum-arr[i].sc+arr[i].fs);
			}
			cout<<ans<<'\n';
			continue;
		}

		if(kuro.empty()){
			assert(shiro.size() == n);
			ll sum = 0;
			for(int i = 1;i<=n;i++)sum += arr[i].fs;
			ll ans = 1e18;
			for(int i = 1;i<=n;i++){
				ans = min(ans,sum-arr[i].fs+arr[i].sc);
			}
			cout<<ans<<'\n';
			continue;
		}

	}
}
