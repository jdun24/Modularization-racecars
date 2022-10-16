#ifndef RACERS_H
#define RACERS_H
#include <stdio.h>
#include <cstdlib>	//required to rand()
#include <ctime>
#include <string>
#include <cmath>

#pragma once

using namespace std;

class Racers
{
 	protected:
	int carNum;
	double speed;
	double currentProgress;
	int id; //0 = Street Racer 1 = Steady Racer 2 = Tough Racer
	int segment;
 	public:
 	Racers(){
	}
	virtual string toString() = 0;
 	int getCarNum();
	void setCarNum(int n);
	double getSpeed();
	double getCurrentProgress();
	void resetProgress();
	virtual void makeProgress(double mod) = 0;
	int getId();
	int getSeg();
	void incSeg();
}; 

class StreetRacer : public Racers
{	
	public:
	StreetRacer(int i) : Racers()
	{
		//To Obtain a random double from 5.5 to 7.5
    	double num = fmod((double)rand(), ((7.5 + 1) - 5.5)) + 5.5;
		this->speed = num;
		carNum = i;	//Works in tandem with the forLoop inside of Race::assignRacer
		id = 0;
		segment = 0;
		currentProgress = 0;
	}
	
	void makeProgress(double mod);
	string toString();
};

class SteadyRacer : public Racers
{
	public:
	SteadyRacer(int i) : Racers()
	{
		//To obtain a random double from 3 to 4
		double num = fmod((double)rand(), ((4 + 1) - 3)) + 3;
		this->speed = num;
		carNum = i;	//Works in tandem with the forLoop inside of Race::assignRacer
		id = 1;
		segment = 0;
		currentProgress = 0;
	}
	void makeProgress(double mod);
	string toString();
};

class ToughRacer : public Racers
{
	public:
	ToughRacer(int i) : Racers()
	{
		//To obtain a random number from 2 to 3
    	double num = fmod((double)rand(), ((3 + 1) - 2)) + 2;;
		this->speed = num;
		carNum = i;	//Works in tandem with the forLoop inside of Race::assignRacer
		id = 2;
		segment = 0;
		currentProgress = 0;
	}
	void makeProgress(double mod);
	string toString();
};

#endif