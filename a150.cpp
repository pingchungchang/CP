#include <bits/stdc++.h>
using namespace std;

struct pts{
	double x;
	double y;
//	pts(double a,double b){
//		x = a;
//		y = b;
//	}
//	pts(){
//		x = 0;
//		y = 0;
//	}
};
int main(){
	int n;
	cin>>n;
	pts v[105];
	for(int i = 0;i<n;i++){
		cin>>v[i].x>>v[i].y;
	}
	double ans = 0;
	for(int i = 1;i<n;i++){
		ans += v[i-1].x*v[i].y-v[i-1].y*v[i].x;
	}
	ans += v[n-1].x*v[0].y-v[n-1].y*v[0].x;
	ans /= 2.0;
	cout<<fixed<<setprecision(2)<<abs(ans);
} 
