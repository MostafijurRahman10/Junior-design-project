

#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.

const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED13 = 13;          // The on-board Arduino LED, close to PIN 13.
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore.
                               // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
                               // Otherwise leave the default "550" value. 
const int sensor=A5; // Assigning analog pin A5 to variable 'sensor'
float tempc; //variable to store temperature in degree Celsius
float tempf;
float vout; //temporary variable to hold sensor reading

PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"


void setup() {
pinMode(sensor,INPUT); // Configuring sensor pin as input
Serial.begin(9600);
// Configure the PulseSensor object, by assigning our variables to it. 
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED13);       //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);   
  pulseSensor.begin() ;//calling the "pulse sensor" object.
     
}

void loop() {
  int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
                                               // "myBPM" hold this BPM value now. 
  vout=analogRead(sensor); //Reading the value from sensor
  vout=(5*vout*100/1024)  ; 
  tempc=vout; // Storing value in Degree Celsius
  Serial.print("Temperature:");
  Serial.print(tempc);
  Serial.print(" and ");
  if (pulseSensor.sawStartOfBeat()) {            // Constantly test to see if "a beat happened". 
    
    Serial.print("BPM: ");                        // Print phrase "BPM: " 
    Serial.println(myBPM);                        // Print the value inside of myBPM. 
}


delay(1000); 
}
