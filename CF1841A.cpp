#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	if(n>4)cout<<"Alice\n";
	else if(n == 4)cout<<"Bob\n";
	else if(n == 3)cout<<"Bob\n";
	else if(n == 2)cout<<"Bob\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
