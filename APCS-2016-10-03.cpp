#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    int arr[n];
    for (int i = 0; i < n;i++){
        arr[i] = 1;
    }
    int pointer=0;
    for (int i = 0; i < k;i++){
        for (int j = 0; j < m-1;j++){
            pointer += 1;
            if (pointer >= n){
                pointer -= n;
            }
            if(arr[pointer] !=1){
                while(true){
                    if(arr[pointer]==1) break;
                    else pointer +=1;
                    if(pointer >=n) pointer -=n;
                }
            }
        }
        arr[pointer] = 0;
        pointer += 1;
        if(arr[pointer] !=1){
            while(true){
                if(arr[pointer]==1) break;
                else pointer +=1;
                if(pointer >=n) pointer -=n;
            }
        }
    }
    pointer += 1;
    if(pointer >=n) pointer -=n;
    cout << pointer;
}
// not done!!!!!!!