// File: CycleSafe.ts 

// Imports
import { Bikes, Bikers } from "./CycleData"

// Function to check if biker is wearing a helmet
function isWearingHelmet(biker: Bikers): boolean {
	let helmetStatus: boolean = false;

  	if (biker.helmet) {
    	helmetStatus = true;
  	}

  	return helmetStatus;
}

// Function to check if biker is wearing proper lights
function isUsingProperLights(biker: Bikers): boolean {
	let lightStatus: boolean = false;

	if (biker.light) {
    	lightStatus = true;
  	}

  	return lightStatus;
}

// Function to check if biker is using functioning brakes
function isUsingFunctioningBrakes(bike: Bikes): boolean {
	let brakesFuntional: boolean = false;

  	if (bike.brakes) {
    	brakesFuntional = true;
  	}

  	return brakesFuntional;
}

// Function to check if biker is wearing reflective clothing
function isWearingReflectiveClothing(biker: Bikers): boolean {
	let reflectiveStatus: boolean = false;

	if (biker.reflectiveClothing) {
    	reflectiveStatus = true;
  	}

  	return reflectiveStatus;
}

// Function to check if biker is staying in bike lane
function isBikerInBikeLane(biker: Bikers): boolean {
	let bikeLaneStatus: boolean = false;

	if (biker.bikeLane) {
    	bikeLaneStatus = true;
  	}

  	return bikeLaneStatus;
}

// Function to validate all safety measures for a biker
export function validateCycleSafety(biker: Bikers, bike: Bikes): boolean {
	let helmet: boolean = isWearingHelmet(biker);
  	let light: boolean = isUsingProperLights(biker);
  	let brakes: boolean = isUsingFunctioningBrakes(bike);
  	let reflective: boolean = isWearingReflectiveClothing(biker);
  	let bikeLane: boolean = isBikerInBikeLane(biker);
  
  	let validCycleSafety: boolean = false;

  	if (helmet && light && brakes && reflective && bikeLane) {
    	validCycleSafety = true;
  	}

  	return validCycleSafety;
}