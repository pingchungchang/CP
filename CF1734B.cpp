#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
void solve(){
	int n;
	cin>>n;
	if(n<3){
		for(int i = 1;i<=n;i++){
			for(int j = 0;j<i;j++)cout<<1<<' ';cout<<'\n';
		}
		return;
	}
	cout<<"1\n1 1\n1 0 1\n";
	for(int i = 4;i<=n;i++){
		cout<<1<<' ';
		for(int j = 1;j<i-1;j++)cout<<0<<' ';
		cout<<"1\n";
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

