#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	io
	int n;
	cin>>n;
	vector<int> tar(n*2,0);
	for(int i = 0;i<n*2;i++)cin>>tar[i];
	vector<int> now(n*2);
	for(int i = 0;i<n*2;i++){
		now[i] = i+1;
	}
	int ans = INT_MAX;
	bool flag = false;
	bool done = false;
	for(int i = 0;i<=n*4;i++){
		for(int j = 0;j<n*2;j++){
			if(now[j] != tar[j])break;
			if(j == n*2-1){
				ans = min(ans,i);
				done = true;
			}
		}
		if(done)break;
		if(flag){
			for(int j = 0;j<n*2;j+=2){
				swap(now[j],now[j+1]);
			}
		}
		else{
			for(int j = 0;j<n;j++){
				swap(now[j],now[j+n]);
			}
		}
		flag ^= true;
	}
	flag = true;
	done = false;
	for(int i = 0;i<n*2;i++)now[i] = i+1;
	for(int i = 0;i<=n*4;i++){
		for(int j = 0;j<n*2;j++){
			if(now[j] != tar[j])break;
			if(j == n*2-1){
				ans = min(ans,i);
				done = true;
			}
		}
		if(done)break;
		if(flag){
			for(int j = 0;j<n*2;j+=2){
				swap(now[j],now[j+1]);
			}
		}
		else{
			for(int j = 0;j<n;j++){
				swap(now[j],now[j+n]);
			}
		}
		flag ^= true;
	}
	if(ans == INT_MAX)cout<<-1;
	else cout<<ans;
}

