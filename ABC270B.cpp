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
int main(){
	io
	ll x,y,z;
	cin>>x>>y>>z;
	if(y*x<0){
		cout<<abs(x);
	}
	else{
		if(x>0&&y>x)cout<<abs(x);
		else if((x>0&&y<x&&z<y))cout<<abs(z)+abs(z-x);
		else if(x<0&&y<x)cout<<abs(x);
		else if((x<0&&y>x&&z>y))cout<<abs(z)+abs(z-x);
		else cout<<"-1";
	}
}

