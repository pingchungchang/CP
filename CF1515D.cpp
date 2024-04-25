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
	int n,l,r;
	cin>>n>>l>>r;
	vector<pii> v(n);
	vector<ll> lef(n+1,0);
	for(int i = 0;i<l;i++){
		int k;cin>>k;
		lef[k]++;
	}
	for(int i = 0;i<r;i++){
		int k;cin>>k;
		lef[k]--;
	}
	l = r = 0;
	for(auto i:lef){
		if(i>0){
			l += i;
		}
		else{
			r += -i;
		}
	}
	int cnt = abs(r-l)/2;
	int ans = cnt;
	for(auto &i:lef){
		if(i>0&&r<l){
			if(cnt>=i/2){
				cnt -= i/2;
				i %=2;
			}
			else{
				i -= cnt*2;
				cnt = 0;
			}
		}
		else if(i<0&&r>l){
			i = abs(i);
			if(cnt>=i/2){
				cnt -= i/2;
				i%=2;
			}
			else{
				i -= cnt*2;
				cnt = 0;
			}
		}
	}
	int lst = 0;
	for(auto i:lef)lst += abs(i);
	if(lst%2 != 0)cout<<"ERROR\n";
	ans += lst/2;
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

