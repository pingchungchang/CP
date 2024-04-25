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
	io
	ll n;
	cin>>n;
	vector<ll> v;
	for(ll i =1;i*i<=n;i++){
		if(n%i == 0){
			v.push_back(i);
			v.push_back(n/i);
		}
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(auto i:v)cout<<i<<' ';
}

