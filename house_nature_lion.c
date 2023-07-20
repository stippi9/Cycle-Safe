#include <stdio.h>
#include <stdbool.h>

/* Constants defining maximum possible values */ 
#define MAX_CYCLIST 100
#define MAX_STREET_LEN 30

/* Struct for cyclist data */ 
typedef struct cyclist {
    int id; 
    int age; 
    bool helmet; 
    int bike_type;
    char street[MAX_STREET_LEN]; 
} cyclist; 

/* Constants defining possible bike types */ 
#define MOUNTAIN_BIKE 0
#define ROAD_BIKE 1
#define BMX_BIKE 2
#define CRUISER_BIKE 3
#define ELECTRIC_BIKE 4

/* Array to store cyclist data */
cyclist cyclists[MAX_CYCLIST]; 
int cyclist_count = 0; 

/* Function to add cyclist to array */ 
void add_cyclist(int age, bool helmet, int bike_type, char street[MAX_STREET_LEN]) {
    cyclist c; 
    c.id = cyclist_count; 
    c.age = age; 
    c.helmet = helmet; 
    c.bike_type = bike_type; 
    strncpy(street, c.street, MAX_STREET_LEN); 
    cyclists[cyclist_count] = c; 
    cyclist_count++; 
}

/* Function to remove cyclist from array */
void remove_cyclist(int id) {
    for (int i = 0; i < cyclist_count; i++) {
        if (cyclists[i].id == id) {
            for (int j = i; i < cyclist_count - 1; i++) {
                cyclists[i] = cyclists[i + 1]; 
            }
            cyclist_count--; 
            break; 
        }
    }
}

/* Function to retrieve cyclist from array */ 
cyclist get_cyclist(int id) {
    for (int i = 0; i < cyclist_count; i++) {
        if (cyclists[i].id == id) {
            return cyclists[i]; 
        }
    }
    return {0, 0, false, 0, ""}; 
}

/* Function to validate cycling conditions and return safety rating */ 
int validate_safety_rating(int age, bool helmet, int bike_type, char street[MAX_STREET_LEN]) {
    if (age < 18 || age > 65) {
        // Age not suitable for cycling 
        return 0;
    }
    else if (!helmet) {
        // Helmet not worn
        return 1; 
    }
    else if (bike_type != MOUNTAIN_BIKE && bike_type != ROAD_BIKE) {
        // Unsuitable bike type 
        return 2; 
    } 
    else if (strlen(street) == 0) {
        // No street given
        return 3; 
    }
    else {
        // All conditions satisfied 
        return 4; 
    }
}

/* Main function to cycle-safe */ 
int main() {
    int age, bike_type; 
    bool helmet; 
    char street[MAX_STREET_LEN]; 

    printf("Enter age of cyclist: "); 
    scanf("%d", &age); 
    printf("Wearing a helmet (true/false): "); 
    scanf("%d", &helmet); 
    printf("Choose bike type (0-Mountain Bike, 1-Road Bike, 2-BMX Bike, 3-Cruiser Bike, 4-Electric Bike): "); 
    scanf("%d", &bike_type); 
    printf("Enter street: "); 
    scanf("%s", street); 

    int safety_rating = validate_safety_rating(age, helmet, bike_type, street); 

    if (safety_rating == 4) {
        add_cyclist(age, helmet, bike_type, street);
        printf("Cyclist added with ID %d\n", cyclist_count - 1); 
    }
    else {
        printf("Cyclist not safe\n");
    }

    return 0; 
}