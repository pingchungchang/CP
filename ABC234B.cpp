#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
long double dist(pii a,pii b){
	return (long double)sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> v(n);
	for(int i = 0;i<n;i++)cin>>v[i].first>>v[i].second;
	long double ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			ans = max(ans,dist(v[i],v[j]));
		}
	}
	cout<<setprecision(9)<<ans;
}
