<?php 

//Define the maximum speed limit a user is allowed to cycle
$maxSpeedLimit = 10;

//Function to check current Speed Limit
function checkSpeedLimit(){
	//Get the current speed limit 
	global $maxSpeedLimit;
	$currentSpeedLimit = getCurrentSpeedLimit();

	//Compare the current speed limit with the maximum allowed
	if($currentSpeedLimit > $maxSpeedLimit){
		//Notify the user if they are over the speed limit 
		alertUser("You are over the speed limit. Please slow down."); 
	}
}

//Function to get the current speed limit
function getCurrentSpeedLimit(){
	//Gets the speed limit from an API 
	$url = 'http://api.openstreetmap.org/speedlimit';
	$ch = curl_init();
	curl_setopt($ch, CURLOPT_URL, $url);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1); 
	$output = curl_exec($ch);
	curl_close($ch);

	//Returns the current speed limit
	return $output; 	
}

//Function to notify the user if they are over the speed limit
function alertUser($message){
	//Sends an alert to the user's phone using an API
	$url = 'http://api.phone.com/send-alert';
	$ch = curl_init();
	curl_setopt($ch, CURLOPT_URL, $url);
	curl_setopt($ch, CURLOPT_POST, 1); 
	curl_setopt($ch, CURLOPT_POSTFIELDS, "message=".$message);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1); 
	$output = curl_exec($ch);
	curl_close($ch);
}

//Function to determine the safest route
function determineSafeRoute(){
	//Gets the map data from an API 
	$url = 'http://api.openstreetmap.org/mapdata';
	$ch = curl_init();
	curl_setopt($ch, CURLOPT_URL, $url);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1); 
	$output = curl_exec($ch);
	curl_close($ch);

	//Parses the map data for the safest route
	$mapData = json_decode($output);
	$safeRoute = $mapData->safestRoute;

	//Returns the safest route
	return $safeRoute;
}

//Function to alert the user when they approach an obstacle
function alertObstacle(){
	//Gets the location of obstacles on the route from an API 
	$url = 'http://api.openstreetmap.org/obstacles';
	$ch = curl_init();
	curl_setopt($ch, CURLOPT_URL, $url);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1); 
	$output = curl_exec($ch);
	curl_close($ch);

	//Parses the map data for the location of obstacles 
	$obstacleData = json_decode($output);
	$obstacleLocation = $obstacleData->location;

	//Checks if the user is approaching an obstacle 
	$userLocation = getUserLocation();
	$distanceToObstacle = calculateDistance($userLocation, $obstacleLocation);

	if($distanceToObstacle <= 10){
		//Notify the user if they are close to an obstacle 
		alertUser("You are approaching an obstacle. Please take caution."); 
	}	
}


//Function to get the user's current location 
function getUserLocation(){
	//Gets the user's location from an API 
	$url = 'http://api.phone.com/get-location';
	$ch = curl_init();
	curl_setopt($ch, CURLOPT_URL, $url);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1); 
	$output = curl_exec($ch);
	curl_close($ch);

	//Returns the user's current location
	return $output; 
}

//Function to calculate the distance between two locations 
function calculateDistance($location1, $location2){
	//Gets the distance between two locations from an API 
	$url = 'http://api.openstreetmap.org/distance';
	$ch = curl_init();
	curl_setopt($ch, CURLOPT_URL, $url);
	curl_setopt($ch, CURLOPT_POST, 1); 
	curl_setopt($ch, CURLOPT_POSTFIELDS, "location1=".$location1."&location2=".$location2);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1); 
	$output = curl_exec($ch);
	curl_close($ch);

	//Returns the distance between two locations
	return $output; 
}

//Main loop
while(true){
	checkSpeedLimit();
	determineSafeRoute();
	alertObstacle();
}

?>