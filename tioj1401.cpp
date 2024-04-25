#include <bits/stdc++.h>
using namespace std;

int n;
bool f(vector<pair<int,int>> &v){
	int p = 0;
	sort(v.begin(),v.end());
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i = 1;i<=n;i++){
		while(p != v.size()&&v[p].first<=i){
			pq.push(v[p].second);
			p++;
		}
		while(!pq.empty()&&pq.top()<i)pq.pop();
		if(pq.empty())return false;
		pq.pop();
	}
	return true;
}
int main(){
	while(cin>>n){
		vector<pair<int,int>> hor(n);
		vector<pair<int,int>> ver(n);
		for(int i = 0;i<n;i++){
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			hor[i] = make_pair(min(a,b),max(a,b));
			ver[i] = make_pair(min(c,d),max(c,d));
		}
		bool ans = true;
		ans = ans&f(hor);
		ans = ans&f(ver);
		if(ans == true)cout<<"YES\n";
		else cout<<"NO\n";
	}
}
