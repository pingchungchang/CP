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
int main(){
	io
	int n,q;
	cin>>n>>q;
	int cnt[n+2] = {};
	while(q--){
		int a,b;
		cin>>a>>b;
		cnt[a]++,cnt[b+1]--;
	}
	int now = 0;
	for(int i = 1;i<=n;i++){
		now += cnt[i];
		cout<<(now&1);
	}
	cout<<endl;
}

