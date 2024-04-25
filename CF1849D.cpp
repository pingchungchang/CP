#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int arr[n+2] = {};
	int pref[n+2] = {};
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n+1;i++)pref[i] = arr[i]+pref[i-1];
	vector<pii> v;
	vector<int> zero;
	for(int i = 1;i<=n;i++){
		if(!arr[i])zero.push_back(i);
	}
	for(int i = 1;i<=n;i++){
		if(arr[i] != 0){
			int pt = i;
			while(pt<=n&&arr[pt]!= 0)pt++;
			v.push_back({i,pt-1});
			i = pt;
		}
	}
	arr[0] = arr[n+1] = -1;
	int ans = v.size();
	for(auto &i:v){
		if(pref[i.sc]-pref[i.fs-1] != i.sc-i.fs+1){
			arr[i.fs-1] = -1;
			arr[i.sc+1] = -1;
		}
		else{
			if(arr[i.fs-1] == 0)arr[i.fs-1] = -1;
			else arr[i.sc+1] = -1;
		}
	}
	for(auto &i:zero)if(!arr[i])ans++;
	cout<<ans;
}
