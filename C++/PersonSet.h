#ifndef PersonSet_h
#define PersonSet_h

class Person;

class PersonSet {

 public:

    virtual void addElement(Person& person);

    virtual Person* removeElement();

    virtual Person& nextElement();

    virtual void reStore(int index);

    virtual Person* removeElement(int Index);


 private:
    Person** _elements;
    int _size;
    int _capacity;
    int _index;

 public:

    /**
     * @element-type Person
     */
    Person *myPerson;

};

#endif // PersonSet_h
