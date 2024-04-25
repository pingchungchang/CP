#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int n;

bool check(int k){
	if(k%7 == 0)return false;
	return true;
}

void solve(){
	if(!n)exit(0);
	for(int i = 1;i<n;i++){
		if(check(i))cout<<i<<' ';
	}
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
