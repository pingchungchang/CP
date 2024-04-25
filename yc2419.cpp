#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	ll ans = 0;
	for(char a = 'A';a<='Z';a++){
		ll C = 0;
		for(auto &i:s){
			if(i == a)C++;
			else ans += C*(C-1)/2;
		}
	}
	cout<<ans;
}
