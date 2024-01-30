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
            std::cout << "increasing bar.num: " << bar.num << std::endl; //4)
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
    void screenShrinker(int magnitude);
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

void Iphone::screenShrinker(int magnitude)
{
    int i = magnitude % 10;
    while(i < 10)
    {
        screenSize -= 0.1f;
    }
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
        float addBodyHeat();
    };

    void cookEggs(Kitchen thiskitchen);
    void serveFood(int tableNumber);
    std::string takeOrders(); 
    void loseRating(int numberOfSpills);
    
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

float Diner::Kitchen::addBodyHeat(){

    float changedTemperature = temperature;
    
    for(int c = 0; c < numberOfChefs; ++c)
    {
        changedTemperature += 0.1f;
    }

    std::cout << "It's " << changedTemperature << " degrees in here!" << std::endl;
    
    return changedTemperature;
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

void Diner::loseRating(int numberOfSpills)
{
    for(int spill = 0; spill < numberOfSpills; ++spill)
    {
        starRating -= 1;
    }
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
    bool checkIfNeighborsAngry(float patience);
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

bool GuitarAmp::checkIfNeighborsAngry(float patience)
{
    while(volumeControl < 100.0f)
    {
        if(volumeControl < patience)
        {
            std::cout << "Seems okay" << std::endl;
        }
        else
        {
            std::cout << "Oh boy. Everyone hide!" << std::endl;
            return false;
        }
    }

    return false;
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
    float robbery(std::string robberType);
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

float Bank::robbery(std::string robberType)
{
    int strength;
    float moneyStolen = 0.0f;
    
    if(robberType == "buff guy")
    {
        strength = 2;
        std::cout << "Stick 'em up!" << std::endl;
    }else
    {
        strength = 1;
        std::cout << "Money please" << std::endl;
    }

    for(int i = 0; i < strength; ++i)
    {
        moneyStolen += 300.0f;
    }

    return moneyStolen;
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
    void breakRib();
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

void Wing::breakRib()
{
    while(numberOfRibs > 0)
    {
        --numberOfRibs;
        std::cout << "Broke 1 rib" << std::endl;
    }
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
    void removeFamily(int numberOfFamilyMembers, std::string parentsAttitude);
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

void Cockpit::removeFamily(int numberOfFamilyMembers, std::string parentsAttitude)
{
    while(numberOfFamilyMembers > 0)
    {
        if(parentsAttitude == "reasonable")
        {
            std::cout << "No problem, please sit down" << std::endl;
            return;
        }
        else
        {
            std::cout << "Off you go" << std::endl;
            -- numberOfFamilyMembers;
        }
    }
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
        float pourCoffee(float coffeeLevel, int numberOfOrders);
    };
    
    void dimLights(float newLevel);
    float serveCoffee(FlightAttendant flightAttendant);
    void playMusic();
    float reclineSeat(float maxReclineAngle, bool rearPassengerIsHappy);
    
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

float Cabin::FlightAttendant::pourCoffee(float coffeeLevel, int numberOfOrders)
{
    for(int order = 0; order < numberOfOrders; ++order)
    {
        if(coffeeLevel > 0.5f)
        {
            std::cout << "Pour cup" << std::endl;
            coffeeLevel -= 0.5f;  
        }
        else
        {
            std::cout << "No more coffee" << std::endl;
            return 0.0f;
        }
    }
    return coffeeLevel;
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

float Cabin::reclineSeat(float maxReclineAngle, bool rearPassengerIsHappy)
{
    float angle = 0.0f;
    
    while(angle < maxReclineAngle)
    {
        if(angle > 30.0f)
        {
            rearPassengerIsHappy = false;
        }
        
        if(rearPassengerIsHappy)
        {
            std::cout << "Recline seat" << std::endl;
            angle += 5.0f;
        }
        else
        {
            std::cout << "No recline" << std::endl;
            return angle;
        }
    }
    return angle;
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
    bool callMaintenence(float toiletLevel, int numberOfVisitors);
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

bool Restroom::callMaintenence(float toiletLevel, int numberOfVisitors)
{
    float maxToiletLevel = 100.0f;
    
    for(int visitor = 0; visitor < numberOfVisitors; ++visitor)
    {
        if(toiletLevel < maxToiletLevel)
        {
            std::cout << "Next!" << std::endl;
            toiletLevel += 10.0f;
        }
        else
        {
        std::cout << "Uh oh!" << std::endl;
        return false;
        }
    }
    
    return true;
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
    bool addFluid(float initialFluidLevel, int bottlesOfFuel, float fluidPerBottle);
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

bool Engine::addFluid(float initialFluidLevel, int bottlesOfFuel, float fluidPerBottle)
{
    float level = initialFluidLevel;
    
    for(int bottle = 0; bottle < bottlesOfFuel; ++bottle)
    {
        if(level < 100.0f)
        {
            std::cout << "1 bottle poured" << std::endl;
            level += fluidPerBottle;
        }
        else
        {
            std::cout << "Too much!" << std::endl;
            return false;
        }
    }
    return true;
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
    bool checkFlightStatus(int numberOfBirdsHit);
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

bool Airplane::checkFlightStatus(int numberOfBirdsHit)
{
    int bird = 0;
    while(bird < numberOfBirdsHit)
    {
        wing.length -= 1.0f;
        std::cout << "Thump" << std::endl;

        if (wing.length < 15.0f)
        {
            std::cout << "Down we go" << std::endl;
            return false;
        }
    }
    return true;
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
    std::cout << kitchenOrder << std::endl;

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
    std::cout << "Legroom: " << std::to_string(legroom) << std::endl;

    ladiesRoom.flowSinkWater();
    ladiesRoom.illuminateRoom(5.0f);
    float flushVolumeInDecibels = ladiesRoom.moveLoadToTank();
    std::cout << "This loud: " << std::to_string(flushVolumeInDecibels) << std::endl;

    jetOne.suckInFuel();
    jetOne.combustFuel();
    float maxVolume = jetOne.spinAxle();
    std::cout << "This loud: " << std::to_string(maxVolume) << std::endl;

    jetTwo.suckInFuel();
    jetTwo.combustFuel();
    jetTwo.spinAxle();

    delta306.takeoff();
    delta306.turn(90.1f);
    float flushSpinDirection = delta306.pingRadar();
    std::cout << "Spin this way: " << std::to_string(flushSpinDirection) << std::endl;

    myPhone.screenShrinker(15);

    float temp = jerrysKitchen.addBodyHeat();
    std::cout << "New temp: " << std::to_string(temp) << std::endl;

    jerrys.loseRating(5);

    bool neighborIsAngry = thisOldAmp.checkIfNeighborsAngry(70.0f);
    std::string neighborIsAngryString = neighborIsAngry ? "true" : "false";
    std::cout << "Are you angry? " << neighborIsAngryString << std::endl;

    float moneyStolen = chase.robbery("buff guy");
    std::cout << "$" << std::to_string(moneyStolen) << " lost" << std::endl;

    leftWing.breakRib();

    pilotsPad.removeFamily(5, "reasonable");

    float coffeeLevel = jessica.pourCoffee(5.0f, 25);
    std::cout << "coffeeleft: " << std::to_string(coffeeLevel) << std::endl;
    
    float angle = passengersClub.reclineSeat(40.0f, true);
    std::cout << "This far back: " << std::to_string(angle) << std::endl;

    bool ladiesRoomStatus = ladiesRoom.callMaintenence(15.0f, 10);
    std::string ladiesRoomStatusString = ladiesRoomStatus ? "true" : "false";
    std::cout << "Bathroom status: " << ladiesRoomStatusString << std::endl;

    bool roomLeft = jetOne.addFluid(0.0f, 20, 10.0f);
    std::string roomLeftString = roomLeft ? "true" : "false";
    std::cout << "Room for fuel: " << roomLeftString << std::endl;

    bool stillFlying = delta306.checkFlightStatus(13);
    std::string stillFlyingString = stillFlying ? "true" : "false";
    std::cout << "We okay up there? " << stillFlyingString << std::endl;

    std::cout << "good to go!" << std::endl;
}
