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
	vector<pll> v;
	bool flag = true;
	while(flag){
		flag = false;
		for(ll i = 2;i*i<=n;i++){
			if(n%i == 0){
				v.push_back({i,0});
				while(n%i == 0){
					v.back().sc++;
					n/=i;
				}
				flag = true;
			}
		}
	}
	if(n != 1)v.push_back({n,1});
	if(v.size()<=2)cout<<"Yes";
	else cout<<"No";
	return 0;
}
