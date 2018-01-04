// -----------------------------------
// Internet Of Things Class
// -----------------------------------

// Variables
int boardLed = D7;
int externalLed = D0;
int sensorEnablePin = A5;
int sensorInputPin = A0;
int sensorValue = 0;
bool dark = false;


void setup()
{
    // Setup GPIO pins.
    pinMode(boardLed, OUTPUT);
    pinMode(externalLed, OUTPUT);
    pinMode(sensorEnablePin, OUTPUT);

    // Enable the sensor.
    digitalWrite(sensorEnablePin, HIGH);

    // Particle API configuration:
    // Exercise 2: expose the "led" function for controlling the LED over the web.
    Particle.function("led", LedFunction);

    // Exercise 3: expose the "photoValue" variable for reading over the web.
    Particle.variable("photoValue", sensorValue);

    // Exercise 4: subscribe to the "photoStatus" event for communicating with other devices.
    Particle.subscribe("photoStatus", SubscriptionHandler);
}

void loop()
{
    // Exercise 3: Read the sensor and update the web variable.
    sensorValue = analogRead(sensorInputPin);

    // Exercise 4: Publish the "photoStatus" event here with the following value when:
    // NOTE: Instructors only.
    // > 400 = "DAY"
    // < 300 = "NIGHT"
    if ((sensorValue < 300) && (dark == false))
    {
        dark = true;
        Particle.publish("photoStatus", "NIGHT");
    }
    else if ((sensorValue > 400) && (dark == true))
    {
        dark = false;
        Particle.publish("photoStatus", "DAY");
    }
}

// Exercise 2: The function is called through the web API to control the LED.
int LedFunction(String command)
{
    //If the incoming command is "ON", turn on the LED and return 0.
    if (command == "ON")
    {
        digitalWrite(externalLed, HIGH);
        return 0;
    }
    //If the incoming command is "OFF", turn off the LED and return 1.
    else if (command == "OFF")
    {
        digitalWrite(externalLed, LOW);
        return 1;
    }

    //Otherwise return -1
    return -1;
}

// Exercise 4: This subscription function is called when the "photoStatus" event is published.
void SubscriptionHandler(const char *event, const char *data)
{
    //If the received data is "NIGHT", turn the on-board LED on.
    //If the received data is "DAY", turn the on-board LED off.
    // Hint: use strcmp
    if (strcmp(data, "NIGHT")==0)
    {
        digitalWrite(boardLed, HIGH);
    }
    else if (strcmp(data, "DAY")==0)
    {
        digitalWrite(boardLed, LOW);
    }
}
