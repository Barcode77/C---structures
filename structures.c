#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structures section
struct Race {
    int numberOfLaps;
    int currentLap;
    char firstPlaceDriverName[15];
    char firstPlaceRaceCarColor[15];
};

struct RaceCar {
    char driverName[15];
    char raceCarColor[15];
    int totalLapTime;
};

// Print functions section
void printIntro() {
    printf("Welcome to our main event digital race fans! I hope everybody has their snacks because we are about to begin!\n");
}

void printCountDown() {
    printf("Racers Ready! In...\n5\n4\n3\n2\n1\nRace!\n");
}

void printFirstPlaceAfterLap(struct Race race) {
    printf("After lap number %d,\nFirst Place Is: %s in the %s race car!\n", race.currentLap, race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race) {
    printf("Let's all congratulate %s in the %s race car for an amazing performance.\nIt truly was a great race and everybody have a goodnight!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

// Logic functions section
int calculateTimeToCompleteLap() {
    int speed, acceleration, nerves;

    speed = (rand() % 3) + 1;
    acceleration = (rand() % 3) + 1;
    nerves = (rand() % 3) + 1;

    return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar *raceCar, int raceTime) {
    raceCar->totalLapTime += raceTime;
}

void updateFirstPlace(struct Race *race, struct RaceCar *raceCar1, struct RaceCar *raceCar2) {
    if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
        strcpy(race->firstPlaceDriverName, raceCar1->driverName);
        strcpy(race->firstPlaceRaceCarColor, raceCar1->raceCarColor);
    } else {
        strcpy(race->firstPlaceDriverName, raceCar2->driverName);
        strcpy(race->firstPlaceRaceCarColor, raceCar2->raceCarColor);
    }
}

// Race function
void startRace(struct RaceCar *raceCar1, struct RaceCar *raceCar2) {
    struct Race race = {5, 1, "", ""};

    for (int i = 0; i < race.numberOfLaps; i++) {
        int raceTime1 = calculateTimeToCompleteLap();
        int raceTime2 = calculateTimeToCompleteLap();

        updateRaceCar(raceCar1, raceTime1);
        updateRaceCar(raceCar2, raceTime2);
        updateFirstPlace(&race, raceCar1, raceCar2);

        printFirstPlaceAfterLap(race);

        race.currentLap++;
    }

    printCongratulation(race);
}

int main() {
    srand(time(0));

    // Declare and initialize RaceCar data types
    struct RaceCar car1 = {"Driver1", "Red", 0};
    struct RaceCar car2 = {"Driver2", "Blue", 0};

    printIntro();
    printCountDown();

    // Call startRace with pointers to RaceCar types
    startRace(&car1, &car2);

    return 0;
}
