#include "trains.h"

Trains::Trains(int number, string dest, string time)
{
    this->number = number;
    this->dest = dest;
    this->time = time;
}

bool Trains::operator >(const Trains& other)
{
    int first_h, first_m;
    int second_h, second_m;
    char ch;

    istringstream ios(this->time);
    ios >> first_h >> ch >> first_m;
    istringstream ios_2(other.time);
    ios_2 >> second_h >> ch >> second_m;

    return (first_h*60 + first_m) > (second_h*60 + second_m);
}

bool Trains::operator <(const Trains& other)
{
    int first_h, first_m;
    int second_h, second_m;
    char ch;

    istringstream ios(this->time);
    ios >> first_h >> ch >> first_m;
    istringstream ios_2(other.time);
    ios_2 >> second_h >> ch >> second_m;

    return (first_h*60 + first_m) < (second_h*60 + second_m);
}

string Trains::get_time(){
    return time;
}

int Trains::get_number(){
    return number;
}

string Trains::get_dest(){
    return dest;
}
