// Imports 
import java.util.Date 

// Class declaration 
class CycleSafe { 
  var totalCycles: Int = 0 
  var lastCheckDate: Date? = null 
    
    // Getter and setter methods 
     fun getTotalCycles(): Int { 
         return totalCycles 
     } 
     fun setTotalCycles(cycles: Int) { 
         this.totalCycles = cycles 
     } 
  
     fun getLastCheckDate(): Date? { 
         return lastCheckDate 
     } 
     fun setLastCheckDate(date: Date) { 
         this.lastCheckDate = date 
     } 
  
     // Function to add cycles 
     fun addCycles(cyclesToAdd: Int) { 
         totalCycles += cyclesToAdd 
     } 
  
     // Function to reset cycles 
     fun resetCycles() { 
         totalCycles = 0 
     } 
  
     // Function to check the cycle safety 
     fun checkCycles(): Boolean { 
         return totalCycles > 100 
     }
} 

// Main function 
fun main(args: Array<String>) { 
    var cycleSafe = CycleSafe() 

     // Check before adding any cycles 
     if (cycleSafe.checkCycles()) { 
         println("Cycle safety is already checked.") 
     } 

     // Adding cycles and checking again 
     cycleSafe.addCycles(50) 
     if (cycleSafe.checkCycles()) { 
         println("Cycle safety checked.") 
     } 

    // Resetting the cycles 
    cycleSafe.resetCycles() 
    println("Cycles reset successfully.") 
}