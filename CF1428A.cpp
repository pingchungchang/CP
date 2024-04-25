#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void solve(){
	ll x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	if(x1 == x2||y1 == y2){
		cout<<abs(x1-x2)+abs(y1-y2)<<"\n";
	}
	else{
		cout<<abs(x1-x2)+abs(y1-y2)+2<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

