#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll a,b,c;
	cin>>a>>b>>c;
	ll x = (a*b+b*c+c*a)*2,y = a*b*c;
	if(x>y)cout<<"2";
	else cout<<"3";
}
