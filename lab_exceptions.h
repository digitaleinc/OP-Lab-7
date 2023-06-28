#ifndef LAB_EXCEPTIONS_H
#define LAB_EXCEPTIONS_H

#include <exception>

class incorrect_date_input : public std::exception{
public:
    const char* what() throw();
};

class empty_array : public std::exception{
public:
    const char* what() throw();
};

#endif // LAB_EXCEPTIONS_H
