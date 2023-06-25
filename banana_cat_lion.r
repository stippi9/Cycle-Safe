#Step 1: Read in data
data <- read.csv('safe_cycling.csv')

#Step 2: Create a summary of the data
summary(data)

#Step 3: Plot the data
# Scatter plot
plot(data$distance_travelled, data$accidents, main="Distance Travelled vs Accidents", 
	xlab="Distance Travelled (km)", ylab="Number of Accidents")

#Step 4: Fit a linear model
fit <- lm(accidents ~ distance_travelled, data=data)
summary(fit)

#Step 5: Estimate the coefficient and create an equation 
coef <- coefficients(fit)
linear_eqn <- paste("accidents =", round(coef[1],3), "+", round(coef[2],3),"*distance_travelled")
linear_eqn

#Step 6: Plot the linear model
plot(data$distance_travelled, data$accidents, main="Distance Travelled vs Accidents", 
	xlab="Distance Travelled (km)", ylab="Number of Accidents")
abline(coef[1], coef[2], col="red")

#Step 7: Predict the number of accidents at a given distance
distance <- 500  # Distance travelled (in km)
accidents_predicted <- coef[1] + coef[2] * distance

#Step 8: Validate the model
validate <- predict(fit, newdata=data)
error_ssr <- mean((data$accidents - validate)^2)

#Step 9: Compute R-squared
rsq <- 1 - (sum((validate - data$accidents)^2) / sum((data$accidents - mean(data$accidents))^2))

#Step 10: Create a data frame for plotting the model
data_frame <- data.frame(distance_travelled=data$distance_travelled, accidents=data$accidents, 
	validate=validate)

#Step 11: Plot the model
plot(data_frame$distance_travelled, data_frame$accidents, type="n", 
	main="Distance Travelled vs Accidents", 
	xlab="Distance Travelled (km)", ylab="Number of Accidents")
lines(data_frame$distance_travelled, data_frame$validate, col="red")

#Step 12: Output the results 
cat("R-squared:", rsq, "\n")
cat("Error sum of squares:", error_ssr, "\n")
cat("Linear equation:", linear_eqn, "\n")
cat("Predicted number of accidents at a distance of 500 km:", accidents_predicted)