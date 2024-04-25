#include <bits/stdc++.h>
using namespace std;
vector<int> v;
bool f(int n,vector<int> vv){
	for(int i = v.size()-1;i>=2;i--){
		if(vv[i]<n)return false;
		int mov = min(vv[i]-n,v[i])/3;
		vv[i-1]+= mov;
		vv[i-2]+= 2*mov;
	}
	if(vv[0]>=n&&vv[1]>=n)return true;
	else return false;
}
void solve(){
	int n;
	cin>>n;
	int r = 0;
	int l = INT_MAX;
	v = vector<int>(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
		r = max(r,v[i]);
	}
	l = 0;
	while(l < r){
//		cout<<l<<' '<<r<<'\n';
		int mid = (r+l+1)/2;
		if(f(mid,v) == true){
			l = mid;
		}
		else r = mid-1;
	}
	cout<<l<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i =0;i<t;i++){
//		cout<<"\n\n";
		solve();
	}
}
