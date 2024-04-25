#include "lib1087.h"
#include<iostream>
#include <cassert>
using namespace std;


/*
void Initialize(){}

void Take_Stone(int r,int c,int* p,int* n){
	cout<<r<<' '<<c<<endl;
	int a,b;
	cin>>a>>b;
	*p = a,*n = b;
	return;
}

*/

int main(){
	Initialize();
	int arr[] = {10,15,20};
	while(true){
		int sum = 0;
		int pile,num;
		for(auto &i:arr)sum ^= i;
		assert(sum);
		bool flag = false;
		int big = 0,one = 0,z = 0;
		for(auto &i:arr)if(i>1)big++;else if(i == 1)one++;else z++;
		if(big == 1){
			if(one&1){
				int a,b;
				for(int i = 0 ;i<3;i++){
					if(arr[i]>1){
						Take_Stone(i+1,arr[i],&a,&b);
						arr[i] = 0;
						arr[a-1] -= b;
					}
				}
			}
			else{
				int a,b;
				for(int i = 0;i<3;i++){
					if(arr[i]>1){
						Take_Stone(i+1,arr[i]-1,&a,&b);
						arr[i] = 1;
						arr[a-1] -= b;
					}
				}
			}
			continue;
		}
		for(int i = 0;i<3;i++){
			for(int j = 0;j<arr[i];j++){
				if(flag)break;
				if((sum^arr[i]^j) == 0){
					flag = true;
					Take_Stone(i+1,arr[i]-j,&pile,&num);
					arr[i] = j;
					//assert(arr[pile-1]>=num);
					arr[pile-1] -= num;
				}
			}
			if(flag)break;
		}
	}
	return 0;
}
