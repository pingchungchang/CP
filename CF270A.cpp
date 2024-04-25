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
	int k;
	cin>>k;
	k = 180-k;
	if(360 %k == 0){
		cout<<"YES\n";
	}
	else cout<<"NO\n";
	return;
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
}

