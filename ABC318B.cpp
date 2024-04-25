#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 110;
int arr[mxn][mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int j = a;j<b;j++){
			for(int k = c;k<d;k++){
				arr[j][k]++;
			}
		}
	}
	int ans = 0;
	for(auto &i:arr)for(auto &j:i)if(j)ans++;
	cout<<ans;
}
