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
	int n,m;
	cin>>n>>m;
	int tmp = n%2+m%2;
	if(tmp&1){
		cout<<"Burenka\n";
	}
	else cout<<"Tonya\n";
	return;
}

int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}
