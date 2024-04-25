#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	vector<int> v;
	for(int i = 0;i<21;i++){
		v.push_back(i*5);
	}
	int n;
	cin>>n;
	int d = n,ans = 0;
	for(int i = 0;i<v.size();i++){
		if(d>abs(v[i]-n)){
			d = abs(v[i]-n);
			ans = v[i];
		}
	}
	cout<<ans;
}
