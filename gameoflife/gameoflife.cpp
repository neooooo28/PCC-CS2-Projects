#include "gameoflife.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

//initialize 2D array
void init_2d(int arr_2d[][MAX]) {
    for (int row=0; row<MAX; row++) {
        for (int col=0; col<MAX; col++) {
            arr_2d[row][col] = 0;
        }
    }
}

//2. initial_config (2d)
void init_config (int arr_2d[][MAX]) {
    //8x8 Array
    arr_2d[1][2] = 1;
    arr_2d[3][1] = 1;
    arr_2d[3][2] = 1;
    arr_2d[3][3] = 1;
    arr_2d[2][3] = 1;


}
//Returns a random number between range(low, high)
int random_int(int low, int high) {
    int r = rand()%(high-low+1)+low;
    return r;
}
void random_fill(int arr_2d[][MAX]) {
    for (int k=0; k<20; k++) {
        int i = random_int(1,MAX-1);
        int j = random_int(1,MAX-1);
        arr_2d[i][j] = 1;
    }
}

//3. step (2d)
void step(int arr_2d[][MAX]) {
    int temp[MAX][MAX];
    init_2d(temp);
    for (int row = 1; row<MAX-1; row++)
    {
        for (int col = 1; col<MAX-1; col++)
        {
            fill_margins(arr_2d);
            int value = count_neighbors(arr_2d, row, col);
            if (value < 2 || value > 3)   //DIE
                temp[row][col] = 0;
            else if (value == 2)          //STAY
                temp[row][col] = arr_2d[row][col];
            else if (value == 3)         //LIVE
                temp[row][col] = 1;

        }
    }
    copy_2d(temp,arr_2d);
}

//int count_neightbors (2d, row, col)
//counts immediate 3x3, max=9
int count_neighbors(int arr_2d[][MAX], int i, int j) {
    int count = 0;
    for (int row = i-1; row <= i+1; row++) {
        for (int col = j-1; col <= j+1; col++) {
            if (arr_2d[row][col] == 1) {
                count++;
            }
        }
    }
    count = count - arr_2d[i][j];
    return count;
}
void fill_margins(int arr_2d[][MAX]) {
    for (int row = 0; row<MAX; row++) {
        arr_2d[row][0] = arr_2d[row][MAX-2];
        arr_2d[row][MAX-1] = arr_2d[row][1];
    }
    for (int col = 0; col<MAX; col++) {
        arr_2d[0][col] = arr_2d[MAX-2][col];
        arr_2d[MAX-1][col] = arr_2d[1][col];
    }
}

//Copy (source, destination) [V]
void copy_2d(int source[][MAX], int dest[][MAX]) {
    for (int row=0; row<MAX; row++) {
        for (int col=0; col<MAX; col++) {
            dest[row][col] = source[row][col];
        }
    }
}

//Print 2D Array [V]
void print_2d(int arr_2d[][MAX]) {
    for (int row=1; row<MAX-1; row++) {
        for (int col=1; col<MAX-1; col++) {
            if (arr_2d[row][col] == 0)
                cout<<setw(2)<<" ";
            else
                cout<<setw(2)<<arr_2d[row][col];
        }
        cout<<endl;
    }
}
//========================================================
void WriteIntsToFile() {
    ofstream outStream;
    outStream.open("Sample.txt");
    if (outStream.fail()) {
        cout<<"Fail to Write";
        exit(0);
    }
    for (int i=0; i<20; i++) {
        outStream<<setw(4)<<i;
    }
    outStream.close();
    cout<<endl<<"s a m p l e"<<endl;
}

void ReadIntsFromFile() {
    cout<<"Read Ints from File: "<<endl;
    ifstream inStream;
    inStream.open("file2.txt"); //Open a file, filename.file
    if (inStream.fail()) {
        cout<<"Fail to Read"<<endl;
        exit(0);
    }
    cout<<endl<<"--begin--"<<endl;

    int num;
    inStream>>num; //use a for loop instead of this

    while (!inStream.eof()) { //end of file marker
        cout<<setw(4)<<num;
        inStream >> num;
    }
    cout<<endl<<"--end--"<<endl;
    inStream.close();
}
//Save
void WriteIntArray(char fileName[], int arr_2d[][MAX]) {
    ofstream outFile;
    outFile.open(fileName);
    if (outFile.fail()) {
        cout<<"Can't open output file."<<endl;
        exit(0);
    }
    for (int r=0; r<MAX; r++) {
        for (int c=0; c<MAX; c++) {
            outFile<<arr_2d[r][c]<<' ';
        }
        outFile<<endl;
    }
    outFile.close();
}
//Load
void ReadIntArray(char fileName[], int arr_2d[][MAX]) {
    ifstream inFile;
    inFile.open(fileName);
    if (inFile.fail()) {
        cout<<"Can't open input file."<<endl;
        exit(0);
    }
    for (int r=0; r<MAX; r++) {
        for (int c=0; c<MAX; c++) {
            inFile>>arr_2d[r][c];
        }
    }
    inFile.close();
}

void PrintIntArray(int arr_2d[][MAX], int size) {
    for (int r=0; r<size; r++) {
        for (int c=0; c<size; c++) {
            cout<<arr_2d[r][c]<<" ";
        }
        cout<<endl;
    }
}

//bool file_exists(char file_name[]) { //check if the file exists

//}


