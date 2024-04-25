#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int h,a,b;
	cin>>h>>a>>b;
	while(a&&h>h/2+10){
		h = h/2+10;
		a--;
	}
	while(b--)h-=10;
	if(h<=0)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
