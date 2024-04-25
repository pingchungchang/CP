#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	int ans = 0;
	for(char i = 'a';i<='t';i++){
		string tar;
		for(int j = 0;j<n;j++){
			if(a[j] != b[j]&&a[j] == i)tar += b[j];
			else if(a[j] != b[j]&&a[j]>b[j]){
				cout<<-1<<'\n';
				return;
			}
		}
		if(tar.empty())continue;
		sort(tar.begin(),tar.end());
		ans++;
		for(int j = 0;j<n;j++){
			if(a[j] != b[j]&&a[j] == i)a[j] = tar[0];
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
