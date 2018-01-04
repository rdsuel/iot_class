// -----------------------------------
// Internet Of Things Class
// -----------------------------------

// Variables


void setup()
{
    // Setup GPIO pins.

    // Enable the sensor.

    // Particle API configuration:
    // Exercise 2: expose the "led" function for controlling the LED over the web.
    // Exercise 3: expose the "photoValue" variable for reading over the web.
    // Exercise 4: subscribe to the "photoStatus" event for communicating with other devices.
}

void loop()
{
    // Exercise 3: Read the sensor and update the web variable.

    // Exercise 4: Publish the "photoStatus" event here with the following value when:
    // NOTE: Instructors only.
    // > 400 = "DAY"
    // < 300 = "NIGHT"
}

// Exercise 2: The function is called through the web API to control the LED.
int LedFunction(String command)
{
    // If the incoming command is "ON", turn on the LED and return 0.
    // If the incoming command is "OFF", turn off the LED and return 1.
    // Otherwise return -1
}

// Exercise 4: This subscription function is called when the "photoStatus" event is published.
void SubscriptionHandler(const char *event, const char *data)
{
    //If the received data is "NIGHT", turn the on-board LED on.
    //If the received data is "DAY", turn the on-board LED off.
    // Hint: use strcmp
}
