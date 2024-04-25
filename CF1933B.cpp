#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	int cnt[3] = {};
	int sum = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		cnt[k%3]++;
		sum += k%3;
	}
	if(sum%3==0)cout<<"0\n";
	else if(cnt[sum%3] != 0||sum%3==2)cout<<"1\n";
	else cout<<"2\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
