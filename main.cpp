/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            ++bar.num;                    //2a), 5)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()





/*
paste your code below
*/
struct Iphone
{
    Iphone();
    
    std::string operatingSystem;
    float screenSize{8.0f};
    std::string speakerType;
    std::string cameraType;
    float batteryLife = 100.0f;
    
    void browseTheWeb(std::string url);
    void playMusic(std::string songName);
    void makePhoneCall(int number);
};

Iphone::Iphone():
operatingSystem("iOS"),
speakerType("Bose"),
cameraType("Nikon")
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
    std::cout << "Listen on on " << speakerType << " speakers" << std::endl;
    number += 1;
}


struct Diner
{
    Diner();

    int numberOfEmployees;
    std::string foodSupplier = "Sysco";
    std::string hoursOfOperation = "eight to five";
    int numberOfTables = 10;
    float starRating = 5;
    
    struct Kitchen
    {
        Kitchen();

        int numberOfChefs;
        std::string grillBrand;
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

Diner::Diner():
numberOfEmployees(5)
{   
    std::cout << "Constructing Diner with " << numberOfEmployees << " employees" << std::endl;
}

Diner::Kitchen::Kitchen():
numberOfChefs(5), 
grillBrand("Weber")
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
    std::cout << "Cooking toast on " << grillBrand << " grill" << std::endl;
    
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

    float volumeControl;
    std::string fxType;
    float gainControl = 50.0f;
    float cabinetSize = 18.0f;
    float inputVoltage = 12.0f;
    
    void changeVolume(float newVolume);
    void processInput();
    void adjustGain(float newGain);
};

GuitarAmp::GuitarAmp():
volumeControl(50.0f),
fxType("Reverb")
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
    int numberOfAtms;
    int numberOfTellers;
    float internalAirTemperature = 70.0f;
    float frontDoorHeight = 100.0f;

    int receiveCash(float amount);
    void payTeller(float amount);
    void hireManager(std::string name);
};

Bank::Bank():
numberOfAtms(3),
numberOfTellers(3)
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
    std::string iceMeltFluidType;
    int numberOfRibs = 10;
    std::string color;
    int numberOfFlaps = 3;

    void inclineFlap();
    void meltIce();
    void flashLight(std::string otherColor);
};

Wing::Wing():
iceMeltFluidType("Dr. Lava"),
color("Greenish Red")
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

    int numberOfPilots;
    int numberOfSwitches = 1400;
    std::string radarType;
    float winshieldTintLevel = 100.0f;
    float winshieldHeight = 18.0f;

    void turnPlane();
    bool sendMessageToAirport(std::string message); 
    void sendPaMessageToCabin(std::string message);
};

Cockpit::Cockpit():
numberOfPilots(3),
radarType("Expensive and Fancy")
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
    std::cout << "Hey guys don't be mad but " << message << ". Also, " << radarType << std::endl;
}

struct Cabin
{
    Cabin();

    int numberOfPassengers;
    int numberOfSeats;
    std::string snackType = "Bugles";
    std::string gingerAletype = "Canada Dry";
    float legroomDepth = 0.0f;
    
    struct FlightAttendant
    {
        FlightAttendant();

        int numberOfEyeballs;
        int numberOfElbows;
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

Cabin::Cabin():
numberOfPassengers(50),
numberOfSeats(49)
{   
    std::cout << "Constructing Cabin" << std::endl;
}

Cabin::FlightAttendant::FlightAttendant():
numberOfEyeballs(1),
numberOfElbows(2)
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
    int numberOfPliesInToiletPaper;
    std::string soapBrand;
    
    void flowSinkWater();
    void illuminateRoom(float newLevel);
    float moveLoadToTank();
};

Restroom::Restroom():
numberOfPliesInToiletPaper(1),
soapBrand("Sergeant Scrub")
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
    std::string typeOfFuel;
    float chamberPressure;
    float maximumTemperature = 451.0f;
    std::string material = "Gold";
    
    void suckInFuel();
    void combustFuel();
    float spinAxle();
};

Engine::Engine():
typeOfFuel("Jet Fuel"),
chamberPressure(14.7f)
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
