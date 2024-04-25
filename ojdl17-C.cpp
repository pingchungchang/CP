#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<int> v;
int n,m;
bool f(int x){
	int tmp = 0;
	int ans = 0;
	for(auto i:v){
		if(i>x)return false;
		tmp += i;
		if(tmp>x){
			ans ++;
			tmp = i;
		}
	}
	if(tmp != 0)ans++;
	if(ans<=m)return true;
	else return false;
}
int main(){
	cin>>n>>m;
	v = vector<int>(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}
	int l = 0,r = 240*n+1;
	while(l != r){
		int mid = (l+r)/2;
		if(f(mid)){
			r = mid;
		}
		else l = mid+1;
	}
	cout<<l; 
}

