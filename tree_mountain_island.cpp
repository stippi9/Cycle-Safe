//Cycle Safe
//A C++ Program to ensure cyclists safety on the roads of India

#include <iostream> 
#include <cstdlib> 
#include <string> 
  
using namespace std; 
  
// function to check the speed of the cyclist 
void checkSpeed(int speed) 
{ 
    if (speed > 30) 
    { 
        cout << "Slow down! \n"; 
    } 
    else if (speed < 10) 
    { 
        cout << "Speed up! \n"; 
    } 
    else
    { 
        cout << "You are moving at a safe speed. \n"; 
    } 
} 
  
// function to check whether the cyclist is going in the right direction 
void checkDirection(string direction) 
{ 
    if (direction == "WRONG") 
    { 
        cout << "Turn around! \n"; 
    } 
    else if (direction == "RIGHT") 
    { 
        cout << "You are going in the right direction. \n"; 
    } 
    else
    { 
        cout << "Look at the road sign! \n"; 
    } 
} 
  
// function to check whether the cyclist is wearing a helmet 
void checkHelmet(bool iswearingHelmet) 
{ 
    if (!iswearingHelmet) 
    { 
        cout << "Start wearing a helmet! \n"; 
    } 
    else if (iswearingHelmet) 
    { 
        cout << "You are wearing the helmet. \n"; 
    } 
    else
    { 
        cout << "You should always wear a helmet. \n"; 
    } 
} 
  
// function to check whether the cyclist has lights on his vehicle 
void checkLights(bool isOn) 
{ 
    if (!isOn) 
    { 
        cout << "Turn the lights on! \n"; 
    } 
    else if (isOn) 
    { 
        cout << "Your vehicle has the lights on. \n"; 
    } 
    else
    { 
        cout << "You should use lights to be visible. \n"; 
    } 
} 
  
void checkMirror(bool isFitted) 
{ 
    if (!isFitted) 
    { 
        cout << "Please fit the mirror. \n"; 
    } 
    else if (isFitted) 
    { 
        cout << "Your vehicle has the mirror fitted. \n"; 
    } 
    else
    { 
        cout << "You should use a rear view mirror. \n"; 
    } 
} 
  
// function to check whether the cyclist is driving in the correct lane 
void checkLane(int lane) 
{ 
    if (lane == 1) 
    { 
        cout << "You should be in the correct lane. \n"; 
    } 
    else if (lane == 2) 
    { 
        cout << "You are in the wrong lane. \n"; 
    } 
    else if (lane == 0) 
    { 
        cout << "Look for the correct lane! \n"; 
    } 
    else
    { 
        cout << "You should always use the correct lane. \n"; 
    } 
} 
  
// function to check whether the cyclist is obeying traffic rules 
void checkRules(int indicator) 
{ 
    if (indicator == 1) 
    { 
        cout << "Use indication! \n"; 
    } 
    else if (indicator == 0) 
    { 
        cout << "You have not used an indicator. \n"; 
    } 
    else
    { 
        cout << "You should always obey the traffic rules. \n"; 
    } 
} 
  
// function to check whether the cyclist is following the correct route 
void checkRoute(string routeMarkers) 
{ 
    if (routeMarkers == "WRONG") 
    { 
        cout << "Follow the right route! \n"; 
    } 
    else if (routeMarkers == "RIGHT") 
    { 
        cout << "You are taking the correct route. \n"; 
    } 
    else
    { 
        cout << "Look for the route markers! \n"; 
    } 
} 
  
 // function to check whether the cyclist is 
// parking in a designated area 
void checkParking(bool isParked) 
{ 
    if (!isParked) 
    { 
        cout << "Park in the designated area! \n"; 
    } 
    else if (isParked) 
    { 
        cout << "You have parked your vehicle. \n"; 
    } 
    else
    { 
        cout << "You should always park in the designated area. \n"; 
    } 
} 
  
int main() 
{ 
    // initializing the variables 
    int speed, lane; 
    bool helmet, lights, isFitted, isParked; 
    string direction, routeMarkers; 
    int indicator; 
  
    // taking input from the user 
    cout << "Please enter the following parameters: \n"; 
    cout << "Speed: \n"; 
    cin >> speed; 
    cout << "Direction: \n"; 
    cin >> direction; 
    cout << "Is wearing helmet?: \n"; 
    cin >> helmet; 
    cout << "Are the lights on?: \n"; 
    cin >> lights; 
    cout << "Is the mirror fitted?: \n"; 
    cin >> isFitted; 
    cout << "Which lane are you in?: \n"; 
    cin >> lane; 
    cout << "Are you using the indication?: \n"; 
    cin >> indicator; 
    cout << "Are you taking the right route?: \n"; 
    cin >> routeMarkers; 
    cout << "Are you parking correctly?: \n"; 
    cin >> isParked; 
  
    // calling the functions to check the cyclists safety 
    checkSpeed(speed); 
    checkDirection(direction); 
    checkHelmet(helmet); 
    checkLights(lights); 
    checkMirror(isFitted); 
    checkLane(lane); 
    checkRules(indicator); 
    checkRoute(routeMarkers); 
    checkParking(isParked); 
  
    return 0; 
}