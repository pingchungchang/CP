#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	io
	int n;
	cin>>n;
	vector<int> lis;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		int p = lower_bound(_all(lis),k)-lis.begin();
		if(p == lis.size())lis.push_back(k);
		else lis[p] = k;
	}
	cout<<lis.size();
}

