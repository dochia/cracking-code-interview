#include <list>
#include <string>
#include <iostream>
using namespace std;

enum AnimalType {D, C};

class Animal
{
      private:
              int mOrder;
              string mName;
      public:
             AnimalType type;
             Animal(string name);
             //Animal(Animal& a);
             void setOrder(int order);
             int getOrder();
             void setName(string name);
             string getName();
             bool isOlderThan(Animal a);
};

class Cat: public Animal
{
    public: 
            Cat(string name) : Animal(name)
            {
                       type = C;
                       cout << "Creating cat with name " << name << ". " << endl; 
            }; 
            //Cat(Animal& a){} : Animal(a) {};
};

class Dog: public Animal
{
      public:
             Dog(string name) : Animal(name)
             {
                        type = D;
                        cout << "Creating dog with name " << name << ". " << endl; 
             };
             //Dog(Animal& a){} : Animal(a){};
};

class AnimalQueue
{
      private:
              list<Dog*> mDogs;
              list<Cat*> mCats;
              int mTimestamp;
      public:
             AnimalQueue();
             void enqueue(Animal* a);
             Animal* dequeueAny();
             Dog* dequeueDogs();
             Cat* dequeueCats();              
};
