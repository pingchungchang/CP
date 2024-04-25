#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
pii arr[mxn];
string s[mxn];
int n;

void solve(){
	for(int i = 0;i<=n;i++){
		s[i].clear();
	}
	for(int i = 0;i<n;i++){
		cin>>s[i];
		arr[i].sc = i;
		for(auto &j:s[i])arr[i].fs += j-'0';
	}
	sort(arr,arr+n);
	for(int i = 0;i<n;i++){
		cout<<s[arr[i].sc]<<' ';
	}
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
