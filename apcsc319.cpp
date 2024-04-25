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
	ll n,x;
	cin>>n>>x;
	vector<ll> v(n);
	for(ll i = 0;i<n;i++)cin>>v[i];
	set<ll> st;
	for(ll i= 0;i<n;i++){
		for(ll j =i;j<n;j++)st.insert(v[i]+v[j]);
	}
	for(auto &i:st){
		if(st.find(x-i) != st.end()){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}

