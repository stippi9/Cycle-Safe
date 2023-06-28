#Vectors to store data
bikedist.matrix <- matrix(NA, nrow = 2000, ncol = 4)

#Looping to populate the matrix with the bike distance information
for (i in 1:2000) {
  bikedist.matrix[i,1] <- sample(10:50,1)
  bikedist.matrix[i,2] <- sample(50:100,1)
  bikedist.matrix[i,3] <- sample(50:100,1)
  bikedist.matrix[i,4] <- sample(10:50,1)
}

#Transpose the matrix 
bikedist.transpose <- t(bikedist.matrix)

#Calculating the total distance 
totaldistance <- colSums(bikedist.transpose)

#Compute the average speed 
average.speed <- totaldistance/3.6

#Compute the number of trips 
num.trips <- sample(5:20,1)

#Compute the total time
total.time <- num.trips * (average.speed/60)

#Calculate the time taken for each trip
time.each.trip <- total.time/num.trips

#Calculate the time taken for each leg
time.each.leg <- time.each.trip/4

#Calculate the distance for each leg
distance.each.leg <- bikedist.matrix/time.each.leg

#Calculate the time taken for each leg
time.each.leg <- bikedist.matrix/distance.each.leg

#Calculate total distance traveled
total.distance <- rowSums(bikedist.matrix)

#Calculate total time taken 
total.time <- total.distance/average.speed

#Calculate average speed
average.speed <- total.distance/(num.trips*time.each.trip)

#Create a dataframe of the results
cycle.stats <- data.frame(totaldistance, num.trips, total.time, time.each.trip, 
time.each.leg, distance.each.leg, total.distance, average.speed)

#Print the results
print(cycle.stats)