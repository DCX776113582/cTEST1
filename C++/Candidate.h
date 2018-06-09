#ifndef Candidate_h
#define Candidate_h

#include "Person.h"
#include "PersonSet.h"


class Candidate : public Person {

 public:

    virtual void addVoter(Person& aVoter);

    virtual int getAverageAge();

    virtual double getAverageSalary();

    virtual bool operator<(Candidate& aCandidate, Candidate& bCandidate);

    static int candidates();

    virtual void printInfo();


 private:
    PersonSet _voterSet;
    static int _totalNumCandidates;

 public:

    /**
     * @element-type PersonSet
     */
    PersonSet *myPersonSet;
};

#endif // Candidate_h
