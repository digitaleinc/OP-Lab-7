#ifndef TRAINS_H
#define TRAINS_H
#define SIZE 256
#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

class Trains
{
private:
    int number;
    string dest;
    string time;
public:
    Trains() = default;
    Trains(int, string, string);
    bool operator>(const Trains&);
    bool operator<(const Trains&);
    int get_number();
    string get_dest();
    string get_time();
};
#endif // TRAINS_H
