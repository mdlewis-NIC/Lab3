/**
 * @file main.cpp
 * @author Matthew Lewis (mdlewis@student.nic.edu)
 * @brief 
 * @version 0.1
 * @date 2023-01-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<iostream>

class Person 
{
    int age;
    std::string name;
    char gender;
    double height;
    static int totalPerson;  // step 2

    public:

    Person();
    ~Person();
    Person(const Person & obj);
    void setAge(const int &age) { this->age = age;}
    void setName(const std::string &name) {this->name = name;}
    void setGender(const char &gender) {this->gender = gender;}
    void setHeight(const double &height) {this-> height = height;}
    int getAge() const {return this->age;}
    std::string getName() const {return this->name;}
    char getGender() const{return this->gender;}
    double getHeight() const {return this->height;}
    static int getTotalPerson(); // step 2
    friend void setInfo(Person &obj); // step 5 this really made no difference from how I had it before
    bool operator==(const Person &right)
{
     if((this->name == right.name && this->age == right.age) && 
     (this->gender == right.gender && this->height == right.height))
     return true;
     else
     return false;
}


};

int Person::totalPerson = 0;
int Person::getTotalPerson(){return totalPerson;}

Person::Person()
{
    age = 0;
    name = "\0";
    gender = '\0';
    height = 0;
    totalPerson++;   //step 2
}

Person::Person(const Person &obj)  //step 4
{
    this->age = obj.age;
    this->name = obj.name;
    this->gender = obj.gender;
    this->height = obj.height;
    totalPerson++;
}

Person::~Person()
{
    totalPerson--;
}

void setInfo(Person &obj)
{
    std::string tempName;
    int tempAge;
    char tempGender;
    double tempHeight;

    // std::cout << "Please enter the name: ";
    // std::cin >> tempName;
    // std::cin.ignore();
    // obj.setName(tempName);

    // std::cout << "Please enter the age: ";
    // std::cin >> tempAge;
    // std::cin.ignore();
    // obj.setAge(tempAge);

    // std::cout << "Please enter the gender M or F.";
    // std::cin >> tempGender;
    // std::cin.ignore();
    // obj.setGender(tempGender);

    // std::cout << " Please enter the height in inches";
    // std::cin >> tempHeight;
    // std::cin.ignore();
    // obj.setHeight(tempHeight);

    std::cout << "Please enter the name: ";
    std::cin >> tempName;
    std::cin.ignore();
    obj.name = tempName;

    std::cout << "Please enter the age: ";
    std::cin >> tempAge;
    std::cin.ignore();
    obj.setAge(tempAge);

    std::cout << "Please enter the gender M or F.";
    std::cin >> tempGender;
    std::cin.ignore();
    obj.setGender(tempGender);

    std::cout << " Please enter the height in inches";
    std::cin >> tempHeight;
    std::cin.ignore();
    obj.setHeight(tempHeight);
    
}

void printInfo(Person &obj)
{
    std::cout << " Name: " << obj.getName() << std::endl;
    std::cout << " Age: " << obj.getAge() << std::endl;
    std::cout << " Gender: " << obj.getGender() << std::endl;
    std::cout << " Height: " << obj.getHeight() << " inches" << std::endl;
}



int main()
{
    Person p1, p2, p3;

    //step 1
    setInfo(p1);
    setInfo(p2);
    setInfo(p3);
    std::cout << " Number of people created is: " << p3.getTotalPerson() << std::endl;  //step2
    printInfo(p1);
    printInfo(p2);
    printInfo(p3);

    // step 2
    Person *ptrObj;
    ptrObj = new Person;
    setInfo(*ptrObj);
    std::cout << " Number of people created is: " << p3.getTotalPerson() << std::endl;  //step2
    printInfo(*ptrObj);
    delete ptrObj;
    std::cout << " Number of people created is: " << p3.getTotalPerson() << std::endl;  //step2


    // step 3
    Person p4;
    p4 = p1;
    printInfo(p4);
    std::cout << " Number of people created is: " << p3.getTotalPerson() << std::endl;  

    // step 4
    Person p5 = p1;
    printInfo(p5);
    std::cout << " Number of people created is: " << p3.getTotalPerson() << std::endl;  //step3

    // step 6
    if(p1 == p5)
    std::cout << " These are the same. \n";
    else
    std::cout << " Different people. \n";

    if(p1 == p3)
    std::cout << " These are the same. \n";
    else 
    std::cout << " Different people. \n";





    return 0;
}



