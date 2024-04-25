#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	int n;
	cin>>n;
	vector<ll> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	ll neg = 0;
	sort(v.begin(),v.end());
	ll diff = (ll)INT_MAX-1,pos = INT_MAX;
	for(int i = 0;i<n;i++){
		if(v[i]<=0)neg++;
		else{
			pos = v[i];
			break;
		}
		diff = min(diff,abs(v[i]-v[i-1]));
	}
	if(pos<=diff)neg++;
	cout<<neg<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}


