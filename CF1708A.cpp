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
	if(b>a)swap(a,b);
	while(b != 0){
		a %= b;
		swap(a,b);
	}
	return a;
}
void solve(){
	int n;
	cin>>n;
	int g = 0;
	vector<int> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
		g = gcd(g,v[i]);
	}
	if(g%v[0] == 0)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

