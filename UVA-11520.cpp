#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<pii> dir = {make_pair(0,1),make_pair(1,0),make_pair(0,-1),make_pair(-1,0)}; 
int x = 0;
void solve(){
	int n;
	x++;
	cout<<"Case "<<x<<":\n";
	cin>>n;
	vector<string> arr(n);
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			int v[4] = {};
			for(auto d:dir){
				if(d.fs+j>=0&&d.fs+j<n&&d.sc+i>=0&&d.sc+i<n&&arr[d.fs+j][d.sc+i]-'A'<4)v[arr[d.fs+j][d.sc+i]-'A'] = 1;
			}
			for(int k = 0;k<4;k++){
				if(v[k] == 0){
					arr[j][i] = 'A'+k;
					break;
				}
			}
		}
	}
	for(auto i:arr)cout<<i<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

