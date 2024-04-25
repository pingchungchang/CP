#include <bits/stdc++.h>
using namespace std;

int main(){
	int ans =0;
	for(int i = 0;i<5;i++){
		for(int j = 0;j<5;j++){
			int k;
			cin>>k;
			if(k != 0){
				ans = abs(i-2)+abs(j-2);
			}
		}
	}
	cout<<ans;
}
