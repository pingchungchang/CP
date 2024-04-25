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
	ll n;
	cin>>n;
	if(n&1){
		cout<<"Bob\n";
		return;
	}
	else{
		for(int i = 0;i<30;i++){
			if((1<<i) == n){
				if(i&1){
					cout<<"Bob\n";
				}
				else cout<<"Alice\n";
				return;
			}
		}
	}
	cout<<"Alice\n";
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

