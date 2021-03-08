#include <iostream>
#include <string>
const int MAX_LETTERS = 256;
using namespace std;

bool isAnagram(string str1, string str2);


int main() {
    cout<<"Please enter your first line of text"<<endl;
    string userInput1;
    getline(cin, userInput1);
    cout<<"Please enter your second line of text"<<endl;
    string userInput2;
    getline(cin, userInput2);
    if(isAnagram(userInput1, userInput2) == true){
        cout<<userInput1<<" and "<<userInput2<<" are anagrams"<<endl;
    }
    else{
        cout<<userInput1<<" and "<<userInput2<<" are not anagrams"<<endl;
    }

    return 0;
}

bool isAnagram(string str1, string str2){
    int str1Letters[MAX_LETTERS] = {};
    int str2Letters[MAX_LETTERS] = {};

    int i;
    for(i = 0; i < str1.length(); i++){
        if(str1[i] >= 'a' && str1[i] <= 'z' && str1[i] != ' '){
            str1Letters[i] = str1Letters[str1[i] - 'a']++;
        }
        if(str1[i] >= 'A' && str1[i] <= 'Z' && str1[i] != ' '){
            str1Letters[i] = str1Letters[str1[i] - 'A']++;
        }

    }
    for(i = 0; i < str2.length(); i++){
        if(str2[i] >= 'a' && str2[i] <= 'z' && str2[i] != ' '){
            str2Letters[i] = str2Letters[str2[i] - 'a']++;
        }
        if(str2[i] >= 'A' && str2[i] <= 'Z' && str2[i] != ' '){
            str2Letters[i] = str2Letters[str2[i] - 'A']++;
        }
    }
    for(i = 0; i < MAX_LETTERS; i++){
        if(str1Letters[i] != str2Letters[i]){
            return false;
        }
        else{
            return true;
        }
    }

}

