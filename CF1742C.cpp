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
	string s[8];
	for(auto &i:s)cin>>i;
	for(int i = 0;i<8;i++){
		int cnt = 0;
		for(int j= 0;j<8;j++){
			if(s[i][j] == 'R')cnt++;
		}
		if(cnt == 8){
			cout<<"R\n";
			return;
		}
	}
	cout<<"B\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

