#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
struct P{
	ll l;
	ll r;
	ll u;
	P(){
		l = 1;
		r = 1;
		u = 1;
	}
	P(ll a,ll b,ll c){
		u = a;
		l = b;
		r = c;
	}
};
int main(){
	P now(1,1,1);
	int n;
	cin>>n;
	for(int i = 1;i<n;i++){
		now = P(now.u+now.r+now.l,now.u+now.l,now.u+now.r);
	}
	cout<<now.r+now.u+now.l;
}
