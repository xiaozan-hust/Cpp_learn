#include <iostream>
#include <string>

using namespace std;

#define MAX 1000

struct Person
{
    string name;
    int age;
    string sex;
    string phonenumber;
    string addr;
};

struct addressBooks
{
    struct Person personArray[MAX];
    int size;
};

void showMeau();
void addPerson(addressBooks *abs);
void showPerson(const addressBooks abs);
int isPerson(const addressBooks abs);
void removePerson(addressBooks *abs);
void searchPerson(const addressBooks abs);
void changePerson(addressBooks *abs);
void deleteallPerson(addressBooks *abs);
