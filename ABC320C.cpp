#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int m;
	cin>>m;
	string s[3];
	for(auto &i:s)cin>>i,i = i+i+i;
	int ans = 1e9;
	for(char i = '0';i<='9';i++){
		int arr[] = {0,1,2};
		do{
			int pt = 0;
			for(int j = 0;j<s[0].size();j++){
				if(s[arr[pt]][j] == i)pt++;
				if(pt == 3){
					ans = min(ans,j);
					break;
				}
			}
		}while(next_permutation(arr,arr+3));
	}
	if(ans>s[0].size())cout<<-1;
	else cout<<ans;
}
