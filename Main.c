
#include <stdbool.h>
#include <stdio.h>
#include <wiringPi.h>

// these are based on the wiringPi pin numbers
#define YELLOW_PIN 26 // GPIO 12
#define GREEN_PIN 27  // GPIO 16
#define BLUE_PIN 28   // GPIO 20
#define RED_PIN 29    // GPIO 21

#define MOTION_SENSOR_PIN 2 // GPIO 27

#define VIBRATION_PIN 0 // GPIO 17

#define BUTTON_PIN 1 // GPIO 18

enum LED_STATE
{
    BLANK = 0,
    YELLOW,
    GREEN,
    BLUE,
    RED,
    NUM_LEDS
};

int main(int argc, char *argv[])
{
    printf("Starting program \n");
    printf("Number of arguments: %d\n", argc);

    printf("Program name: %s\n", argv[0]); // argv[0] holds the program name

    for (int i = 1; i < argc; i++)
    { // Iterate through arguments starting from index 1
        printf("Argument %d: %s\n", i, argv[i]);
    }

    wiringPiSetup();

    pinMode(YELLOW_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    pinMode(RED_PIN, OUTPUT);

    pinMode(BUTTON_PIN, INPUT);
    pullUpDnControl(BUTTON_PIN, PUD_UP);

    pinMode(MOTION_SENSOR_PIN, INPUT);

    pinMode(VIBRATION_PIN, OUTPUT);

    enum LED_STATE ledState = BLANK;
    digitalWrite(YELLOW_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
    digitalWrite(RED_PIN, LOW);
    bool buttonPressed = false;

    while (1)
    {
        if (digitalRead(MOTION_SENSOR_PIN) == HIGH)
        {
            printf("Motion detected!\n");

            digitalWrite(YELLOW_PIN, HIGH);

            digitalWrite(VIBRATION_PIN, HIGH);
            delay(2000);
            digitalWrite(VIBRATION_PIN, LOW);
        }
        else
        {
            digitalWrite(YELLOW_PIN, LOW);
        }
    }

    return 0;
}
