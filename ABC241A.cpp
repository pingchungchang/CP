#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[10];
	for(int i = 0;i<10;i++)cin>>arr[i];
	int now = 0;
	for(int i = 0;i<3;i++){
		now = arr[now];
	}
	cout<<now;
}
