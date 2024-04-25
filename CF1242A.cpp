#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	if(n == 1){
		cout<<1;
		return 0;
	}
	ll N = n;
	vector<ll> paths;
	bool flag = true;
	while(flag){
		flag = false;
		for(ll i = 2;i*i<=n;i++){
			if(n%i == 0){
				flag = true;
				paths.push_back(i);
				while(n%i == 0)n/=i;
			}
		}
	}
	if(n!=1)paths.push_back(n);
	int s = paths.size();
	for(int i = 1;i<s;i++)paths.push_back(paths[i]-paths[i-1]);
	ll G = paths[0];
	for(auto &i:paths)G = __gcd(G,i);
	cout<<G;
}
