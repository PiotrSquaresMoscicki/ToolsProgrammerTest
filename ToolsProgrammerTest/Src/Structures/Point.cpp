#include "Point.hpp"

#include <algorithm>

using namespace TPT;

Point::Point() 
	: Id(IdGenerator) 
{ 
	IdList.push_back(IdGenerator); 
	++IdGenerator;
}

Point::Point(size_t id)
	: Id(id) 
{
	if (std::find(IdList.begin(), IdList.end(), Id) != IdList.end()) 
		throw new std::exception();

	IdList.push_back(IdGenerator);
}

TPT::Point::~Point()
{
	IdList.erase(std::remove(IdList.begin(), IdList.end(), Id), IdList.end());
}