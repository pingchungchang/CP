#include <bits/stdc++.h>
using namespace std;

int arr[9][9] = {};
bool get(){
	memset(arr,-1,sizeof(arr));
	for(int i = 0;i<9;i++){
		for(int j = 0;j<9;j++){
			cin>>arr[i][j];
		}
	}
	if(arr[8][8] == -1)return false;
	return true;
}
bool cr(int n){
	int v[10] = {};
	for(int i = 0;i<9;i++){
		v[arr[n][i]]=1;
	}
	for(int i = 1;i<=9;i++){
		if(v[i] == 0)return false;
	}
	return true;
}
bool cc(int n){
	int v[10] = {};
	for(int i = 0;i<9;i++){
		v[arr[i][n]] = 1;
	}
	for(int i = 1;i<=9;i++){
		if(v[i] == 0)return false;
	}
	return true;
}
bool cs(int x,int y){
	int v[10] = {0};
	for(int i = 0;i<3;i++){
		for(int j =0;j<3;j++){
			v[arr[i+x][j+y]] = 1;
		}
	}
	for(int i = 1;i<=9;i++){
		if(v[i] == 0)return false;
	}
	return true;
}
int main(){
	while(get()){
		bool done = false;
		for(int i = 0;i<8;i++){
			if(cr(i) == false){
				cout<<"no\n";
				done = true;
				break;
			}
			if(cc(i) == false){
				cout<<"no\n";
				done = true;
				break;
			}
		}
		if(done)continue;
		for(int i = 0;i<3;i++){
			if(done)break;
			for(int j = 0;j<3;j++){
				if(cs(i*3,j*3) == false){
					cout<<"no\n";
					done = true;
					break;
				}
			}
		}
		if(done){
			continue;
		}
		else cout<<"yes\n";
	}
}
