 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Person{
    int age;
    float height;
    float hairLength;
    float GPA;
    float SATScore;
    float distanceTravelled;

    struct Foot
    {
        float latitude = 0.0f;
    
        float stepSize();
        void stepForward();
    };

    void run(float howFast, bool startWithLeftFoot);

    Foot leftFoot;
    Foot rightFoot;
};

float Person::Foot::stepSize()
{
    return latitude;
}

void Person::Foot::stepForward()
{
    latitude += 0.000001f;
}

void Person::run(float howFast, bool startWithLeftFoot)
{
    if(startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    
    distanceTravelled += (leftFoot.stepSize() + rightFoot.stepSize()) * howFast;
    
    height = hairLength * GPA * SATScore * distanceTravelled;
    age += 1;
}



 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */

/*
paste your code below
*/
struct Iphone
{
    std::string operatingSystem = "iOS";
    float screenSize = 8.0f;
    std::string speakerType = "Bose";
    std::string cameraType = "Nikon";
    float batteryLife = 100.0f;
    
    void browseTheWeb(std::string url);
    void playMusic(std::string songName);
    void makePhoneCall(int number);
};

void Iphone::browseTheWeb(std::string url)
{   
    operatingSystem = speakerType + cameraType;
    std::cout << "www." << url << std::endl;
}

void Iphone::playMusic(std::string songName)
{
    screenSize = batteryLife;
    std::cout << speakerType << " " << songName << std::endl;
}

void Iphone::makePhoneCall(int number)
{
    number += 1;
}


struct Diner
{
    int numberOfEmployees = 5;
    std::string foodSupplier = "Sysco";
    std::string hoursOfOperation = "eight to five";
    int numberOfTables = 10;
    float starRating = 5;
    
    struct Kitchen
    {
        int numberOfChefs = 5;
        std::string grillBrand = "Weber";
        std::string tileType = "Marble";
        int numberOfBlenders = 10;
        float temperature = 100.0f;
        
        void runFoodDisposal();
        void burnToast(int numberOfSlices);
        std::string receiveOrder();
    };

    void cookEggs(Kitchen thiskitchen);
    void serveFood(int tableNumber);
    std::string takeOrders(); 
    
    Kitchen kitchen;
};

void Diner::Kitchen::runFoodDisposal()
{
    numberOfChefs -= numberOfBlenders;
    std::cout << "Grrrrrrrr" << std::endl;
}

void Diner::Kitchen::burnToast(int numberOfSlices)
{
    if(numberOfSlices == 1 || grillBrand == "Weber")
    {
        temperature += 1.0f;
    }
    else
    {
        temperature += 2.0f;
    }
}

std::string Diner::Kitchen::receiveOrder(){
    return "Roger that!";
}

void Diner::cookEggs(Kitchen thiskitchen)
{
    numberOfTables = numberOfEmployees + thiskitchen.numberOfChefs;
    std::cout << "You've got crumbs all over my" << kitchen.tileType << std::endl;
}

void Diner::serveFood(int tableNumber)
{
        tableNumber += 1;
}


std::string Diner::takeOrders()
{
    return hoursOfOperation + foodSupplier;
}

struct GuitarAmp
{
    float volumeControl = 50.0f;
    std::string fxType = "Reverb";
    float gainControl = 50.0f;
    float cabinetSize = 18.0f;
    float inputVoltage = 12.0f;
    
    void changeVolume(float newVolume);
    void processInput();
    void adjustGain(float newGain);
};

void GuitarAmp::changeVolume(float newVolume)
{
    volumeControl = newVolume;
    cabinetSize = 14.0f;
}

void GuitarAmp::processInput()
{
    fxType = "chuggawugga";
    inputVoltage = 11.9f;
}

void GuitarAmp::adjustGain(float newGain)
{
    gainControl = newGain;
}

struct Bank
{
    float totalCash = 1000000.0f;
    int numberOfAtms = 3;
    int numberOfTellers = 3;
    float internalAirTemperature = 70.0f;
    float frontDoorHeight = 100.0f;

    int receieveCash(float amount);
    void payTeller(float amount);
    void hireManager(std::string name);
};

int Bank::receieveCash(float amount)
{
    totalCash += amount;
    internalAirTemperature += frontDoorHeight;
    return 1;
}

void Bank::payTeller(float amount)
{
    std::cout << "Please take $" << amount << std::endl;
}

void Bank::hireManager(std::string name)
{
    std::cout << "Hi " << name << std::endl;
    numberOfTellers += numberOfAtms;
}

struct Wing
{
    float length = 20.0f;
    std::string iceMeltFluidType = "Dr. Lava";
    int numberOfRibs = 10;
    std::string color = "Greenish Red";
    int numberOfFlaps = 3;

    void inclineFlap();
    void meltIce();
    void flashLight(std::string otherColor);
};

void Wing::inclineFlap()
{
    std::cout << "Pffpfpfpfpppppffpffp " << std::endl;
    numberOfRibs = numberOfFlaps;
}

void Wing::meltIce()
{
    std::cout << "Applying " << iceMeltFluidType << std::endl;
}

void Wing::flashLight(std::string otherColor)
{
    color = otherColor;
    length = 21.0f;
}

struct Cockpit
{
    int numberOfPilots = 3;
    int numberOfSwitches = 1400;
    std::string radarType = "Expensive and Fancy";
    float winshieldTintLevel = 100.0f;
    float winshieldHeight = 18.0f;

    void turnPlane();
    bool sendMessageToAirport(std::string message); 
    void sendPaMessageToCabin(std::string message);
};

void Cockpit::turnPlane()
{
    winshieldHeight -= winshieldTintLevel;
    numberOfPilots = numberOfSwitches;
}

bool Cockpit::sendMessageToAirport(std::string message)
{
    std::cout << "Hey airport... " << message << std::endl;
    return true;
}

void Cockpit::sendPaMessageToCabin(std::string message)
{
    std::cout << "Hey guys don't be mad but" << message << ". Also, " << radarType << std::endl;
}

struct Cabin
{
    int numberOfPassengers = 50;
    int numberOfSeats = 49;
    std::string snackType = "Bugles";
    std::string gingerAletype = "Canada Dry";
    float legroomDepth = 0.0f;
    
    struct FlightAttendant
    {
        int numberOfEyeballs = 1;
        int numberOfElbows = 2;
        std::string deoderantBrand = "Mitchum";
        std::string favoriteDanceType = "Disco";
        float earSize = 0.0f;
        
        void dance(float insanityLevel);
        float bendKnee();
        void speak();
    };
    
    void dimLights(float newLevel);
    float serveCoffee(FlightAttendant flightAttendant);
    void playMusic();
    
    FlightAttendant joseph;
    FlightAttendant nadine;
};


void Cabin::FlightAttendant::dance(float insanityLevel)
{
    std::cout << "I had like " << insanityLevel << " cups of coffee before this" << std::endl;
}

float Cabin::FlightAttendant::bendKnee()
{
    earSize *= 2.0f;
    return earSize;
}

void Cabin::FlightAttendant::speak()
{
    std::cout << "About what?" << std::endl;
    std::cout << deoderantBrand << favoriteDanceType << std::endl;
}

void Cabin::dimLights(float newLevel)
{
    newLevel += legroomDepth;
    std::cout << snackType << " and " << gingerAletype << std::endl;
}

float Cabin::serveCoffee(FlightAttendant flightAttendant)
{
    flightAttendant.bendKnee();
    return legroomDepth;
}

void Cabin::playMusic()
{
    if(numberOfPassengers < numberOfSeats)
    {
        joseph.numberOfEyeballs = 0;
        nadine.numberOfElbows = 0;
    }
}

struct Restroom
{
    float roomHeight = 120.0f;
    float sinkDepth = 0.1f;
    float flushVolumeInDecibels = 150.0f;
    int numberOfPliesInToiletPaper = 1;
    std::string soapBrand = "Sergeant Scrub";
    
    void flowSinkWater();
    void illuminateRoom(float newLevel);
    float moveLoadToTank();
};

void Restroom::flowSinkWater()
{
    sinkDepth -= 1.0f;
    numberOfPliesInToiletPaper += 1;
}

void Restroom::illuminateRoom(float newLevel)
{
    flushVolumeInDecibels = newLevel / roomHeight;
}

float Restroom::moveLoadToTank()
{
    std::cout << "farewell" << soapBrand << std::endl;
    return flushVolumeInDecibels;
}

struct Engine
{
    int numberOfCylinders = 6;
    std::string typeOfFuel = "Jet Fuel";
    float chamberPressure = 14.7f;
    float maximumTemperature = 451.0f;
    std::string material = "Gold";
    
    void suckInFuel();
    void combustFuel();
    float spinAxle();
};

void Engine::suckInFuel()
{
    std::cout << "yea the " << typeOfFuel << " in the "<< material << " bottle" << std::endl;
}

void Engine::combustFuel()
{
    numberOfCylinders += 1;
}

float Engine::spinAxle()
{
    return chamberPressure * maximumTemperature;
}

struct Airplane
{
    Wing wing;
    Cockpit cockpit;
    Cabin cabin;
    Restroom restroom;
    Engine engine;
    
    void takeoff();
    void turn(float angle);
    float pingRadar();
};

void Airplane::takeoff()
{
    wing.inclineFlap();
    cockpit.sendPaMessageToCabin("Have fun");
    cabin.playMusic();
}

void Airplane::turn(float angle)
{
    angle *= 2.0f;
    engine.suckInFuel();
}

float Airplane::pingRadar()
{
    return restroom.moveLoadToTank();
}

int main()
{
    std::cout << "good to go!" << std::endl;
}
