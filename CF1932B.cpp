#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll n;
	cin>>n;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	__int128_t ans = 0;
	for(auto &i:arr){
		ans = (ans+i)/i*i;
	}
	string s;
	while(ans){
		s += '0'+ans%10;
		ans/=10;
	}
	reverse(s.begin(),s.end());
	cout<<s<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
