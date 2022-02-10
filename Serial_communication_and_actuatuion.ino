const int SendPulses = 11;
const int RELAY_PIN = 3; // This value is to determine the direction of rotation of the servo motor
const int NumPulses = 90; // This value is equivalent to 90 degrees of rotation
const int Freq = 1; // This value is to determine the frequency of pulse train
float Period = 1/Freq;
boolean par = 1;
String InBytes;



//



void setup() {
Serial.begin(9600);
pinMode(RELAY_PIN, OUTPUT);
pinMode(SendPulses, OUTPUT);
}



void loop()
{
if (Serial.available()>0)
{
InBytes = Serial.readStringUntil('\n');



if(InBytes =="1")
{
// Shaft rotates 45 degrees CCW towards the target
digitalWrite(RELAY_PIN, HIGH); // set the direction of rotation to CCW
for (int i = 0; i < 0.5*NumPulses; i++)
{
// This pulse train is set to 50% duty cycle
digitalWrite(SendPulses, HIGH);
delay(1000 * Period/2);
digitalWrite(SendPulses, LOW);
delay(1000 * Period/2);
}
delay(2000);
// Shaft rotates 45 degrees CW back to the initial position
digitalWrite(RELAY_PIN, LOW); // set the direction of rotation to CW
for (int i = 0; i < 0.5*NumPulses; i++)
{
// This pulse train is set to 50% duty cycle
digitalWrite(SendPulses, HIGH);
delay(1000 * Period/2);
digitalWrite(SendPulses, LOW);
delay(1000 * Period/2);
}
}



if(InBytes =="3")
{
// Shaft rotates 90 degrees CCW towards the target
digitalWrite(RELAY_PIN, HIGH); // set the direction of rotation to CCW
for (int i = 0; i < NumPulses; i++)
{
// This pulse train is set to 50% duty cycle
digitalWrite(SendPulses, HIGH);
delay(1000 * Period/2);
digitalWrite(SendPulses, LOW);
delay(1000 * Period/2);
}
delay(2000);
// Shaft rotates 90 degrees CW back to the initial position
digitalWrite(RELAY_PIN, LOW); // set the direction of rotation to CW
for (int i = 0; i < NumPulses; i++)
{
// This pulse train is set to 50% duty cycle
digitalWrite(SendPulses, HIGH);
delay(1000 * Period/2);
digitalWrite(SendPulses, LOW);
delay(1000 * Period/2);
}
}



if(InBytes =="2")
{
// Shaft rotates 45 degrees CW towards the target
digitalWrite(RELAY_PIN, LOW); // set the direction of rotation to CW
for (int i = 0; i < 0.5*NumPulses; i++)
{
// This pulse train is set to 50% duty cycle
digitalWrite(SendPulses, HIGH);
delay(1000 * Period/2);
digitalWrite(SendPulses, LOW);
delay(1000 * Period/2);
}
delay(2000);
// Shaft rotates 45 degrees CCW back to the initial position
digitalWrite(RELAY_PIN, HIGH); // set the direction of rotation to CW
for (int i = 0; i < 0.5*NumPulses; i++)
{
// This pulse train is set to 50% duty cycle
digitalWrite(SendPulses, HIGH);
delay(1000 * Period/2);
digitalWrite(SendPulses, LOW);
delay(1000 * Period/2);
}
}



if(InBytes =="4")
{
// Shaft rotates 90 degrees CW towards the target
digitalWrite(RELAY_PIN, LOW); // set the direction of rotation to CW
for (int i = 0; i < NumPulses; i++)
{
// This pulse train is set to 50% duty cycle
digitalWrite(SendPulses, HIGH);
delay(1000 * Period/2);
digitalWrite(SendPulses, LOW);
delay(1000 * Period/2);
}
delay(2000);
// Shaft rotates 90 degrees CCW back to the initial position
digitalWrite(RELAY_PIN, HIGH); // set the direction of rotation to CCW
for (int i = 0; i < NumPulses; i++)
{
// This pulse train is set to 50% duty cycle
digitalWrite(SendPulses, HIGH);
delay(1000 * Period/2);
digitalWrite(SendPulses, LOW);
delay(1000 * Period/2);
}
}



par = false;
}}
