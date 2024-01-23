/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




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
    Example::main();

    
    std::cout << "good to go!" << std::endl;
}
