#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 40;

void init_2d(int arr_2d[][MAX]);
void init_config(int arr_2d[][MAX]);
int random_int(int low, int high);
void copy_2d(int source[][MAX], int dest[][MAX]);
void step(int arr_2d[][MAX]);
void print_2d(int arr_2d[][MAX]);
void fill_margins(int arr_2d[][MAX]);
int count_neighbors(int arr_2d[][MAX], int row, int col);
void random_fill(int arr_2d[][MAX]);

//=======================================================

void WriteIntsToFile();
void ReadIntsFromFile();
void OutputInts(ostream& outStream);
void WriteIntArray(char fileName[], int arr_2d[][MAX]);
void ReadIntArray(char fileName[], int arr_2d[][MAX]);
void PrintIntArray(int arr_2d[][MAX], int size);
bool file_exists(char file_name[]); //check if the file exists

#endif // GAMEOFLIFE_H
