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
	int cnt = 0;
	for(int i = n-1;i>=0;i--){
		if(s[i] == '0'){
			if(i>=n/2){
				cout<<1<<' '<<i+1<<' '<<1<<' '<<i<<'\n';
				return;
			}
			else{
				cout<<i+1<<' '<<n<<' '<<i+2<<' '<<n<<'\n';
				return;
			}
		}
		if(s[i] == '1')cnt++;
	}
	cout<<1<<' '<<n-1<<' '<<2<<' '<<n<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

