#include "Race.h"
#include "RoadSegments.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>	//required to rand()
#include <ctime>

using namespace std;

void Race::outputTrack(RoadSegments** tr)
{
	int i;
	cout << "Track: " << endl;
	for(i = 0;i < numOfSegments; i++){
		if(tr[i]->getType() == "Asphalt - "){	//Asphalt segment
			cout << "A";
		}else if(tr[i]->getType() == "Crumbled - "){	//crumbled segment
			cout << "C";
		}else if (tr[i]->getType() == "Dirt - "){	//gravel segment
			cout << "D";
		}else if(tr[i]->getType() == "Gravel - "){	//Dirt segment
			cout << "G";
		}
		if(i != 7){	// So that there isn't a ' - ' sticking out at the end
			cout << " - ";
		}
	}
	cout << endl;
}

void Race::outputRacers()
{
	cout << "Racers: " << endl;
	for(int i = 0;i < 8; i++){
		if(racerList[i]->getId() == 0){	//Street Racer
			cout << racerList[i]->toString();
		}else if(racerList[i]->getId() == 1){	//Steady Racer
			cout << racerList[i]->toString();
		}else if (racerList[i]->getId() == 2){	//Tough Racer
			cout << racerList[i]->toString();
		}
		cout << endl;
	}
}

void Race::assignRacers()
{
	int num;
	
	int i;
	for(i = 0; i < 8; i++){
		num = rand() % 2; //num equals a number 0 to 2
		if(num == 0){	//Street Racer
			//i is to set carNum, same for the next two
			//StreetRacer* sr = new StreetRacer(i);
			racerList[i] = new StreetRacer(i);
		}else if(num == 1){	//Tough Racer
			ToughRacer* tr = new ToughRacer(i);
			racerList[i] = tr;
		}else{	//Steady Racer
			SteadyRacer* stead = new SteadyRacer(i);
			racerList[i] = stead;
			//SteadyRacer* racerList[i] = new SteadyRacer(i);
		}
	}
}

void Race::outDivider(int i)
{
	cout << "############## Update " << i << " ##############" << endl << endl;
}

void Race::start()
{
	RoadSegments** track = new RoadSegments*[numOfSegments];	//allocates appropriate amount of space
	int i, noWinner = 0,n = rand() % 3; // to acquire a number between 0 and 3
	int iterate = 0;
	//To get the first segment
	if(n == 0){	//Asphalt segment
		track[0] = new AsphaltSegment();
	}else if(n == 1){	//crumbled segment
		track[0] = new CrumbledSegment();
	}else if (n == 2){	//gravel segment
		track[0] = new GravelSegment();
	}else{	//Dirt segment
		track[0] = new DirtSegment();
	}
	for(i = 1; i < numOfSegments; i++){
		track[i] = track[i - 1]->generateNeighbor();
	}
	//Race now generated
	
	while(noWinner != 1 && iterate < 200)
	{
		for(int j = 0;j < 8;j++){
			racerList[j]->makeProgress(track[racerList[j]->getSeg()]->getModifier());
			if(racerList[j]->getCurrentProgress() >=  track[racerList[j]->getSeg()]->getLength() && racerList[j]->getSeg() == numOfSegments - 1)
			{	//if current racers prog is >= track seg length AND current racer segment is one below finish line then...
				noWinner = 1;
				racerList[j]->resetProgress();
				racerList[j]->incSeg();
				cout << endl << "The winner is " << racerList[j]-> toString() << "!!!!!" << endl;
				break;
			}
				
			if(racerList[j]->getCurrentProgress() >=  track[racerList[j]->getSeg()]->getLength() && noWinner != 1){
				racerList[j]->resetProgress();
				racerList[j]->incSeg();
			}
		}
		if(noWinner != 1){	//Makes sure more output isnt printed once winner is found
			outDivider(iterate + 1);
			outputTrack(track);
			outputRacers();
		}
		iterate++;
	}
	
	free(track);	//Frees allocated mem
}