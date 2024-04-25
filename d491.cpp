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
	ll a,b;
	cin>>a>>b;
	if(a>b)swap(a,b);
	if(a&1)a++;
	if(b&1)b--;
	ll total = ((b-a)/2+1)*(a+b)/2;
	if(total<0)cout<<"0";
	else cout<<total;
}

