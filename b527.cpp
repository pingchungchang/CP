#include <bits/stdc++.h>
using namespace std;

int main(){
	int m;
	cin>>m;
	int arr[m];
	for(int i = 0;i<m;i++)cin>>arr[i];
	for(int i = 0;i<(1<<(m-1));i++){
		int total = arr[0];
		int total2 = 0;
		int tt = i;
		for(int j = 1;j<m;j++){
			if(tt&1)total += arr[j];
			else total2 += arr[j];
			if(total>10007)total-= 10007;
			if(total2>10007)total2 -= 10007;
			tt>>=1;
		}
		if(total == total2){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}
