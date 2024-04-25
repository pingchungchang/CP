#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	vector<ll> ans;
	for(ll i = 1;i<=1000;i++){
		for(ll j = 1;j<=1000;j++){
			ans.push_back((i*i+j*j)*(i+j));
		}
	}
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()));
	for(int i = 0;i<10;i++)cout<<ans[i]<<' ';
}

