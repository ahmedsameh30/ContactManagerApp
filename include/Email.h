#ifndef EMAIL_H
#define EMAIL_H
#include<bits/stdc++.h>

using namespace std;

class Email
{
private :
    int no_of_mails;
    string email;
    string type; // vodafone - etisalat - orange ... etc

    fstream mail,nom,temp;
    vector<pair<string,string>> vp;

    // for reading from file..
    char _no_of_mails[3];
    char _id[5];
    char _mail[60];
    char _type[30];
public :
    Email();
    Email(const Email&);
    string check_mail_type(string&);
    void add_mail(int);
    void add_extra_mail(string);
    void edit_mail(string);
    void delete_specific_mail(string);
    void delete_all(string);
    void update_no_of_phones(char,string);
    void print(string);
    virtual ~Email();

    protected:
};

#endif // EMAIL_H
