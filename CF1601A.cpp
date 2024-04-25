#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

int gcd(int a,int b){
	if(a<b)swap(a,b);
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}
void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	vector<int> bits(33,0);
	for(int i = 0;i<n;i++){
		cin>>v[i];
		int tmp = v[i];
		for(int j = 0;j<31;j++){
			if((tmp&1))bits[j]++;
			tmp>>=1;
		}
	}
	int G = 0;
	for(auto i:bits){
		G = gcd(G,i);
	}
	for(int i = 1;i<=n;i++){
		if(G%i == 0)cout<<i<<' ';
	}
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

