#include "squarerect.h"
#include <bits/stdc++.h>
using namespace std;

const int mxn = 101;

bool am_i_square(int N, int Q) {
	bool inside[4][4] = {};
	int cnt = 0;
	for(int i = 0;i<4;i++){
		for(int j = 0;j<4;j++){
			inside[i][j] = inside_shape(i*20+20,j+20+20);
			cnt += inside[i][j];
		}
	}
	if(!cnt){
		for(int i = 20;i<=100;i+=20)
	}
}
