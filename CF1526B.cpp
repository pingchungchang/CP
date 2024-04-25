#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<ll> v;
void solve(){
	ll n;
	cin>>n;
	int k = n%111;
	for(int i = 0;i<11&&k<=n;i++){
		if(k%11 == 0){
			cout<<"YES\n";
			return;
		}
		k += 111;
	}
	cout<<"NO\n";
	return;
}
int main(){
	io
	v = {11};
	for(int i = 3;i<=9;i++)v.push_back(stoll(string(i,'1')));
	int t;
	cin>>t;
	while(t--)solve();
}

