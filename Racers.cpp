#include "Racers.h"
#include <iostream>
using namespace std;

int Racers::getCarNum()
{
 	return carNum;
} 

void Racers::setCarNum(int n)
{
	carNum = n;
}

double Racers::getSpeed()
{
	return speed;
}

double Racers::getCurrentProgress()
{
	return currentProgress;
}

void Racers::resetProgress()
{
	currentProgress = 0;
}

int Racers::getId()
{
	return id;
}

int Racers::getSeg()
{
	return segment;
}

void Racers::incSeg()
{
	segment = segment + 1;
}

//__________STREET RACERS____________

void StreetRacer::makeProgress(double mod)
{
	this->currentProgress += (speed * mod) + .5;
}

string StreetRacer::toString()
{
	string finalize = "Racer #" + to_string(this->carNum);
	finalize.append(" Street Racer - ");
	finalize.append(to_string(currentProgress));
	finalize.append(" Units into Segment #");
	finalize.append(to_string(segment));
	return finalize; 
}

//__________STEADY RACERS____________

void SteadyRacer::makeProgress(double mod)
{
	//Steady Racer Ignores all Modifiers
	this->currentProgress += speed;
}

string SteadyRacer::toString()
{
	string finalize = "Racer #" + to_string(this->carNum);
	finalize.append(" Steady Racer - ");
	finalize.append(to_string(currentProgress));
	finalize.append(" Units into Segment #");
	finalize.append(to_string(segment));
	return finalize; 
}

//__________TOUGH RACERS____________

void ToughRacer::makeProgress(double mod)
{
	//stuff happens
	double bonusSpeed = 5 * (1.0 - mod);
	this->currentProgress += speed + bonusSpeed;
}

string ToughRacer::toString()
{
	string finalize = "Racer #" + to_string(this->carNum);
	finalize.append(" Tough Racer - ");
	finalize.append(to_string(currentProgress));
	finalize.append(" Units into Segment #");
	finalize.append(to_string(segment));
	return finalize; 
}