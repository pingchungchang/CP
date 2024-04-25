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
	int n;
	cin>>n;
	vector<ll> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	sort(v.begin(),v.end());
	for(ll i = n-3;i>=0;i--){
		if(v[i]+v[i+1]>v[i+2]){
			cout<<v[i]<<' '<<v[i+1]<<' '<<v[i+2]<<'\n';
			return 0;
		}
	}
	cout<<-1;
	return 0;
}

