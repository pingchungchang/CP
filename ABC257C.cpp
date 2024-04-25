#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

struct P{
	int id;
	int w;
	P(){}
};
bool cmp(P a,P b){
	return a.w<b.w;
}
int main(){
	int n;
	string in;
	cin>>n>>in;
	vector<P> v(n,P());
	for(int i = 0;i<n;i++){
		cin>>v[i].w;
		v[i].id = in[i]-'0';
	}
	sort(v.begin(),v.end(),cmp);
	int ans = 0;
	int zero = 0,one = 0;
	for(int i = 0;i<n;i++){
		if(v[i].id == 1)one++;
	}
	ans = one;
	for(int i = 0;i<n;i++){
		if(v[i].id == 0)zero++;
		else one--;
		if(i != n-1&&v[i].w == v[i+1].w)continue;
		ans = max(ans,one+zero);
	}
	cout<<ans;
}

