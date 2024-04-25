#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

int n;
void make(string a,string b,int k){
	//cout<<a<<' '<<b<<k<<'\n';
	string ans;
	int p1 = 0,p2 = 0;
	for(int i = 0;i<n;i++){
		while(p1 < a.size()&&a[p1]-'0' != k)ans += a[p1],p1++;
		while(p2 < b.size()&&b[p2]-'0' != k)ans += b[p2],p2++;
		p1++,p2++;
		ans += '0'+k;
		//cout<<p1<<' '<<p2<<',';
	}
	while(p1<a.size())ans += a[p1],p1++;
	while(p2<b.size())ans += b[p2],p2++;
	assert(ans.size()<=3*n);
	while(ans.size()<n*3)ans+='0';
	cout<<ans<<'\n';
	return;
}

void solve(){
	cin>>n;
	string arr[3];
	int cnt[3] = {};
	pair<int,string> v[3];
	for(int i = 0;i<3;i++){
		cin>>arr[i];
		for(auto &j:arr[i])cnt[i] += j-'0';
		v[i] = {cnt[i],arr[i]};
	}
	sort(v,v+3);
	if(v[1].fs >= n){
		make(v[1].sc,v[2].sc,1);
	}
	else make(v[0].sc,v[1].sc,0);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
