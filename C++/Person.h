#ifndef Person_h
#define Person_h


class Person {

 public:

    virtual void setAge(int newAge);

    virtual void setSalary(double newSalary);

    virtual void printInfo();


 private:
    string _name;
    int _age;
    int _salary;
    const int _id;
    static int _totalPersons;

};

#endif // Person_h
