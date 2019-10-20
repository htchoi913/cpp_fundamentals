#include <iostream>
#include <cstring>

using namespace std;

int lastIndexOf(const char* inString, char target);
int replace(char* inString, char target, char replacementChar);
int numLetters(const char* inString);
bool isPalindrome(const char* inString);
void reverse(char* inString);
void toupper(char* inString);


// This function completes the tasks required in Assignment 6.1
int main()
{
    char str1[] = "Hello World";
    char str2[] = "C++ is fun!";
    char str3[] = "aBba";
    char str4[] = "Henry";
    char str5[] = "Choi23";
    char str6[] = "NeverOddOrEven";
    char str7[] = "To be or not to be, that is the question.";
    char str8[] = "She sells sea shells by the sea shore";
    
    cout << "This part counts indexes:" <<  endl;
    cout << lastIndexOf(str1, 'o') << endl;
    cout << lastIndexOf(str2, '+') << endl;
    cout << lastIndexOf(str3, 'a') << endl;
    
    reverse(str4);
    reverse(str5);
    
    cout << "This part reverses strings:" << endl;
    cout << str4 << endl;
    cout << str5 << endl;
 
    cout << "This part replaces string characters:" << endl;
    cout << replace(str7, 'o', '0') << endl;
    cout << str7 << endl;
    cout << replace(str8, 'e', '3') << endl;
    cout << str8 << endl;
    
    cout << "This part checks for palindromes:" << endl;
    cout << isPalindrome(str3) << endl;
    cout << isPalindrome(str4) << endl;
    cout << isPalindrome(str6) << endl;
    
    cout << "This part converts c-strings to all uppercase:" << endl;
    toupper(str6);
    toupper(str4);
    toupper(str2);
    cout << str6 << endl;
    cout << str4 << endl;
    cout << str2 << endl;
 
    cout << "This part counts numbers of letters in c-string:" << endl;
    cout << numLetters(str3) << endl;
    cout << numLetters(str5) << endl;
    cout << numLetters(str2) << endl;
    
}






// This function counts the number of letters in a string
int numLetters(const char* inString)
{
    int index = 0;
    int count = 0;
    
    while (inString[index] != '\0') {
        if (isalpha(inString[index])) {
            count++;
        }
        index++;
    }

    return count;
}






// This function turns all the c-string characters to uppercase
void toupper(char* inString) {
    int index = 0;
    
    while (inString[index] != '\0') {
        inString[index] = toupper(inString[index]);
        index++;
    }
}






// This returns true if the c-string is a palindrome
bool isPalindrome(const char* inString)
{
    int front;
    int back;
    
    back = strlen(inString) - 1;
    for (front = 0; front < strlen(inString)/2; front++) {
        if (tolower(inString[front]) != tolower(inString[back])) {
            return false;
        }
        back--;
    }
    
    return true;
}






// This replaces a c-string's character based on the target
// and replacement char arguments
int replace(char* inString, char target, char replacementChar) {
    
    int index = 0;
    int replacementCount = 0;
    
    while (inString[index] != '\0') {
        if (inString[index] == target) {
            inString[index] = replacementChar;
            replacementCount++;
        }
        index++;
    }
    
    return replacementCount;
}






// This returns the last index value of a target character in a c-string
int lastIndexOf(const char* inString, char target)
{
    
    int index = -1;
    int count = 0;
    
    while (inString[count] != '\0') {
        if (inString[count] == target) {
            index = count;
        }
        count++;
    }
    
    return index;
}






// This function reverses the order of a c-string
void reverse(char* inString)
{
    int front;
    int back;
    
    back = strlen(inString) - 1;
    
    for (front = 0; front < strlen(inString)/2; front++) {
        swap(inString[front], inString[back]);
        back--;
    }
}


/* Program output:
 
 This part counts indexes:
 7
 2
 3
 This part reverses strings:
 yrneH
 32iohC
 This part replaces string characters:
 5
 T0 be 0r n0t t0 be, that is the questi0n.
 7
 Sh3 s3lls s3a sh3lls by th3 s3a shor3
 This part checks for palindromes:
 1
 0
 1
 This part converts c-strings to all uppercase:
 NEVERODDOREVEN
 YRNEH
 C++ IS FUN!
 This part counts numbers of letters in c-string:
 4
 4
 6
 Program ended with exit code: 0
 
 */
