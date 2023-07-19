%Cycle Safe MATLAB Function 

%Input: 
%	Road between two points 

%Output: 
%	Optimized route to ensure the maximum safety for the cyclist 

%Define Constants
SPEED_LIMIT = 50; %km/h 
ACCELERATION = 5; %km/h/s
MIN_DISTANCE = 10; %feet
SEGMENT_LENGTH = 30; %m 

% Read road from input file
fileID = fopen('Road.txt','r'); 
roadData = textscan(fileID, '%s %f %f %f');
fclose(fileID); 

%Get original coordinates of the road
originXcoord = roadData{2}; 
originYcoord = roadData{3}; 

%Compute distance between each coordinate point
distances = sqrt(diff(originYcoord).^2 + diff(originXcoord).^2);

%Optimize route to ensure safety 
optimizedRoute = zeros(length(distances),2); 
cumulativeDistance = 0; 

%For each segment of the road
for i = 1:length(distances)
    % Set the final point of the segment 
    optimizedRoute(i,1) = originXcoord(i+1); 
    optimizedRoute(i,2) = originYcoord(i+1);
    
    % Set the initial point of the segment 
    optimizedRoute(i,1) = optimizedRoute(i,1) - (distances(i)-SEGMENT_LENGTH)/2;
    optimizedRoute(i,2) = optimizedRoute(i,2) - (distances(i)-SEGMENT_LENGTH)/2;
    
    % Calculate cumulative distance 
    cumulativeDistance = cumulativeDistance + distances(i);  
    
    % Set the segment distance speed limit 
    speedLimit = min(SPEED_LIMIT, cumulativeDistance/ACCELERATION);
    
    % Check if cyclist can stop safely before reaching the end of the segment 
    if speedLimit*ACCELERATION < (SEGMENT_LENGTH-MIN_DISTANCE)
        % Align segment length with the safety distance
        optimizedRoute(i,1) = optimizedRoute(i,1) + SEGMENT_LENGTH - (SEGMENT_LENGTH-MIN_DISTANCE)/2;
        optimizedRoute(i,2) = optimizedRoute(i,2) + SEGMENT_LENGTH - (SEGMENT_LENGTH-MIN_DISTANCE)/2;
    end 
end 

%Save optimized route 
fileID = fopen('OptimizedRoute.txt','w'); 
fprintf(fileID, '%f %f\n', optimizedRoute');
fclose(fileID);