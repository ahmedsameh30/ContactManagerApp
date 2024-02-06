#ifndef CONTACT_H
#define CONTACT_H
#include "Users.h"
#include<vector>

using namespace std;

class Contact
{
private :
    Users u;
public :
    Contact();
    static int charArr_to_int(string);
    void add_contact();
    void edit_contact();
    void search_for_contact();
    void delete_contact();
    void how_many_contacts();
    void print_all_contacts();
    virtual ~Contact();

    protected:
};

#endif // CONTACT_H
