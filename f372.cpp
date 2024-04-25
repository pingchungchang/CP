#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e4+7;

void solve(int m){
	int t = 3;
	int now = 1;
	while(m>0){
		if((m&1) == 1){
			now *= t;
		}
		m>>=1;
		t = t*t;
		now %= mod;
		t %= mod;
	}
	cout<<now<<'\n';
	return;
}
int main(){
	int m;
	while(cin>>m){
		solve(m);
	}
}
