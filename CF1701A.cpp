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
	int arr[2][2];
	int total = 0;
	for(int i = 0;i<2;i++)for(int j = 0;j<2;j++){
		cin>>arr[i][j];
		total += arr[i][j];
	}
	if(total!= 4&&total>0)cout<<1<<'\n';
	else if(total == 4)cout<<2<<'\n';
	else cout<<"0\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

