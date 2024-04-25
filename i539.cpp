#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	io
	ll a,b,c,pa,pb,pc;
	cin>>a>>b>>c>>pa>>pb>>pc;
	cout<<fixed<<setprecision(2)<<(ld)(a*pa+b*pb+c*pc)/1000.0;
}

