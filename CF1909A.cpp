#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	int flag = 0;
	while(n--){
		pii a;
		cin>>a.fs>>a.sc;
		if(a.fs>0)flag|=8;
		if(a.fs<0)flag|=16;
		if(a.sc>0)flag|=2;
		if(a.sc<0)flag|=4;
	}
	if(__builtin_popcount(flag)==4)cout<<"NO\n";
	else cout<<"YES\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
