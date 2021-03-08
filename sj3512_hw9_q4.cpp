#include <iostream>

using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
int main(){
    int arrSize;
    cout<<"Enter the size of the array: "<<endl;
    cin>>arrSize;

    int userArr[arrSize];
    cout<<"Enter numbers for the array: "<<endl;
    for(int i = 0; i< arrSize; i++){
        cin>>userArr[i];
    }

    oddsKeepEvensFlip(userArr, arrSize);
    printArray(userArr, arrSize);

    return 0;
}


void oddsKeepEvensFlip(int arr[], int arrSize){
        int arrTemp[arrSize];
        int count = 0;
        for (int i = 0; i < arrSize; i++) {
            if (arr[i] % 2 == 1){
                arrTemp[count++] = arr[i];
            }
        }
        for (int i = arrSize - 1; i >= 0; i--) {
            if (arr[i] % 2 == 0){
                arrTemp[count++] = arr[i];
            }
        }
        for (int i = 0; i < arrSize; i++) {
            arr[i] = arrTemp[i];
        }
}


void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}