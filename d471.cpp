#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

int n;

void print(int k){
	for(int i = n-1;i>=0;i--){
		if((1<<i)&k)cout<<1;
		else cout<<0;
	}
	cout<<'\n';
	return;
}
void solve(){
	for(int i = 0;i<(1<<n);i++){
		print(i);
	}
	return;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
