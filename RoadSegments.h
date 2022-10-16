#ifndef ROADSEGMENTS_H
#define ROADSEGMENTS_H

//#pragma once
#include <stdio.h>
#include <cstdlib>	//required to rand()
#include <ctime>
#include <string>

#pragma once

using namespace std;

class RoadSegments
{
	protected: 
	int length;
	double modifier;
	string type;
	
	public:
	
	RoadSegments()
	{
		
	}
	
	virtual RoadSegments* generateNeighbor() = 0;
	virtual string toString() = 0;
	int getLength();
	double getModifier();
	string getType();
};

class AsphaltSegment : public RoadSegments
{
	protected:
	
	public:
	
	AsphaltSegment() : RoadSegments()
	{
		this->type = "Asphalt - ";
		this->modifier = 1;
	}
	
	RoadSegments* generateNeighbor();
	string toString();
};

class CrumbledSegment : public RoadSegments
{
	protected:
	
	
	public:
	CrumbledSegment() : RoadSegments()
	{
		this->length = (rand() % 10) + 40;
		this->type  = "Crumbled - ";
		this->modifier = .8;
	}
	
	RoadSegments* generateNeighbor();
	string toString();
};

class DirtSegment : public RoadSegments
{
	protected:
	
	public:
	DirtSegment() : RoadSegments()
	{
		this->length = (rand() % 10) + 40;
		this->type = "Dirt - ";
		this->modifier = .6;
	}
	
	RoadSegments* generateNeighbor();
	string toString();
};

class GravelSegment : public RoadSegments
{
	protected:
	
	public:
	GravelSegment() : RoadSegments()
	{
		this->length = (rand() % 10) + 40;
		this->type = "Gravel - ";
		this->modifier = .3;
	}
	
	RoadSegments* generateNeighbor();
	string toString();
};


#endif