/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable that IS NOT initialized in-class
    float b { 2.f }; //a member variable that IS initialized in-class
    UDT() : a(0) { } // 'constructor-initializer-list' initializing the member that wasn't initialized in-class.
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //2) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()




/*
paste your code below
*/
struct Iphone
{
    Iphone();
    
    std::string operatingSystem = "iOS";
    float screenSize = 8.0f;
    std::string speakerType = "Bose";
    std::string cameraType = "Nikon";
    float batteryLife = 100.0f;
    
    void browseTheWeb(std::string url);
    void playMusic(std::string songName);
    void makePhoneCall(int number);
};

Iphone::Iphone()
{   
    std::cout << "Constructing IPhone" << std::endl;
}

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
    Diner();

    int numberOfEmployees = 5;
    std::string foodSupplier = "Sysco";
    std::string hoursOfOperation = "eight to five";
    int numberOfTables = 10;
    float starRating = 5;
    
    struct Kitchen
    {
        Kitchen();

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

Diner::Diner()
{   
    std::cout << "Constructing Diner" << std::endl;
}

Diner::Kitchen::Kitchen()
{   
    std::cout << "Constructing Diner::Kitchen" << std::endl;
}

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
    std::cout << "You've got crumbs all over my " << kitchen.tileType << std::endl;
}

void Diner::serveFood(int tableNumber)
{
    tableNumber += 1;
}


std::string Diner::takeOrders()
{
    return hoursOfOperation + " " + foodSupplier;
}

struct GuitarAmp
{
    GuitarAmp();

    float volumeControl = 50.0f;
    std::string fxType = "Reverb";
    float gainControl = 50.0f;
    float cabinetSize = 18.0f;
    float inputVoltage = 12.0f;
    
    void changeVolume(float newVolume);
    void processInput();
    void adjustGain(float newGain);
};

GuitarAmp::GuitarAmp()
{   
    std::cout << "Constructing GuitarAmp" << std::endl;
}

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
    Bank();

    float totalCash = 1000000.0f;
    int numberOfAtms = 3;
    int numberOfTellers = 3;
    float internalAirTemperature = 70.0f;
    float frontDoorHeight = 100.0f;

    int receiveCash(float amount);
    void payTeller(float amount);
    void hireManager(std::string name);
};

Bank::Bank()
{   
    std::cout << "Constructing Bank" << std::endl;
}

int Bank::receiveCash(float amount)
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
    Wing();

    float length = 20.0f;
    std::string iceMeltFluidType = "Dr. Lava";
    int numberOfRibs = 10;
    std::string color = "Greenish Red";
    int numberOfFlaps = 3;

    void inclineFlap();
    void meltIce();
    void flashLight(std::string otherColor);
};

Wing::Wing()
{   
    std::cout << "Constructing Wing" << std::endl;
}

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
    Cockpit();

    int numberOfPilots = 3;
    int numberOfSwitches = 1400;
    std::string radarType = "Expensive and Fancy";
    float winshieldTintLevel = 100.0f;
    float winshieldHeight = 18.0f;

    void turnPlane();
    bool sendMessageToAirport(std::string message); 
    void sendPaMessageToCabin(std::string message);
};

Cockpit::Cockpit()
{   
    std::cout << "Constructing Cockpit" << std::endl;
}

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
    Cabin();

    int numberOfPassengers = 50;
    int numberOfSeats = 49;
    std::string snackType = "Bugles";
    std::string gingerAletype = "Canada Dry";
    float legroomDepth = 0.0f;
    
    struct FlightAttendant
    {
        FlightAttendant();

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

Cabin::Cabin()
{   
    std::cout << "Constructing Cabin" << std::endl;
}

Cabin::FlightAttendant::FlightAttendant()
{   
    std::cout << "Constructing Cabin::FlightAttendant" << std::endl;
}

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
    std::cout << deoderantBrand << " " << favoriteDanceType << std::endl;
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
    Restroom();

    float roomHeight = 120.0f;
    float sinkDepth = 0.1f;
    float flushVolumeInDecibels = 150.0f;
    int numberOfPliesInToiletPaper = 1;
    std::string soapBrand = "Sergeant Scrub";
    
    void flowSinkWater();
    void illuminateRoom(float newLevel);
    float moveLoadToTank();
};

Restroom::Restroom()
{   
    std::cout << "Constructing Restroom" << std::endl;
}

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
    std::cout << "farewell " << soapBrand << std::endl;
    return flushVolumeInDecibels;
}

struct Engine
{
    Engine();

    int numberOfCylinders = 6;
    std::string typeOfFuel = "Jet Fuel";
    float chamberPressure = 14.7f;
    float maximumTemperature = 451.0f;
    std::string material = "Gold";
    
    void suckInFuel();
    void combustFuel();
    float spinAxle();
};

Engine::Engine()
{   
    std::cout << "Constructing Engine" << std::endl;
}

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
    Airplane();

    Wing wing;
    Cockpit cockpit;
    Cabin cabin;
    Restroom restroom;
    Engine engine;
    
    void takeoff();
    void turn(float angle);
    float pingRadar();
};

Airplane::Airplane()
{   
    std::cout << "Constructing Airplane" << std::endl;
}

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
    Example::main();

    Iphone myPhone;
    Iphone davesPhone;
    Diner jerrys;
    Diner::Kitchen jerrysKitchen;
    GuitarAmp thisOldAmp;
    Bank chase;
    Wing leftWing;
    Wing rightWing;
    Cockpit pilotsPad;
    Cabin passengersClub;
    Cabin::FlightAttendant jerry;
    Cabin::FlightAttendant jessica;
    Restroom ladiesRoom;
    Engine jetOne;
    Engine jetTwo;
    Airplane delta306;

    myPhone.browseTheWeb("homestarrunner.com");
    myPhone.playMusic("Night Mommas");
    myPhone.makePhoneCall(5551234);

    davesPhone.browseTheWeb("namethatbeard.com");
    davesPhone.playMusic("Sharp Dressed Man");
    davesPhone.makePhoneCall(5559876);

    jerrysKitchen.runFoodDisposal();
    jerrysKitchen.burnToast(1);
    std::string kitchenOrder = jerrysKitchen.receiveOrder();
    std::cout << "Here's your " << kitchenOrder << std::endl;

    jerrys.serveFood(12);
    jerrys.cookEggs(jerrysKitchen);
    std::string tableOrder = jerrys.takeOrders();
    std::cout << "Here's your " << tableOrder << std::endl;

    thisOldAmp.changeVolume(5.0f);
    thisOldAmp.processInput();
    thisOldAmp.adjustGain(5.0f);

    int status = chase.receiveCash(3.0f);
    chase.payTeller(3.0f);
    chase.hireManager("Jerry's mom");
    std::cout << "Status: " << std::to_string(status) << std::endl;

    leftWing.inclineFlap();
    leftWing.meltIce();
    leftWing.flashLight("bluish yellow");

    rightWing.inclineFlap();
    rightWing.meltIce();
    rightWing.flashLight("purplish green");

    pilotsPad.turnPlane();
    bool airportResponse = pilotsPad.sendMessageToAirport("Control tower we have violent turbulence. We are scared.");
    std::string airportResponseString = airportResponse ? "true" : "false";
    pilotsPad.sendPaMessageToCabin("bumpy ride today right?");
    std::cout << "To that I say: " << airportResponseString << std::endl;

    jerry.dance(7.0f);
    float jerrysEar = jerry.bendKnee();
    jerry.speak();
    std::cout << "gross me out, " << std::to_string(jerrysEar) << std::endl;

    jessica.dance(14000.0f);
    float jessicasEar = jessica.bendKnee();
    jessica.speak();
    std::cout << "hear me, " << std::to_string(jessicasEar) << std::endl;

    passengersClub.dimLights(11.0f);
    float legroom = passengersClub.serveCoffee(jessica);
    passengersClub.playMusic();
    std::cout << "Here's your " << std::to_string(legroom) << std::endl;

    ladiesRoom.flowSinkWater();
    ladiesRoom.illuminateRoom(5.0f);
    float flushVolumeInDecibels = ladiesRoom.moveLoadToTank();
    std::cout << "Here's your " << std::to_string(flushVolumeInDecibels) << std::endl;

    jetOne.suckInFuel();
    jetOne.combustFuel();
    float maxVolume = jetOne.spinAxle();
    std::cout << "Here's your " << std::to_string(maxVolume) << std::endl;

    jetTwo.suckInFuel();
    jetTwo.combustFuel();
    jetTwo.spinAxle();

    delta306.takeoff();
    delta306.turn(90.1f);
    float flushSpinDirection = delta306.pingRadar();
    std::cout << "Here's your " << std::to_string(flushSpinDirection) << std::endl;

    std::cout << "good to go!" << std::endl;
}
