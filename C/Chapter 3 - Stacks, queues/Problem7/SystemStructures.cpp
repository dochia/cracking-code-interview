#include "SystemStructures.h"
#include <iostream>

using namespace std;

Animal::Animal(string name)
{
       cout << "Creating animal with name " << name << ". " << endl; 
       mName = name;               
}

void Animal::setOrder(int order)
{
     mOrder = order;
}

void Animal::setName(string name)
{
     mName = name;
}

string Animal::getName()
{
       return mName;
}

int Animal::getOrder()
{
    return this->mOrder;
}
bool Animal::isOlderThan(Animal a)
{
     return this->mOrder < a.getOrder();
}

AnimalQueue::AnimalQueue()
{
    mTimestamp = 0;             
}
void AnimalQueue::enqueue(Animal* a)
{
    a->setOrder(mTimestamp);
    mTimestamp++;
    if (a->type == 0)
    {
        cout << "Adding a dog with name " << a->getName() << " and timestamp " << a->getOrder() << ". " << endl; 
        mDogs.push_back(static_cast<const Dog*>(a));
    }                         
    else if (a->type == 1)
    {
        cout << "Adding a cat with name " << a->getName() << " and timestamp " << a->getOrder() << ". " << endl;
        mCats.push_back(static_cast<const Cat*>(a));
    }
}

Animal* AnimalQueue::dequeueAny()
{
       if (mDogs.empty())
       {
          return dequeueCats();
       }
       else if (mCats.empty())
       {
          return dequeueDogs();
       }
       Dog* d = mDogs.front();
       Cat* c = mCats.front();
       if (d->isOlderThan(*c))
       {
          return dequeueDogs();
       }
       else
       {
           return dequeueCats();
       }
}

Dog* AnimalQueue::dequeueDogs()
{
    Dog* d = mDogs.front();
    cout << "Removing dog with name " << d->getName() << " and timestamp " << d->getOrder() << ". "<< endl ;
    mDogs.pop_front();
    return d;
}

Cat* AnimalQueue::dequeueCats()
{
    Cat* c = mCats.front();
    cout << "Removing cat with name " << c->getName() << " and timestamp " << c->getOrder() << ". "<< endl ;
    mCats.pop_front();
    return c;
}
