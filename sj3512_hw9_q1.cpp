#include <iostream>
#include <string>
const int NUMBER_OF_LETTERS_IN_ALPHABET = 26;
using namespace std;

int numOfWords(string str);
void analyzeLetters(string str);
int main() {
    cout<<"Please enter a line of text"<<endl;
    string userInput;
    getline(cin, userInput);
    cout<<numOfWords(userInput)<<"\t"<<"words"<<endl;
    analyzeLetters(userInput);

    return 0;
}

int numOfWords(string str){
    int i;
    int counter = 1;
    for(i = 0; i < str.length(); i++){
        if(str[i] == ' '){
            counter++;
        }
    }
    return counter;
}

void analyzeLetters(string str){
    int letters[NUMBER_OF_LETTERS_IN_ALPHABET] = {};
    int i;
    for(i = 0; i < str.length(); i++){
        if(str[i] >= 'a' && str[i] <= 'z' && str[i] != ' '){
            letters[str[i] - 'a'] = letters[str[i] - 'a'] + 1;
        }
        if(str[i] >= 'A' && str[i] <= 'Z' && str[i] != ' '){
            letters[str[i] - 'A'] =  letters[str[i] - 'A'] + 1;
        }
    }

    for(i = 0; i < NUMBER_OF_LETTERS_IN_ALPHABET; i++){
        if(letters[i] > 0){
            cout<<letters[i]<<"\t"<<(char)(i + 'a')<<endl;
        }
    }
}

