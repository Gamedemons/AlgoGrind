#include <iostream>
#include <string>
using std::cout;

static int getMaxDigit(int num);
static int getLength(int num);
static int reverseNumber(int num);
static int getDigitAtIndex(int num, int index);

int main(){
    const int NUMBER = 46793;

    const int MAX_DIGIT = getMaxDigit(NUMBER);
    const int NUMBER_LENGTH = getLength(NUMBER);
    const int REVERSED_NUMBER = reverseNumber(NUMBER);

    for(int i = 0; i < MAX_DIGIT; i++){
        for(int j = 0; j < NUMBER_LENGTH; j++){
            int current_digit = getDigitAtIndex(REVERSED_NUMBER, j);
            int padding = MAX_DIGIT - current_digit - 1;
            if(i <= padding){
                cout << " ";
            }else{
                cout << "*";
            }
        }
        cout << '\n';
    }
    
    return 0;
}

static int getMaxDigit(int num){
    int result = 0;

    while(num>0){
        int last_digit = num % 10;
        if ( last_digit > result ) result = last_digit;
        num = num / 10;
    }

    return result;
}

static int getLength(int num){
    int result = 0;

    while(num>0){
        num = num / 10;
        ++result; 
    }

    return result;
}

static int reverseNumber(int num){
    int result = 0;

    while(num>0){
        int last_digit = num % 10;
        result = (result * 10) + last_digit;
        num = num / 10;
    }

    return result;
}

static int getDigitAtIndex(int num, int index){
    int result = 0;
    for(int i = index; i >= 0; i--){
        result = num % 10;
        num = num / 10;
    }
    return result;
}