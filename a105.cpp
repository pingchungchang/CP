#include <bits/stdc++.h>
using namespace std;

bool arr[550][550] = {};
int n,m;

void solve(){
	pair<int,int> a,b;
	cin>>a.first>>a.second>>b.first>>b.second;
	if(a>b)swap(a,b);
	if(a.second == b.second){
		while(a.first <= b.first){
			arr[a.first][a.second] = true; 
			a.first++;
		}
		return;
	}
	if(a.first == b.first){
		while(a.second <= b.second){
			arr[a.first][a.second] = true;
			a.second++;
		}
		return;
	}
	
	if(a.first-a.second == b.first-b.second){
		while(a.first <=b.first){
			arr[a.first][a.second] = true;
			a.first++;
			a.second++;
		}
		return;
	}
	
	while(a.first <= b.first){
		arr[a.first][a.second] = true;
		a.first++;
		a.second--;
	} 
	return;
}
int main(){
	cin>>n>>m;
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
	int ans = 0;
	for(int i = 1;i<=n;i++)for(int j = 0;j<=m;j++)if(arr[i][j])ans++;
	cout<<ans;
}
