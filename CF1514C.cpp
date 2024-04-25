#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	int n;
	cin>>n;
	vector<int> fac;
	for(int i = 2;i<n;i++){
		if(n%i == 0){
			fac.push_back(i);
			fac.push_back(n/i);
		}
	}
	bool lef[n+1] = {};
	for(auto i:fac){
		for(int j = i;j<=n;j+=i)lef[j] = true;
	}
	ll total = 1;
	int cnt = 0;
	for(ll i= 1;i<n;i++){
		if(!lef[i]){
			total *= i;
			total %= n;
			cnt++;
		}
	}
	if(total != 1){
		cnt--;
	}
	else total = 0;
	cout<<cnt<<'\n';
	for(int i = 1;i<n;i++){
		if(i == total||lef[i])continue;
		cout<<i<<' ';
	}
	return 0;
}

