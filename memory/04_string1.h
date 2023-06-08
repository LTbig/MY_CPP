#ifndef STRING1_H_
#define STRING1_H_
#include<iostream>
using std::ostream;
using std::istream;

class String
{
// public:
    // static const int CINLIM = 80;
private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;//can input limit
    // enum Limit{CINLIM = 80};
public:
    //constructor operator methods
    String(const char * s);
    String();
    String(const String &);
    ~String();
    int length() const {return len;}
    //overloaded operator methods
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);
    const char & operator[](int i) const;
    //overloaded operator friends
    friend bool operator<(const String & st, const String & st2);
    friend bool operator>(const String & st1, const String & st2);
    friend bool operator==(const String & st, const String & st2);
    friend ostream & operator<<(ostream & os, const String & st);
    friend istream & operator>>(istream & is, String & st);
    //static function
    static int HowMany();
};

#endif