#Importing the necessary modules
import math
import time

#Creating a class 'CycleSafe'
class CycleSafe:
    
    #initializing the class variables
    def __init__(self,speed,distance,time):
        self.speed = speed
        self.distance = distance
        self.time = time
    
    #Calculating the speed
    def getSpeed(self):
        return self.speed
    
    #Calculating the distance
    def getDistance(self):
        return self.distance
    
    #Calculating the time
    def getTime(self):
        return self.time
    
    #Calculating the total distance
    def calculateDistance (self):
        dist = self.speed * self.time
        return dist
    
    #Calculating the remaining distance
    def calculateRemainingDistance (self):
        rem_dist = self.distance - self.calculateDistance()
        return rem_dist
    
    #Calculating the time left to complete the journey
    def calculateTimeLeft (self):
        time_left = self.calculateRemainingDistance/self.speed
        return time_left 
    
    #Checking if the journey is completed
    def isJourneyCompleted (self):
        if self.calculateRemainingDistance() <= 0:
            return True
        else:
            return False

# Creating an object 'cycle'
cycle = CycleSafe(60,100,2)

#Calculating the total distance
total_dist = cycle.calculateDistance()
print("Total Distance Travelled:",total_dist)

#Calculating the remaining distance
rem_dist = cycle.calculateRemainingDistance()
print("Remaining Distance: ",rem_dist)

#Calculating the time left to complete the journey
time_left = cycle.calculateTimeLeft()
print("Time Left to Complete Journey: ",time_left)

#Checking if the journey is completed
if cycle.isJourneyCompleted():
    print("Journey Completed!")
else:
    print("Journey still left to complete!")
    
#Adding a safety measure
#Creating a timer
start_time = time.time()
while(True):
    cycle_time = time.time() - start_time
    if cycle_time > time_left:
        print("Time Up! Journey Stopped")
        break
    else:
        time.sleep(1)