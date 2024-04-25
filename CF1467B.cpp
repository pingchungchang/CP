#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<int> v;
bool is(int now){
	if(now <= 0||now >= v.size()-1)return false;
	else if(v[now]>v[now-1]&&v[now]>v[now+1])return true;
	else if(v[now]<v[now-1]&&v[now]<v[now+1])return true;
	return false;
}
void solve(){
	int n;
	cin>>n;
	v = vector<int>(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	int ans =0;
	for(int i = 1;i<n-1;i++){
		if(v[i]>v[i-1]&&v[i]>v[i+1])ans++;
		else if(v[i]<v[i-1]&&v[i]<v[i+1])ans++;
	}
	int now = ans;
	for(int i = 0;i<n;i++){
		int tmp = 0;
		if(is(i))tmp++;
		if(is(i-1))tmp++;
		if(is(i+1))tmp++;
		int test[] = {(i>0?v[i-1]:v[i]),v[i],(i<n-1?v[i+1]:v[i])};
		int tp = tmp;
		for(auto k:test){
			int tt = 0;
			swap(k,v[i]);
			if(is(i))tt++;
			if(is(i-1))tt++;
			if(is(i+1))tt++;
			swap(k,v[i]);
			tp = min(tp,tt);
		}
		now = min(now,ans-tmp+tp);
	}
	cout<<now<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

