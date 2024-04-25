#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll solve(ll n){
	ll m= n;
	map<ll,int> mp;
	ll k = sqrt(n);
	bool done = false;
	while(done == false){
		if(n <= 3){
			if(!mp.count(n))mp[n] = 1;
			else mp[n]++;
			break;
		}
		for(ll i = 2;i<=k;i++){
			if(n%i == 0){
				if(!mp.count(i))mp[i] = 1;
				else mp[i]++;
				n/=i;
				k = sqrt(n);
				break;
			}
			if(i == k){
				if(mp.count(n) == 0)mp[n] = 1;
				else mp[n]++;
				done = true;
			}
		}
	}
	ll t = 1;
	for(auto it:mp){
		t *= (it.second+1);
	}
	t--;
	return m-t;
}
int main(){
	ll n;
	while(cin>>n){
		if(n>600000000)cout<<n-1<<'\n';
		else{
			cout<<solve(n)<<'\n';
		}
	}
}



