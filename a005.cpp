#include <iostream>

using namespace std;
int main(){
    int n;
    cin>>n;
    for(int j = 0;j<n;j++){
        int arr[5];
        for(int i = 0;i<4;i++){
            cin>>arr[i];
            cout<<arr[i]<<' ';
        }
        if(arr[2]%arr[1]!=0||arr[2]/arr[1]!=arr[3]/arr[2]){
            arr[4] = arr[3]+arr[3]-arr[2];
            cout<<arr[4]<<endl;
        }
        else{
            arr[4] = arr[3]*(arr[3]/arr[2]);
            cout<<arr[4]<<endl;
        }
    }
}

