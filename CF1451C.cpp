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

void solve(){
	ll d,k;
	cin>>d>>k;
	ll mx = 0;
	for(;mx*mx*k*k*2<=d*d;mx++);
	mx--;
	if(k*k*(mx*mx+(mx+1)*(mx+1))<=d*d){
		cout<<"Ashish\n";
	}
	else cout<<"Utkarsh\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

