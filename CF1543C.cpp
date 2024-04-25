#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define ld long double

const ld eps = 1e-7;

ld f(ld c,ld m,ld p,ld v){
	ld re = 0;
	//cout<<c<<' '<<m<<' '<<p<<'\n';
	assert(abs(max((ld)0.0,c)+max((ld)0.0,m)+p-1)<1e-5);
	if(abs(c)>eps){
		if(abs(m) < eps){
			if(c>=v)re += c*f(c-v,m,p+v,v);
			else re += c;
		}
		else{
			if(c>=v)re += c*f(c-v,m+v/2,p+v/2,v);
			else re += c*f(0.0,m+c/2,p+c/2,v);
		}
	}
	if(abs(m)>eps){
		if(abs(c) < eps){
			if(m>=v)re += m*f(c,m-v,p+v,v);
			else re += m;
		}
		else{
			if(m>=v)re += m*f(c+v/2,m-v,p+v/2,v);
			else re += m*f(c+m/2,0.0,p+m/2,v);
		}
	}
	//cout<<c<<' '<<m<<' '<<p<<":"<<re+1<<endl;
	return re+1;
}

void solve(){
	ld c,m,p,v;
	cin>>c>>m>>p>>v;
	//cout<<c<<' '<<m<<' '<<p<<' '<<v<<'\n';
	cout<<fixed<<setprecision(10)<<f(c,m,p,v)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
