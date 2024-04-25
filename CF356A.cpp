#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	set<int> alives;
	vector<int> loses(n,-1);
	for(int i =0;i<n;i++)alives.insert(i);
	for(int i =0;i<m;i++){
		int l,r,x;
		cin>>l>>r>>x;
		x--;
		l--;
		r--;
		for(auto it = alives.lower_bound(l);it != alives.upper_bound(r);it++){
			//cout<<*it<<' ';
			if(*it != x){
				loses[*it] = x;
				int k = *it;
				it--;
				alives.erase(k);
			}
			//cout<<'\n';
		}

	}
	for(int i =0;i<n;i++){
		cout<<loses[i]+1;
		if(i != n-1)cout<<' ';
	}
}
//fail
