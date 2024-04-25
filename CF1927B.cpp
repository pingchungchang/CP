#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
string cnt[mxn];
int arr[mxn];
int n;

void solve(){
	for(int i = 0;i<=n;i++)cnt[i].clear();
	for(int i = 'a';i<='z';i++)cnt[0].push_back(i);
	cin>>n;
	string s;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i = 1;i<=n;i++){
		int k = arr[i];
		s += cnt[k].back();
		cnt[k+1].push_back(cnt[k].back());
		cnt[k].pop_back();
	}
	cout<<s<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
