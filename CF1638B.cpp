#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<int> v;
int n;
bool f(int l,int r){
//	cout<<l<<' '<<r<<'\n';
	if(r == l)return true;
	else if(r-l == 1&&(v[r]+v[l])%2 == 0&&v[l]>v[r])return false;
	else if(r-l == 1){
		if(v[r]<v[l])swap(v[l],v[r]);
		return true;
	}
	int mid = (l+r)/2;
	bool returns = (f(l,mid)&&f(mid+1,r));
	queue<int> q;
	int odd = 0;
	int evs = 0;
	for(int i = l;i<=mid;i++){
		if(v[i]%2 == 0)evs++;
		else odd++;
	}
	int p1 = l;
	int p2 = mid+1;
	while(p1 != mid+1&&p2 != r+1){
		if(v[p1]<=v[p2]){
			q.push(v[p1]);
			if(v[p1]%2 == 0)evs--;
			else odd--;
			p1++;
		}
		else{
			q.push(v[p2]);
			if(v[p2]%2 == 0&&evs != 0)returns = false;
			else if(v[p2]% 2 == 1&&odd != 0)returns = false;
			p2++;
		}
	}
	while(p1 != mid+1){
		q.push(v[p1]);
		p1++;
	}
	while(p2 != r+1){
		q.push(v[p2]);
		p2++;
	}
	for(int i = l;i<=r;i++){
		v[i] = q.front();
		q.pop();
	}
//	cout<<l<<r<<':';
//	for(int i = l;i<=r;i++)cout<<v[i]<<' ';
//	cout<<'\n';
	return returns;
	
}
void solve(){
	cin>>n;
	v = vector<int>(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	if(f(0,n-1)){
		cout<<"YES\n";
	}
	else cout<<"NO\n";
//	for(auto i:v)cout<<i<<' ';
//	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

