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
    pinMode(boardLed, OUTPUT);
    blinkTimer.start();
    
    // Exercise 3: Led web function
    pinMode(externalLed, OUTPUT);
    Particle.function("SetLed", LedFunction);
    
    // Exercise 4: Sensor web variable.
    pinMode(sensorEnable, OUTPUT);
    pinMode(sensorInput, INPUT);
    digitalWrite(sensorEnable, HIGH);
    Particle.variable("SensorValue", sensorValue);
    
    // Exercise 5: Subscribe to night Event.
    Particle.subscribe("NightEvent", SubscriptionHandler, ALL_DEVICES);
    Particle.function("InstructorPublishNightEvent", InstructorPublishNightEvent);
}

void loop()
{
    // Exercise 4: populate the sensor web variable.
    sensorValue = analogRead(sensorInput);
    
}

// Exercise 3: The function is called through the web API to control the LED.
// If the incoming command is "ON", turn on the LED and return 0.
// If the incoming command is "OFF", turn off the LED and return 1.
// Otherwise return -1    
int LedFunction(String command)
{
    if(command.equals("ON"))
    {
        digitalWrite(externalLed, HIGH);
        return 0;
    }
    else if(command.equals("OFF"))
    {
        digitalWrite(externalLed, LOW);
        return 1;
    }
    else
    {
        return -1;
    }
}

// Exercise 4: This subscription function is called when the "photoStatus" event is published.
//If the received data is "ON", turn LEDs on and stop the blink timer.
//If the received data is "OFF", turn LEDs off and start the blink timer.
void SubscriptionHandler(const char *event, const char *data)
{
    String command = String(data);
    
    if(command.equals("ON"))
    {
        blinkTimer.stop();
        digitalWrite(boardLed, HIGH);
        digitalWrite(externalLed, HIGH);
    }
    else if(command.equals("OFF"))
    {
        blinkTimer.start();
        digitalWrite(boardLed, LOW);
        digitalWrite(externalLed, LOW);
    }
}

// Exercise 2: Timer callback function to blink the on-board LED,
void Blink(void)
{
    boardLedState = !boardLedState;
    digitalWrite(boardLed, boardLedState);
}

// Exercise 4: Public function for instructors to publish the NightEvent, which will 
// turn the LEDs on for all subscribed particles in the class.
int InstructorPublishNightEvent(String command)
{
    Particle.publish("NightEvent", command);
}
