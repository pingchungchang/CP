#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i= 0;i<n;i++){
		cin>>arr[i];arr[i]--;
	}
	
	int d = 0;
	int p = 0;
	while(p != n){
		d++;
		int b = arr[p];
		while(true){
			b = max(b,arr[p]);
			if(p == b){
				p++;
				break;
			}
			p++;
		}
	}
	cout<<d;
}

