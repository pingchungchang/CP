#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool check(ll k){
	ll t = k;
	while(t>0){
		if(t%10 != 0&&k%(t%10)!= 0)return false;
		t /=10;
	}
	return true;
}

void solve(){
	ll n;
	cin>>n;
	while(!check(n))n++;
	cout<<n<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
