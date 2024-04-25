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
	ll x,y;
	cin>>x>>y;
	ll k = 100-x-y;
	if(k>0&&k<=30)cout<<"sad!\n";
	else if(k>30&&k<=60)cout<<"hmm~~\n";
	else if(k>60&&k<100)cout<<"Happyyummy\n";
	else{
		cout<<"evil!!\n";
	}
	return;
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
}

