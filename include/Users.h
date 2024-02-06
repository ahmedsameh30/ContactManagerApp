#ifndef USERS_H
#define USERS_H
#include<bits/stdc++.h>
#include "Phone.h"
#include "Email.h"

using namespace std;

class Users
{
private :
    int id;
    string name;
    string gender;
    string city;
    string address;

    Phone p;
    Email e;

    fstream contact,temp;

    // for reading from file..
    char _id[5];
    char _name[50];
    char _gender[8];
    char _city[30];
    char _address[50];
public :
    Users();
    Users(const Users&);
    void _add_contact();
    void add_extra_phon_or_mail(int,string);
    void _edit_contact(string);
    void _search();
    void search_by_name();
    void search_by_contact_id();
    void _delete_contact(string);
    void delete_certain_phone(string);
    void delete_certain_mail(string);
    void display_all_contacts();
    int no_of_contacts();
    virtual ~Users();

protected :
};

#endif // USERS_H
