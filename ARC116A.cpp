#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	ll n;
	cin>>n;
	if(n%2 == 0&&n%4 != 0){
		cout<<"Same\n";
	}
	else if(n%2 != 0){
		cout<<"Odd\n";
	}
	else{
		cout<<"Even\n";
	}
	return;
}

int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

