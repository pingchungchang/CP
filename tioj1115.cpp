#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
ld x,y,r;
const ld PI = acos(-1);
void solve(){
	if(y>=r){
		cout<<fixed<<setprecision(2)<<r*r*PI<<'\n';
	}
	else if(y>=0){
		cout<<fixed<<setprecision(2)<<r*r*PI/2+r*r*(PI/2-acos(y/r))+y*sqrt(r*r-y*y)<<'\n';
	}
	else if(y>-r){
		y = abs(y);
		cout<<fixed<<setprecision(2)<<r*r*PI/2-r*r*(PI/2-acos(y/r))-y*sqrt(r*r-y*y)<<'\n';
	}
	else cout<<"0.00\n";
}
int main(){
//	io
	while(cin>>x>>y>>r)solve();
}

