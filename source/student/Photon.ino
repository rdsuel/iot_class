// -----------------------------------
// Internet Of Things Class
// -----------------------------------

// Variables
// Exercise 2: Blink the on-board LED at 60Hz.
int boardLed = D7;
bool boardLedState = LOW;
Timer blinkTimer(500, Blink);

// Exercise 3: Control external led with web function.
int externalLed = D0;

// Exercise 4: Read the light sensor with web variable.
int sensorEnable = A5;
int sensorInput = A0;
int sensorValue = 0;

void setup()
{
    // Exercise 2: Blink the on-board LED
    
    // Exercise 3: Led web function
    
    // Exercise 4: Sensor web variable.
    
    // Exercise 5: Subscribe to night Event.
}

void loop()
{
    // Exercise 4: populate the sensor web variable.   
}

// Exercise 3: The function is called through the web API to control the LED.
// If the incoming command is "ON", turn on the LED and return 0.
// If the incoming command is "OFF", turn off the LED and return 1.
// Otherwise return -1    
int LedFunction(String command)
{

}

// Exercise 4: This subscription function is called when the "NightEvent" event is published.
//If the received data is "ON", turn LEDs on and stop the blink timer.
//If the received data is "OFF", turn LEDs off and start the blink timer.
void SubscriptionHandler(const char *event, const char *data)
{

}

// Exercise 2: Timer callback function to blink the on-board LED,
void Blink(void)
{
    
}
