--Set up a global variable to track how many cycles have been safely performed
cyclesCompleted = 0

--This function will start the cycle-safe procedure
--This should be called to begin the process
function cycleSafe()
    --trigger physical action
    doHardwareAction()
    --Wait for the hardware action to complete
    waitForHardwareComplete()
    --update the global cycle count
    cyclesCompleted = cyclesCompleted + 1
    --Print out a completion message
    print('Cycle ' .. cyclesCompleted .. ' completed safely!')
end

--Create a function to call the hardware action
function doHardwareAction()
    --call the hardware action here
end

--Create a function to wait for the hardware action to complete
function waitForHardwareComplete()
    --loop while the hardware action is ongoing
    while(hardwareActionInProgress()) do
        --wait until the hardware action is complete
        waitForHWActionComplete()
    end
end

--Create a function to check if hardware action is still in progress
function hardwareActionInProgress()
    --check if hardware action is still in progress
    return hardwareActionState == 'In Progress'
end

--Create a function to wait for the hardware action to complete
function waitForHWActionComplete()
    --wait for the hardware action to complete
    wait(100)
end

--Run the cycle-safe procedure
cycleSafe()