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
	if(n == 3)cout<<"-1\n";
	else if(n == 2)cout<<"2 1\n";
	else{
		for(int i = 3;i<=n;i++)cout<<i<<' ';cout<<"1 2\n";
		return;
	}
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

