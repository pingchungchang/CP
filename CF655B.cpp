#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	list<int> lst;
	for(int i = 0;i<k;i++){
		int c;
		cin>>c;
		lst.push_back(c);
	}
	int ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			int c;
			cin>>c;
			auto it = lst.begin();
			ans++;
			while(*it != c)it++,ans++;
			lst.erase(it);
			lst.push_front(c);
		}
	}
	cout<<ans;
}
