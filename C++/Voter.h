#ifndef Voter_h
#define Voter_h

#include "Person.h"


class Voter : public Person {

 public:

    static double voters();

    virtual Person& selectCandidate(PersonSet& candidates);

    virtual void vote(Candidate& aCandidate);

    virtual void printInfo();


 private:
    int _poliingStation;
    static int _totalNumVoters;
};

#endif // Voter_h
