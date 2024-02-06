#ifndef PHONE_H
#define PHONE_H
#include<bits/stdc++.h>

using namespace std;

class Phone
{
private :
    int no_of_phones;
    string phone;
    string type; // vodafone - etisalat - orange ... etc

    fstream phon,noph,temp;
    vector<pair<string,string>> vp;
public :

    Phone();
    Phone(const Phone&);
    string check_phone_type(string&);
    void add_phone_details(int);
    void add_extra_phone(string);
    void edit_phone(string);
    void search_();
    void delete_specific_phone(string);
    void delete_all(string);
    void update_no_of_phones(char,string);
    void print(string);
    virtual ~Phone();

    char _no_of_phones[3];
    char _id[5];
    char _phone[13];
    char _type[20];

protected :
};

#endif // PHONE_H
