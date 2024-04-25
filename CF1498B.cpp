#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

int highbit(int now){
	int cnt = 0;
	while(now != 0){
		now>>=1;
		cnt++;
	}
	return cnt;
}
void solve(){
	int n,w;
	cin>>n>>w;
	vector<int> v(33,0);
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		v[highbit(k)]++;
	}
	int ans = 0;
	while(n != 0){
//		cout<<n<<endl;
		ans++;
		int lef = w;
		for(int i = 31;i>=1;i--){
			int now = 1<<(i-1);
			if(w<now)continue;
			else{
				int k = lef/now;
				if(k>v[i])k = v[i];
				n -= k;
				lef -= k*now;
				v[i] -= k;
			}
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

