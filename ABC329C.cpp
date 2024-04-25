#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


string s;
vector<pii> v;
int cnt[26];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	cin>>s;
	for(auto &i:s){
		if(v.empty()||v.back().fs+'a' != i)v.push_back({i-'a',1});
		else v.back().sc++;
	}
	for(auto &i:v)cnt[i.fs] = max(cnt[i.fs],i.sc);
	int ans = 0;
	for(auto &i:cnt)ans += i;
	cout<<ans;
}
