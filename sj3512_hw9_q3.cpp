#include <iostream>
#include <string>

using namespace std;
void printArray(int* arr, int arraySize);
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main() {
    int outPosArrNum1Size;
    int arrSize;
    cout<<"Enter the size of the array: "<<endl;
    cin>>arrSize;

    int userArr[arrSize];
    cout<<"Enter numbers for the array: "<<endl;
    for(int i = 0; i< arrSize; i++){
        cin>>userArr[i];
    }

    //part A
    cout<<"Part A"<<endl;
    int* posNum1;
    posNum1 = getPosNums1(userArr, arrSize, outPosArrNum1Size);
    cout<<"getPosNums1 new address: "<<posNum1<<" and new size is: "<<outPosArrNum1Size<<endl;
    printArray(posNum1, outPosArrNum1Size);
    cout<<endl;

    //part B
    cout<<"Part B"<<endl;
    int* outPosArrSizePtr = &outPosArrNum1Size;
    int* posNum2;
    posNum2 =  getPosNums2(userArr,arrSize,outPosArrSizePtr);
    cout<<"getPosNums2 new address: "<<posNum2<<" and new size is: "<<*outPosArrSizePtr<<endl;
    printArray(posNum2, *outPosArrSizePtr);
    cout<<endl;

    //part C
    cout<<"Part C"<<endl;
    int* outPosArr;
    int posNum3NewSize;
    getPosNums3(userArr, arrSize, outPosArr, posNum3NewSize);
    cout<<"getPosNums3 new address: "<<outPosArr<<" and new size is: "<<posNum3NewSize<<endl;
    printArray(outPosArr, posNum3NewSize);
    cout<<endl;

    //part D
    cout<<"Part D"<<endl;
    getPosNums4(userArr, arrSize, &posNum2, outPosArrSizePtr);
    cout<<"getPosNums4 new address: "<<posNum2<<" and new size is: "<<*outPosArrSizePtr<<endl;
    printArray(posNum2, *outPosArrSizePtr);
    cout<<endl;

    delete [] posNum1;
    delete [] outPosArr;
    delete [] posNum2;

    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    int* newPositiveArr = new int [arrSize];
    int counter = 0;
    int i;
    for(i = 0; i < arrSize; i++){
        if(arr[i] > 0){
            newPositiveArr[counter] = arr[i];
            counter++;
        }
    }
    outPosArrSize = counter;
    return newPositiveArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr){
    int* newArr = new int[(*outPosArrSizePtr)];
    int counter = 0;
    for(int i = 0; i < arrSize; i++){
        if(arr[i] > 0 ){
            newArr[counter] = arr[i];
            counter++;
        }
    }
    return newArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    outPosArr = getPosNums1(arr, arrSize, outPosArrSize);
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    *outPosArrPtr = new int[*outPosArrSizePtr];
    int newArrPos = 0;
    int i;
    for(i = 0; i < arrSize; i++){
        if(arr[i] > 0){
            (*outPosArrPtr)[newArrPos] = arr[i];
            newArrPos++;
        }
    }

}

void printArray(int* arr, int arraySize){
    cout<<"Positive values: ";
    int i;
    for(i = 0; i < arraySize; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
