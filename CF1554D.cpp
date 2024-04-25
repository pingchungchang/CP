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
	if(n&1){
		cout<<'c';
		n--;
	}
	if(!n){
		cout<<'\n';
		return;
	}
	int l = n/2;
	while(l--)cout<<'a';
	cout<<'b';
	l = n/2-1;
	while(l--)cout<<'a';
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
