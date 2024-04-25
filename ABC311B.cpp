#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,d;
	cin>>n>>d;
	int cnt[d] = {};
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		for(int j = 0;j<d;j++){
			if(s[j] == 'o')cnt[j]++;
		}
	}
	for(auto &i:cnt)if(i == n)i = 1;else i = 0;
	int pre = 0;
	int ans = 0;
	for(auto &i:cnt){
		if(!i)pre = 0;
		else pre++;
		ans = max(ans,pre);
	}
	cout<<ans;
	return 0;
}
