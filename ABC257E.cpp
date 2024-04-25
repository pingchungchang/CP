#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

struct node{
	ll times[9];
	int l;
	node(){
		l = 0;
		memset(times,0LL,sizeof(times));
	}
	node(ll tt[],int k){
		for(int i = 0;i<9;i++)times[i] = tt[i];
		l = k;
	}
	bool operator<(const node & b)const{
		if(l != b.l)return l<b.l;
		for(int i = 0;i<9;i++){
			if(times[i] != b.times[i])return times[i]<b.times[i];
		}
		return l<b.l;
	}
};

int main(){
	io
	int n;
	cin>>n;
	ll c[9];
	for(int i = 0;i<9;i++)cin>>c[i];
	vector<node> dp(n+1,node());
	reverse(c,c+9);
	for(int i = 0;i<9;i++){
		for(int j = c[i];j<=n;j++){
			ll form[9];
			for(int k = 0;k<9;k++){
				form[k] = dp[j-c[i]].times[k];
			}
			form[i]++;
			node tmp(form,dp[j-c[i]].l+1);
			dp[j] = max(dp[j],tmp);
		}
	}
	string ans;
	for(int i = 0;i<9;i++){
		ans += string(dp[n].times[i],(char)('9'-i));
	}
	cout<<ans;
	return 0;
}

