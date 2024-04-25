#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define ld long double

const ld PI = acos(-1);


void solve(){
	int n;
	cin>>n;
	ld theta = PI/n;
	ld R = sqrt(2/(1-cos(theta)));
	ld phi = theta/2;
	cout<<fixed<<setprecision(10)<<R*cos(phi)<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
