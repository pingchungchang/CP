#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	pii a,b;
	cin>>a.fs>>a.sc>>b.fs>>b.sc;
	if(a.fs == b.fs){
		if(a.fs == a.sc+b.sc){
			cout<<"Yes\n";
			return;
		}
	}
	if(a.fs == b.sc){
		if(a.fs == a.sc+b.fs){
			cout<<"Yes\n";
			return;
		}
	}
	swap(a.fs,a.sc);
	if(a.fs == b.fs){
		if(a.fs == a.sc+b.sc){
			cout<<"Yes\n";
			return;
		}
	}
	if(a.fs == b.sc){
		if(a.fs == a.sc+b.fs){
			cout<<"Yes\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
