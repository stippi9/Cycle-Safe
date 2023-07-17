%This Matlab code allows a user to practice 'Cycle Safe'

%Clearing screen, closing all figures
clc;
close all;

%Initializing variables 
i = 1;
counter = 0;

%Main loop
while i<=2000
    if counter < 10
        %Simulating traffic condition
        traffic = round(rand(1));
        %Prompt user to proceed
        if traffic == 0
            fprintf('Proceed to Cycle Safe\n');
            counter = counter + 1;
        elseif traffic == 1
            fprintf('Wait for Traffic Condition to clear to Cycle Safe\n');
        end
      
    else
        break;
    end
    i = i+1;
end

%Printing the message
fprintf('Congratulations!! You have completed Cycle Safe\n');