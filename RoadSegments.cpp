#include "RoadSegments.h"
#include <iostream>
using namespace std;

int RoadSegments::getLength()
{
	return length;
}

double RoadSegments::getModifier()
{
	return modifier;
}

string RoadSegments::getType()
{
	return type;
}

//______________ASPHALT SEGMENTS___________________

RoadSegments* AsphaltSegment::generateNeighbor()
{
	int num = rand() % 100; //num equals a number 0 to 100
	
	if(num <= 65){
		return new AsphaltSegment();
	}else if(num > 65 && num <= 85){
		return new CrumbledSegment();
	}else if(num > 85 && num <= 95){
		return new GravelSegment();
	}else if(num > 95){
		return new DirtSegment();
	}
	//Defult will be to return a Dirt Segment, so no warnings will pop up
	return new DirtSegment();
}

string AsphaltSegment::toString()
{
	string finalize = type + to_string(length);
	finalize.append(" Units\n");
	return finalize; 
}

//______________CRUMBLED SEGMENTS__________________

RoadSegments* CrumbledSegment::generateNeighbor()
{
	int num = rand() % 100; //num equals a number 0 to 100
	
	if(num <= 45){
		return new CrumbledSegment();
	}else if(num > 45 && num <= 65){
		return new AsphaltSegment();
	}else if(num > 65 && num <= 90){
		return new GravelSegment();
	}else if(num > 90){
		return new DirtSegment();
	}
	//Defult will be to return a Dirt Segment, so no warnings will pop up
	return new DirtSegment();
}

string CrumbledSegment::toString()
{
	string finalize = type + to_string(length);
	finalize.append(" Units\n");
	return finalize; 
}

//______________DIRT SEGMENTS______________________

RoadSegments* DirtSegment::generateNeighbor()
{
	int num = rand() % 100; //num equals a number 0 to 100
	
	if(num <= 60){
		return new DirtSegment();
	}else if(num > 60 && num <= 95){
		return new GravelSegment();
	}else if(num > 95 && num <= 100){
		return new CrumbledSegment();
	}
	//0% chance of producing an Asphalt Segment, so the logic does not exist for it
	//Defult will be to return a Dirt Segment, so no warnings will pop up
	return new DirtSegment();
}

string DirtSegment::toString()
{
	string finalize = type + to_string(length);
	finalize.append(" Units\n");
	return finalize; 
}

//______________GRAVEL SEGMENTS____________________

RoadSegments* GravelSegment::generateNeighbor()
{
	int num = rand() % 100; //num equals a number 0 to 100
	
	if(num <= 55){
		return new GravelSegment();
	}else if(num > 55 && num <= 85){
		return new DirtSegment();
	}else if(num > 85 && num <= 95){
		return new CrumbledSegment();
	}else if(num > 95){
		return new AsphaltSegment();
	}
	//Defult will be to return a Dirt Segment, so no warnings will pop up
	return new DirtSegment();
}

string GravelSegment::toString()
{
	string finalize = type + to_string(length);
	finalize.append(" Units\n");
	return finalize; 
}