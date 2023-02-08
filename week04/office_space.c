// Office Space Calculator
// Carson Cheung, Gabriel Krumlauf
// 1/30/23

#include <stdio.h>

int main()
{
    // Define Terms
#define PRIVATEOFFICESPACE 150;
#define KITCHENSPACE 200;
#define CONFERENCEROOM 250;
#define SPACEPEREMPLOYEE 200;
#define UTILITYROOMSPACE 300;

    int numOfEmployees, numOfKitchens, numOfPrivateOffices, numOfConferenceRooms, numOfUtilityRooms;
    int workSpace, privateOfficeSpace, conferenceRoomSpace, kitchenSpace, utilityRoomSpace, totalSpace;

    // Inputs
    printf("Enter how many employees you have: ");
    scanf("%d", &numOfEmployees);

    printf("\nNumber of kitchens: ");
    scanf("%d", &numOfKitchens);

    printf("\nNumber of private offices: ");
    scanf("%d", &numOfPrivateOffices);

    printf("\nNumber of conference rooms: ");
    scanf("%d", &numOfConferenceRooms);

    printf("\nNumber of utility rooms: ");
    scanf("%d", &numOfUtilityRooms);

    // Calculations
    workSpace = numOfEmployees * SPACEPEREMPLOYEE;
    privateOfficeSpace = numOfPrivateOffices * PRIVATEOFFICESPACE;
    conferenceRoomSpace = numOfConferenceRooms * CONFERENCEROOM;
    kitchenSpace = numOfKitchens * KITCHENSPACE;
    utilityRoomSpace = numOfUtilityRooms * UTILITYROOMSPACE;
    totalSpace = workSpace + privateOfficeSpace + conferenceRoomSpace + kitchenSpace + utilityRoomSpace;

    // Output
    printf("\nTotal Space Recommended: %d Sqft\n", totalSpace);
    printf("Work Space: %d Sqft\n", workSpace);
    printf("Private Office: %d Sqft\n", privateOfficeSpace);
    printf("Conference Room: %d Sqft\n", conferenceRoomSpace);
    printf("Kitchen: %d Sqft\n", kitchenSpace);
    printf("Utility Room: %d Sqft\n", utilityRoomSpace);
}