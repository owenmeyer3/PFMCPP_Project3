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
    // 5 properties:
    //     1) operating system (std::string)
        std::string operatingSystem = "iOS";
    //     2) screen size (float)
        float screenSize = 8.0f;
    //     3) speaker type (std::string)
        std::string speakerType = "Bose";
    //     4) camera type (std::string)
        std::string cameraType = "Nikon";
    //     5) battery life (float)
        float batteryLife = 100.0f;
    
    // 3 things it can do:
    //     1) browse the web
    void browseTheWeb(std::string url);
    //     2) play music
    void playMusic(std::string songName);
    //     3) make phone call
    void makePhoneCall(int number);
};

/*
Thing 2) Diner
5 properties:
    1) number of employees (int)
    2) food supplier (std::string)
    3) hours of operation (std::string)
    4) number of tables (int)
    5) star rating (float)
3 things it can do:
    1) cook eggs
    2) serve food
    3) take orders
*/
struct Diner
{
    // 5 properties:
    //     1) number of employees (int)
    int numberOfEmployees = 5;
    //     2) food supplier (std::string)
    std::string foodSupplier = "Sysco";
    //     3) hours of operation (std::string)
    std::string hoursOfOperation = "8-5";
    //     4) number of tables (int)
    int numberOfTables = 10;
    //     5) star rating (float)
    float starRating = 5;
    
    struct Kitchen
    {
        // 5 properties:
        //     1) number of chefs (int)
        int numberOfChefs = 5;
        //     2) grill brand (std::string)
        std::string grillBrand = "Weber";
        //     3) tileType (std::string)
        std::string tileType = "Marble";
        //     4) number of blenders (int)
        int numberOfBlenders = 10;
        //     5) temperature (float)
        float temperature = 100.0f;
        
        // 3 things it can do:
        //     1) run ood disposal
        void runFoodDisposal();
        //     2) burn toast
        void burnToast(int numberOfSlices);
        //     3) receive order
        std::string receiveOrder(); //return order
    };
    
    // 3 things it can do:
    //     1) cook eggs
    void cookEggs(Kitchen kitchen); //pass kitchen to cook the eggs
    //     2) serve food
    void serveFood(int tableNumber);
    //     3) take orders
    std::string takeOrders(); //return orders
    
    Kitchen kitchen;
};

/*
Thing 3) Guitar Amp
5 properties:
    1) Volume control (float)
    2) FX Type (std::string)
    3) gain control (float)
    4) cabinet size (float)
    5) input voltage (float)
3 things it can do:
    1) change volume
    2) process input
    3) adjust gain
*/
struct GuitarAmp
{
    // Thing 3) Guitar Amp
    // 5 properties:
    //     1) Volume control (float)
    float volumeControl = 50.0f;
    //     2) FX Type (std::string)
    std::string fxType = "Reverb";
    //     3) gain control (float)
    float gainControl = 50.0f;
    //     4) cabinet size (float)
    float cabinetSize = 18.0f;
    //     5) input voltage (float)
    float inputVoltage = 12.0f;
    
    // 3 things it can do:
    //     1) change volume
    void changeVolume(float newVolume);
    //     2) process input
    void processInput();
    //     3) adjust gain
    void adjustGain(float newGain);
};

/*
Thing 4) Bank
5 properties:
    1) total cash (float)
    2) number of atms (int)
    3) number of tellers (int)
    4) internal air temperature (float)
    5) front door height (float)
3 things it can do:
    1) recieve cash
    2) pay teller
    3) hire manager
*/
struct Bank
{
    // 5 properties:
    //     1) total cash (float)
    float totalCash = 1000000.0f;
    //     2) number of atms (int)
    int numberOfAtms = 3;
    //     3) number of tellers (int)
    int numberOfTellers = 3;
    //     4) internal air temperature (float)
    float internalAirTemperature = 70.0f;
    //     5) front door height (float)
    float frontDoorHeight = 100.0f;
    
    // 3 things it can do:
    //     1) recieve cash
    int receieveCash(float amount); //return deposit id
    //     2) pay teller
    void payTeller(float amount);
    //     3) hire manager
    void hireManager(std::string name);
};

/*
Thing 5) Wing
5 properties:
    1) length (float)
    2) ice melt fluid type (std::string)
    3) number of ribs (int)
    4) color (std::string)
    5) number of flaps (int)
3 things it can do:
    1) incline flap
    2) melt ice
    3) flash light
*/
struct Wing
{
    // 5 properties:
    //     1) length (float)
    float length = 20.0f;
    //     2) ice melt fluid type (std::string)
    std::string iceMeltFluidType = "Dr. Lava";
    //     3) number of ribs (int)
    int numberOfRibs = 10;
    //     4) color (std::string)
    std::string color = "Greenish Red";
    //     5) number of flaps (int)
    int numberOfFlaps = 3;
    
    // 3 things it can do:
    //     1) incline flap
    void inclineFlap();
    //     2) melt ice
    void meltIce();
    //     3) flash light
    void flashLight(std::string color);
};

/*
Thing 6) Cockpit
5 properties:
    1) number of pilots (int)
    2) number of switches (int)
    3) radar type (std::string)
    4) winshield tint level (float)
    5) winshield height (float)
3 things it can do:
    1) turn plane
    2) send message to airport
    3) send PA message to cabin
*/
struct Cockpit
{
    // 5 properties:
    //     1) number of pilots (int)
    int numberOfPilots = 3;
    //     2) number of switches (int)
    int numberOfSwitches = 1400;
    //     3) radar type (std::string)
    std::string radarType = "Expensive and Fancy";
    //     4) winshield tint level (float)
    float winshieldTintLevel = 100.0f;
    //     5) winshield height (float)
    float winshieldHeight = 18.0f;
    
    // 3 things it can do:
    //     1) turn plane
    void turnPlane();
    //     2) send message to airport
    bool sendMessageToAirport(std::string message); //return success (true) or failure (false)
    //     3) send PA message to cabin
    void sendPaMessageToCabin(std::string message);
};

/*
Thing 7) Cabin
5 properties:
    1) number of passengers (int)
    2) number of seats (int)
    3) snack type (std::string)
    4) ginger ale type (std::string)
    5) legroom depth (float)
3 things it can do:
    1) dim lights
    2) serve coffee
    3) play music
*/
struct Cabin
{
    // 5 properties:
    //     1) number of passengers (int)
    int numberOfPassengers = 50;
    //     2) number of seats (int)
    int numberOfSeats = 49;
    //     3) snack type (std::string)
    std::string snackType = "Bugles";
    //     4) ginger ale type (std::string)
    std::string gingerAletype = "Canada Dry";
    //     5) legroom depth (float)
    float legroomDepth = 0.0f;
    
    struct FlightAttendant
    {
        // 5 properties:
        //     1) number of eyeballs (int)
        int numberOfEyeballs = 1;
        //     2) number of elbows (int)
        int numberOfElbows = 2;
        //     3) deoderant brand (std::string)
        std::string deoderantBrand = "Mitchum";
        //     4) favorite dance type (std::string)
        std::string favoriteDanceType = "Disco";
        //     5) ear size (float)
        float earSize = 0.0f;
        
        // 3 things it can do:
        //     1) dance
        void dance(float insanityLevel);
        //     2) bend knee
        float bendKnee(); //return degrees bent
        //     3) speak
        void speak();
    };
    
    // 3 things it can do:
    //     1) dim lights
    void dimLights(float newLevel);
    //     2) serve coffee
    float serveCoffee(FlightAttendant flightAttendant); //pass server, return tip amount
    //     3) play music
    void playMusic();
    
    FlightAttendant joseph;
    
    FlightAttendant nadine;
};

/*
Thing 8) Restroom
5 properties:
    1) room height (float)
    2) sink depth (float)
    3) flush volume in decibels (float)
    4) number of plies in toilet paper (int)
    5) soap brand (std::string)
3 things it can do:
    1) flow sink water
    2) illuminate room
    3) move load to tank
*/
struct Restroom
{
    // 5 properties:
    //     1) room height (float)
    float roomHeight = 120.0f;
    //     2) sink depth (float)
    float sinkDepth = 0.1f;
    //     3) flush volume in decibels (float)
    float flushVolumeInDecibels = 150.0f;
    //     4) number of plies in toilet paper (int)
    int numberOfPliesInToiletPaper = 1;
    //     5) soap brand (std::string)
    std::string soapBrand = "Sergeant Scrub";
    
    // 3 things it can do:
    //     1) flow sink water
    void flowSinkWater();
    //     2) illuminate room
    void illuminateRoom(float newLevel);
    //     3) move load to tank
    float moveLoadToTank();//return tank level
};

/*
Thing 9) Engine
5 properties:
    1) number of cylinders (int)
    2) type of fuel (std::string)
    3) chamber pressure (float)
    4) maximum temperature (float)
    5) material (std::string)
3 things it can do:
    1) suck in fuel
    2) combust fuel
    3) spin axle
*/
struct Engine
{
    // 5 properties:
    //     1) number of cylinders (int)
    int numberOfCylinders = 6;
    //     2) type of fuel (std::string)
    std::string typeOfFuel = "Jet Fuel";
    //     3) chamber pressure (float)
    float chamberPressure = 14.7f;
    //     4) maximum temperature (float)
    float maximumTemperature = 451.0f;
    //     5) material (std::string)
    std::string material = "Gold";
    
    // 3 things it can do:
    //     1) suck in fuel
    void suckInFuel();
    //     2) combust fuel
    void combustFuel();
    //     3) spin axle
    float spinAxle(); //return axle rpm
};

/*
Thing 10) Airplane
5 properties:
    1) wing (Wing)
    2) cockpit (Cockpit)
    3) cabin (Cabin)
    4) restroom (Restroom)
    5) engine (Engine)
3 things it can do:
    1) takeoff
    2) turn
    3) ping radar
*/
struct Airplane
{
    // 5 properties:
    //     1) wing (Wing)
    Wing wing;
    //     2) cockpit (Cockpit)
    Cockpit cockpit;
    //     3) cabin (Cabin)
    Cabin cabin;
    //     4) restroom (Restroom)
    Restroom restroom;
    //     5) engine (Engine)
    Engine engine;
    
    // 3 things it can do:
    //     1) takeoff
    void takeoff();
    //     2) turn
    void turn(float angle);
    //     3) ping radar
    float pingRadar();//return distance from object
};


int main()
{
    std::cout << "good to go!" << std::endl;
}
