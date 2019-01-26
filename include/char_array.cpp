#include "char_array.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//Position of '\0' = length(array) + 1
//Number of elements in array
int length(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

//Displays char array
void print(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        cout<<s[i];
        i++;
    }

}
//Makes a copy of the source array
//into the destination array
void copy(char source[], char dest[]) {
    int i =0;
    while (source[i] != '\0') {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
}

void concatenate(char s1[], char s2[]) {
    int i = 0;
    int x = length(s2);
    while (i < length(s1)) {
        s2[x] = s1[i];
        i++;
        x++;
    }
    s2[x] = '\0';
}

//Clear elements in the array
void clear(char s[]) {

}

//Reverse the positions of elements in source array
//stores the reversed in destination arr
//to avoid confusion
//Ex. 1234 (source) --> 4321 (dest) | length = 4
void reverse(char source[], char dest[]) {
    int i = length(source)-1;  // end of source   (3=4-1)
    int x = 0;                 // start of source (0)
    while (i >= 0) {           // (3 >= 0), loop
        dest[i] = source[x];   // dest[3] = source[0]
        i--;                   // i = 2
        x++;                   // x = 1
    }
    dest[x] = '\0';
}
//Swaps 2 elements: ab --> ba
void swap(char& a, char& b) {
    char temp;
    temp = a;
    a = b;
    b = temp;
}
// '0' = 48
//Converts character into integer
int char_2_int(char ch) {  // '7' ->  7
    int i = 0;
    switch (toupper(ch)) {
    case 'A':
        i = 10;
        break;
    case 'B':
        i = 11;
        break;
    case 'C':
        i = 12;
        break;
    case 'D':
        i = 13;
        break;
    case 'E':
        i = 14;
        break;
    case 'F':
        i = 15;
        break;
    default:
        i = ch - '0';
        break;
    }
    return i;
}
//Converts integer into character
char int_2_char(int i)  {   //  7  -> '7'
    char ch;
    switch (i) {
    case 10:
        ch = 'A';
        break;
    case 11:
        ch = 'B';
        break;
    case 12:
        ch = 'C';
        break;
    case 13:
        ch = 'D';
        break;
    case 14:
        ch = 'E';
        break;
    case 15:
        ch = 'F';
        break;
    default:
        ch = i + '0';
        break;
    }
    return ch;
}
//Includes a filler, i.e. '0' that is used as
//a place holder. Ex: 110 = 00110 // 2 = 2.00
//# of fills depends on length of array
void pad(char source[], int n, char filler) {
    // usually...n = max[length(num1,num2)]
    int i = length(source);
    while (i < n) {
        source[i] = filler; //filler = '0'
        i++;
    }
    source[i] = '\0';
}

//Input 2 numbers, output sum of those numbers
//Bases: 2 (binary), 10 (decimal), 16 (hexadecimal)
void add(char num1[], char num2[], char sum[], int base)
{
    char temp1[MAX], temp2[MAX], temp_sum[MAX+1]; //dest arrays to store low-level functions
    int Length = max(length(num1),length(num2))+1;  //determine which array is longer
    reverse(num1, temp1);
    reverse(num2, temp2);
    pad(temp1, Length, '0');
    pad(temp2, Length, '0');

    int i = 0, carry = 0;
    while (i < Length)
    {
        int s1 = char_2_int(temp1[i]); //convert num1 -> int
        int s2 = char_2_int(temp2[i]); //convert num2 -> int
        int rem = s1 + s2 + carry;     //add
        carry = rem / base;
        rem = rem % base;
        char value = int_2_char(rem);
        temp_sum[i] = value;
        i++;
    }
    if (temp_sum[i-1] == '0')
        i--;
    temp1[i] = '\0';
    temp2[i] = '\0';
    temp_sum[i] = '\0';
    reverse(temp1,num1);
    reverse(temp2,num2);
    reverse(temp_sum,sum);
}

void trim (char s[]) {
    int x = length(s);
    while (s[x-1] == '0') {
        x--;
    }
    s[x] = '\0';
}




