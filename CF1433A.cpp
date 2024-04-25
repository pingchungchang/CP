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
	string s;
	cin>>s;
	int ans = 0;
	for(int i = '1';i<='9';i++){
		string now(1,i);
		while(now != s&&now.size()<=4){
			ans += now.size();
			now += i;
		}
		if(now == s){
			ans += now.size();
			break;
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

