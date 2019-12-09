#include "Magazine.h"

Magazine::Magazine()
{

}

Magazine::Magazine(string name, double price, bool type)
{
	this->name = name;
	this->price = price;
	this->type = type;
}


Magazine::~Magazine()
{
}
