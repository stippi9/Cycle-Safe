// ----------------------------------------------

// Library imports
use std::sync::{Mutex, Arc};
use std::thread;
use std::time::Duration;

// Defines the structure of the Lock, which allows multiple threads to execute a code block
// simultaneously
struct Lock {
    count: u8,
    guard: Mutex<u8>,
}

// Creates a Lock instance
fn create_lock() -> Lock {
    Lock {
        count: 0,
        guard: Mutex::new(0),
    }
}

// Defines the entry point into the program
fn main() {
	// Initializes a Lock instance
    let lock = Arc::new(create_lock());

    // Spawns a thread
    let thread_one = thread::spawn(move || {
        // Defines the code to be executed
        println!("Thread One started.");

        // Acquires the lock
        let mut guard = lock.guard.lock().unwrap();

        // Waits for the signal
        *guard += 1;

        // Executes the given code
        println!("Thread One cycled safely.");

        // Releases the lock
        *guard -= 1;
    });

    // Spawns an additional thread
    let thread_two = thread::spawn(move || {
        // Defines the code to be executed
        println!("Thread Two started.");

        // Acquires the lock
        let mut guard = lock.guard.lock().unwrap();

        // Waits for the signal
        while *guard == 0 {}

        // Executes the given code
        println!("Thread Two cycled safely.");

        // Releases the lock
        *guard -= 1;
    });

    // Waits until the threads finish executing
    thread_one.join().unwrap();
    thread_two.join().unwrap();

    // Terminates the program
    println!("Threads completed.");
}