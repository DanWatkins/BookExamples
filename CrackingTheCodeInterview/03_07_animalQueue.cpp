// Created 2014.12.21 by Daniel L. Watkins
// This file is in the public domain

#include <list>
#include <iostream>

using namespace std;

struct Animal
{
	int index;
};

struct Dog : public Animal
{
	Dog() : Animal()
	{
		std::cout << "Created a Dog" << std::endl;
	}
};

struct Cat : public Animal
{
	Cat() : Animal()
	{
		std::cout << "Created a Cat" << std::endl;
	}
};


class AnimalQueue
{
public:
	AnimalQueue() :
		mIndex(0)
	{
	}
	
	
	void enqueue(Animal *animal)
	{
		if (Dog *dog = dynamic_cast<Dog*>(animal))
		{
			dog.index = mIndex++;
			mDogList.push_back(dog);
		}
		else if (Cat *cat = dynamic_cast<Cat*>(animal))
		{
			cat.index = mIndex++;
			mCatList.push_back(cat);
		}
	}
	
	
	Animal* dequeueAny()
	{
		if (mDogList.empty())
			return mCatList.front();
		else if (mCatList.empty())
			return mDogList.front();
			
		Dog *dog = mDogList.front();
		Cat *cat = mCatList.front();
		
		return dog.index < cat.index ? dog : cat;
	}
	
	
	Dog* dequeueDog()
	{
		Dog *dog = mDogList.front();
		mDogList.erase(mDogList.begin());
		
		return dog;
	}
	
	
	Cat* dequeueCat()
	{
		Cat *cat = mCatList.front();
		mCatList.erase(mCatList.begin());
		
		return mCat;
	}
	
private:
	std::list<Dog*> mDogList;
	std::list<Cat*> mCatList;
	int mIndex;
};


#define myAssert(expression) if (!(expression)) \
								std::cout << "Problem at line " << __LINE__ << std::endl

int main()
{
	
}