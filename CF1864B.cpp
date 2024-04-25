#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	if(k%2 == 0){
		sort(s.begin(),s.end());
		cout<<s<<'\n';
		return;
	}
	else{
		string ev,od;
		for(int i = 0;i<n;i++){
			if(i&1)od += s[i];
			else ev += s[i];
		}
		sort(od.rbegin(),od.rend());
		sort(ev.rbegin(),ev.rend());
		for(int i = 0;i<n;i++){
			if(i&1){
				cout<<od.back();
				od.pop_back();
			}
			else{
				cout<<ev.back();
				ev.pop_back();
			}
		}
	}
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
