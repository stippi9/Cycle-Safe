import scala.collection.mutable.ListBuffer 

// A helper function which checks whether an element exists in the given list
def checkExists(list: ListBuffer[Int], element: Int): Boolean = { 
    var i = 0 
    var result = false 
    while (i < list.length) {
        if (list(i) == element) {
            result = true
            break
        }
        i += 1
    }
    return result
}

// A function that takes a list of integers and checks whether it is safe to cycle through (has no repetition)
def isCycleSafe(list: ListBuffer[Int]): Boolean = { 
    var i = 0
    var result = true
    while (i < list.length) {
        if (checkExists(list.slice(i + 1, list.length), list(i)) == true) {
            result = false
            break
        }
        i += 1
    }
    return result
}

// A function that takes a list of lists of integers and returns the number of cycle safe lists
def cycleSafe(lists: ListBuffer[ListBuffer[Int]]): Int = {
    var i = 0
    var count = 0
    while (i < lists.length) {
        if (isCycleSafe(lists(i)) == true) {
            count += 1
        }
        i += 1
    }
    return count
}

// Driver Program 
object CycleSafe {
    // Main Function 
    def main(args: Array[String]) { 
        var list1 = new ListBuffer[Int]()
        list1 += 1
        list1 += 2
        list1 += 3
        list1 += 4
        list1 += 5
  
        var list2 = new ListBuffer[Int]()
        list2 += 5
        list2 += 5
        list2 += 6
        list2 += 7
        list2 += 8
  
        var list3 = new ListBuffer[Int]() 
        list3 += 8
        list3 += 9
        list3 += 10
        list3 += 11
        list3 += 12
  
        var list4 = new ListBuffer[Int]()
        list4 += 4
        list4 += 5
        list4 += 6
        list4 += 7
        list4 += 5
  
        var lists = new ListBuffer[ListBuffer[Int]]()
        lists += list1
        lists += list2
        lists += list3
        lists += list4
  
        println("Number of cycle safe lists are " + cycleSafe(lists))
    } 
}