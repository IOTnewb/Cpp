#include "BoundCheck.h"

BoundCheckAccountArray::BoundCheckAccountArray(): count(0){}

Account** BoundCheckAccountArray::Getclient(){	return client;}

void BoundCheckAccountArray::Addcount(){	count++;}

int BoundCheckAccountArray::Getcount(){	return count;}

BoundCheckAccountArray::~BoundCheckAccountArray()
{
	for (int i = 0; i < count; i++)
	{
		delete client[i];
	}
}