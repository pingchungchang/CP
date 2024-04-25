#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	if(n == 1){
		cout<<"1\n";
		return;
	}
	else if(n&1){
		cout<<-1<<'\n';
		return;
	}
	vector<int> ans;
	for(int i = 2;i<=n;i+=2)ans.push_back(i),ans.push_back(i-1);
	bool flag = true;
	while(flag){
		flag = false;
		for(int i = 0;i<n;i++){
			if(flag)break;
			int p = ans[i];
			for(int j = i+1;j<n;j++){
				p += ans[j];
				if(p%(j-i+1) == 0){
					flag = true;
					break;
				}
			}
		}
		//random_shuffle(ans.begin(),ans.end());
	}
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
/*
n*(n+1)/2
eoeoeo

4:
3 4 1 2
1 4 2 3
1 3 2 4

6:
1 2 3 4 5 6
1 6 2 5 3 4
1 4 2 5 3 6

8:
1 5 2 6 3 7 4 8

10
1 6 2 7 3 8 4 9 5 10

x x+n/2 x+1 x+n/2+1
*/
