#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int mid = n/3;
	for(int i = -5;i<=5;i++){
		for(int j = -5;j<=5;j++){
			for(int k = -5;k<=5;k++){
				int a = mid+i,b = mid+j,c = mid+k;
				if(a<=0||b<=0||c<=0)continue;
				if(a+b+c == n&&a%3 != 0&&b%3 != 0&&c%3 != 0){
					cout<<a<<' '<<b<<' '<<c;
					return 0;
				}
			}
		}
	}
}
