#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int mcnt = 0;
	int cnt = 0;
	for(int i = 0;i<n;i++){
		if(s[i] == 'T')cnt++;
		else {
			mcnt++;
			cnt--;
		}
		if(cnt <0){
			cout<<"NO\n";
			return;
		}
	}
	cnt =0;
	reverse(s.begin(),s.end());
	for(int i = 0;i<n;i++){
		if(s[i] == 'T')cnt++;
		else cnt--;
		if(cnt<0){
			cout<<"NO\n";
			return;
		}
	}
	if(mcnt*3 == n){
		cout<<"YES\n";
	}
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

