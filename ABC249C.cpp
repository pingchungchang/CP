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
	int n,k;
	cin>>n>>k;
	string arr[n];
	for(auto &i:arr)cin>>i;
	int ans = 0;
	for(int i = 0;i<(1<<n);i++){
		int tans = 0;
		for(char j = 'a';j<='z';j++){
			int C = 0;
			for(int l = 0;l<n;l++){
				if((1<<l)&i){
					for(int ii = 0;ii<arr[l].size();ii++){
						if(arr[l][ii] == j)C++;
					}
				}
			}
			if(C == k)tans++;
		}
		ans = max(tans,ans);
	}
	cout<<ans;
}
