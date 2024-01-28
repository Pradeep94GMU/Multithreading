#include <stdio.h>
#include <unistd.h>

void operatePathALights(int greenDurationSec) {
    printf("Path A Green Light\n");
    sleep(greenDurationSec);

    printf("Path A Yellow Light\n");
    sleep(5);

    printf("Path A Red Light\n");
    sleep(5); 
}

void operatePathBLights(int greenDurationSec) {
    printf("Path B Red Light\n");
    sleep(5); // Wait for Path A's green and yellow lights

    printf("Path B Green Light\n");
    sleep(greenDurationSec);

    printf("Path B Yellow Light\n");
    sleep(5);
}

int main() {
    float greenDurationMin;
    printf("Enter the duration of the Green Light (in minutes, can be fractional): ");
    scanf("%f", &greenDurationMin);

    int greenDurationSec = (int)(greenDurationMin * 60);

    while(1) {
        operatePathALights(greenDurationSec);
        operatePathBLights(greenDurationSec);
    }
    return 0;
}
