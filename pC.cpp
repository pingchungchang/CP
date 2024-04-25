#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	int k = sqrt(n);
	int s =k;
	if(k*k != n)k++;
	vector<pair<bool,pair<int,int>>> seg(k,make_pair(false,make_pair(INT_MAX,-1)));
	vector<int> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
		int pos = i/s;
		seg[pos].second.first = min(seg[pos].second.first,v[i]);
		seg[pos].second.second = max(seg[pos].second.second,v[i]);
		if(i%s == k-1){
			if(seg[pos].second.second == v[i]&&seg[pos].second.first == v[(i/s)*s])seg[pos].first = true;
		}
	}
	if(seg[k-1].second.second == v[n-1]&&seg[k-1].second.first == v[((n-1)/s)*s])seg[k-1].first = true;
	
	for(int i = 0;i<q;i++){
		int a,b;
		cin>>a>>b;
		a--;
		v[a] = b;
		int pos = i/s;
	}
}
