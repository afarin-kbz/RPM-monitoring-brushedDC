#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Adafruit_PWMServoDriver.h>
#include <Encoder.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);

const int encoderPinA = 2; // Replace with the actual pin connected to Encoder Channel A
const int encoderPinB = 3; // Replace with the actual pin connected to Encoder Channel B
const int encoderResolution = 2000; // Encoder resolution (cycles per revolution)
Encoder myEncoder(encoderPinA, encoderPinB);

const unsigned long predefinedDuration = 3000; // Define the duration in milliseconds (5 seconds in this example)
unsigned long startTime = 0; // Variable to store the starting time
bool loopRunning = true; // Flag to indicate if the loop is running

long firstRawPosition = 0; // Variable to store the first generated raw position
long lastRawPosition = 0; // Variable to store the last generated raw position

unsigned long encoderResetInterval = predefinedDuration; // Interval to reset the encoder and calculate RPM (in milliseconds)
unsigned long lastEncoderResetTime = 0; // Variable to store the last time the encoder was reset

unsigned long convertingFactor = 60000/predefinedDuration;

unsigned long i = 0;
unsigned long currentspeed = 0;

void setup() {
  Serial.begin(9600);
  AFMS.begin();
  myMotor->setSpeed(currentspeed);
  
}


void loop() {
  // Run the motor continuously
  //Serial.println(i);
  myMotor->run(FORWARD);

   if (Serial.available())
   {
      int speed = Serial.parseInt();
     // Serial.print("you entered "); // ***** added line
      //Serial.println(speed); // ***** added line

      //somehow 
      switch(speed){
        case 0:
        break;
        default:
        currentspeed = speed;
        break;
      }
      myMotor->setSpeed(currentspeed);

   }

   //Serial.print("the thing u entered iiiis "); // ***** added line
   //Serial.println(currentspeed); // ***** added line

  // Read the raw encoder data (position count)
  long rawPosition = myEncoder.read();

  // Output the raw encoder data and frequency
  //Serial.print("Raw Position: ");
  //Serial.println(rawPosition);

  // Add a delay or other logic here, depending on your application
  //delay(100); // Adjust this delay as needed to control the update rate

  // Check if it's time to reset the encoder and calculate RPM
  unsigned long currentTime = millis();
  if (currentTime - lastEncoderResetTime >= encoderResetInterval) {
    myMotor->run(RELEASE); // Stop the motor

    // Calculate the total number of revolutions since the last reset
    float totalRotations = static_cast<float>(rawPosition - firstRawPosition) / encoderResolution;
    float RPM = totalRotations * convertingFactor;
    float F = RPM/60;
    // float RPM = 0.2017 * totalRotations * convertingFactor + 36.39;

    //Serial.print("Total Rotations: ");
    //Serial.println(totalRotations);
    Serial.print("RPM: ");
    Serial.print(RPM);
    Serial.print(" , Frequency: ");
    Serial.println(F);

    // Store the current raw position for the next interval's calculation
    firstRawPosition = rawPosition;

    // Reset the timer for the next interval
    lastEncoderResetTime = currentTime;

    // Restart the motor for the next interval
    myMotor->run(FORWARD);
    myMotor->setSpeed(currentspeed);
    
   
  }
  i = i + 1;
  //Serial.println(i);
}

