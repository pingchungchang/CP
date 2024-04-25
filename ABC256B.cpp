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
	int p = 0;
	int arr[4] = {};
	while(n--){
		int k;
		cin>>k;
		arr[0]++;
		for(int i = 3;i>=0;i--){
			if(k+i>=4){
				p += arr[i];
				arr[i] = 0;
			}
			else{
				arr[i+k] += arr[i];
				arr[i] = 0;
			}
		}
	}
	cout<<p;
}

