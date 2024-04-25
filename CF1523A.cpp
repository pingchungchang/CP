#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i = 0;i<min(n,m);i++){
		string tmp = s;
		for(int j = 0;j<n;j++){
			int C = 0;
			if(j&&s[j-1] == '1')C++;
			if(j != n-1&&s[j+1] == '1')C++;
			if(C == 1)tmp[j] = '1';
		}
		swap(s,tmp);
	}
	cout<<s<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
