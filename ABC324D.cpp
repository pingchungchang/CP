#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

int cnt[10];
string s;
int n;

bool calc(ll k){
	int arr[10] = {};
	while(k)arr[k%10]++,k/=10;
	for(int i = 1;i<10;i++)if(arr[i] != cnt[i])return false;
	if(arr[0]<=cnt[0])return true;
	else return false;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>s;
	sort(s.rbegin(),s.rend());
	for(auto &i:s)cnt[i-'0']++;
	ll ans = 0;
	for(ll i = 0;i*i<=1e13;i++){
		if(calc(i*i))ans++;
	}
	cout<<ans;
}
