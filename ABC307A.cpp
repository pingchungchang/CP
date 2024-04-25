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
	for(int i = 0;i<n;i++){
		int sum = 0;
		for(int j =0;j<7;j++){
			int k;
			cin>>k;
			sum += k;
		}
		cout<<sum<<' ';
	}
	return 0;
}
