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
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	s += '0';
	n = s.size();
	int cnt = 0;
	int pref[n+1] = {};
	for(int i = 0;i<n;i++){
		if(s[i] == '1')cnt++;
		else if(s[i] == '?'){
			pref[i+1]++;
		}
		pref[i+1] += pref[i];
	}
	vector<int> v;
	bool flag[n] = {};
	int ans = 0;
	for(int i = 0;i<n;i++){
		if(s[i] == '0'){
			for(auto &j:v){
				if(j+m<n&&flag[j+m-1]&&pref[j+m]-pref[j] <= m-cnt)ans++;
//				cout<<j<<',';
			}
//			cout<<":";
			v.clear();
		}
		else{
			flag[i] = true;
			v.push_back(i);
		}
	}
//	cout<<ans<<' ';
	if(ans != 1)cout<<"No\n";
	else cout<<"Yes\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

