#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	string arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 1;i<m;i++){
		for(int j = 0;j<n;j++){
			if(arr[j][i] != arr[j][i-1]){
				cout<<"NO\n";
				return 0;
			}
			if(j&&arr[j][i] == arr[j-1][i]){
				cout<<"NO\n";
				return 0;
			}
		}
	}
	cout<<"YES\n";
	return 0;
}
