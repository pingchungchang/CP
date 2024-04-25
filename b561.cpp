#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define ld long double
const ld pi = 3.14159;

int n;
void solve(){
	ld ta = 0;
	while(n--){
		ld k;
		cin>>k;
		ta += k*k*pi/4;
	}
	cin>>n;
	while(n--){
		ld k;
		cin>>k;
		ta -= k*k*pi/4;
	}
	cout<<fixed<<setprecision(2)<<abs(ta)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
