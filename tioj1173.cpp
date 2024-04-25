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
	bool a = false,g = false;
	if(x+z == y*2)a = true;
	if(y != 0&&x != 0&&x*z == y*y)g = true;
	if(a&&g){
		cout<<"both";
	}
	else if(a){
		cout<<"arithmetic";
	}
	else if(g){
		cout<<"geometric";
	}
	else cout<<"normal";
}

