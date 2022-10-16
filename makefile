OBJS = RoadSegments.o Racers.o Race.o
CPPS = main.cpp RoadSegments.cpp Racers.cpp Race.cpp

#_______________ROAD SEGMENT FILES_____________
ROADSEGCPP = RoadSegments.h RoadSegments.cpp

#_______________RACER FILES____________________
RACERSCPP = Racers.h Racers.cpp

RACECPP = Race.h Race.cpp

DEBUG = -g
CFLAGS = -Wall -c 
LFLAGS = -Wall $(DEBUG)
WALL = -Wall

exe: $(OBJS)
	g++ $(WALL) $(CPPS) -o exe
	
RoadSegments.o: $(ROADSEGCPP)
	g++ $(CFLAGS) RoadSegments.cpp

Racers.o: $(RACERSCPP)
	g++ $(CFLAGS) Racers.cpp

Race.o: $(RACECPP)
	g++ $(CFLAGS) Race.cpp

clean:
	\rm *.o *~ exe