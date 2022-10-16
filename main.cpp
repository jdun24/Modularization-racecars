

using namespace std;

int ask(){
	cout << "Welcome to the Racer Derby!" << endl;
	cout << "Woudl you like to:" << endl;
	cout << "1 - Determine the length of the race" << endl;
	cout << "2 - Run a random race" << endl;
	cout << "-1 - Exit" << endl;
	int answer;
	cin >> answer;
	if(answer == 1){
		return 1;
	}else if(answer == 2){
		return 2;
	}else{
		return -1;
	}
}
int main()
{
	srand(time(0));
	int decision = ask();
	if(decision == 1){
		cout << "What would you like the length to be?";
		int length;
		cin >> length;
		Race rd(length);
		rd.assignRacers();
		rd.start();
	}else if(decision == 2){
		//Default constructor gives a random amount of segments
		Race rd;
		rd.assignRacers();
		rd.start();
	}else{
		//Exit was entered
		
		return 0;
	}
	
 	return 0;
} 