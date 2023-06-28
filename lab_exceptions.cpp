#include "lab_exceptions.h"

const char* incorrect_date_input::what() throw()
{
    return "Incorrect input of date\n";
}

const char* empty_array::what() throw()
{
    return "Array is empty\n";
}
