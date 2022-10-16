#ifndef RACE_H
#define RACE_H
#include <stdio.h>
#include <cstdlib>	//required to rand()
#include <ctime>
#include <string>
#include <cmath>
#include <vector>

#include "RoadSegments.h"
#include "Racers.h"

#pragma once

using namespace std;

class Race
{
	private:
	int numOfSegments;
	Racers* racerList[8];
	
	
	public:	//isRandom 0 = Random, 1 = not Random
	Race(int l)
	{
		numOfSegments = l;
	}
	Race()
	{
		//fmod will help gen a number between 10 and 50
    	numOfSegments = fmod((double)rand(), ((50 + 1) - 10)) + 10;
	}

	void outputTrack(RoadSegments** tr);	
	void outputRacers();
	void assignRacers();
	void outDivider(int i);
	void start();
};
#endif