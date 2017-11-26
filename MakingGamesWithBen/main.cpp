#include<iostream>
#include<random>
#include<ctime>

using namespace std;

// Function Declarations
int getNumHumans();
int getNumSkeletons();
void simulateBattle(int &numHumans, int &numSkeletons);
void printResults(int numHumans, int numSkeletons, int startHumans, int startSkeletons);

int main() {
	int startHumans;
	int startSkeletons;

	int numSkeletons;
	int numHumans;

	cout << "*** Skeletons Vs. Humans! ***\n\n";

	numHumans = getNumHumans();
	startHumans = numHumans;

	numSkeletons = getNumSkeletons();
	startSkeletons = numSkeletons;

	simulateBattle(numHumans, numSkeletons);

	printResults(numHumans, numSkeletons, startHumans, startSkeletons);

	system("PAUSE");
	return 0;
}

int getNumHumans() {
	// Get the number of Humans
	int numHumans;
	cout << "Enter the number of Humans: ";
	cin >> numHumans;

	return numHumans;
}

int getNumSkeletons() {
	// Get the number of Skeletons
	int numSkeletons;
	cout << "Enter the number of Skeletons: ";
	cin >> numSkeletons;

	return numSkeletons;
}

void printResults(int numHumans, int numSkeletons, int startHumans, int startSkeletons) {

	cout << "\nBattle is over!\n";

	if (numHumans > 0) {
		cout << "Humans won!\n";
		cout << "There are " << numHumans << " humans left!\n\n";
	} else {
		cout << "Skeletons won!\n";
		cout << "There are " << numSkeletons << " skeletons left!\n\n";
	}
	// KILL COUNTER!!!
	cout << startHumans - numHumans << " humans and " << startSkeletons - numSkeletons << " skeletons lost their lives!\n";
}

void simulateBattle(int &numHumans, int &numSkeletons) {
	static default_random_engine randomEngine(time(NULL));
	uniform_real_distribution<float> attack(0.0f, 1.0f);

	// Human Properties
	float humanAttack = 0.6f;
	float humanHealth = 250.0f;
	float humanDamage = 200.0f;
	float currentHumanHealth = humanHealth;

	//Skeleton Properties
	float skeletonAttack = 0.4f;
	float skeletonHealth = 50.0f;
	float skeletonDamage = 40.0f;
	float currentSkeletonHealth = skeletonHealth;

	float attackResult;

	char turn = 'H';

	cout << " \nBeggining combat!\n\n";

	while ((numHumans > 0) && (numSkeletons > 0)) {

		// Get our attack result
		attackResult = attack(randomEngine);

		if (turn == 'H') {
			// Check if attack was successful
			if (attackResult <= humanAttack) {
				currentSkeletonHealth -= humanDamage;
				if (currentSkeletonHealth < 0) {
					numSkeletons--;
					currentSkeletonHealth = skeletonHealth;
				}
			}
			turn = 'S';

		} else {

			if (attackResult <= skeletonAttack) {
				currentHumanHealth -= skeletonDamage;
				if (currentHumanHealth < 0) {
					numHumans--;
					currentHumanHealth = humanHealth;
				}
			}

			turn = 'H';
		}

	}
}