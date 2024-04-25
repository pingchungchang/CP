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
	int n;
	cin>>n;
	vector<string> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(i == j)continue;
			else if(v[i][j] == 'D'&&v[j][i] != 'D'){
				cout<<"incorrect";
				return 0;
			}
			else if(v[i][j] != 'D'&&v[i][j] == v[j][i]){
				cout<<"incorrect";
				return 0;
			}
		}
	}
	cout<<"correct";
	return 0;
}

