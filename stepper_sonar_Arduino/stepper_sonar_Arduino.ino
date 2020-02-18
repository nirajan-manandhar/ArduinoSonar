#define IN1 8

#define IN2 9

#define IN3 10

#define IN4 11

#define trig 12

#define echo 13

#define FULL_ROTATION 4096

int oneDegree = 11.3777;

const int phases1[] = {0, 0, 0, 0, 0, 1, 1, 1};

const int phases2[] = {0, 0, 0, 1, 1, 1, 0, 0};

const int phases3[] = {0, 1, 1, 1, 0, 0, 0, 0};

const int phases4[] = {1, 1, 0, 0, 0, 0, 0, 1};

int Phase = 0;
int Degree = 0;

long duration;
int distance;

int Speed = 100; //MUST BE 1 - 100

void setup()

{

//For the stepper motor
pinMode(IN1, OUTPUT);

pinMode(IN2, OUTPUT);

pinMode(IN3, OUTPUT);

pinMode(IN4, OUTPUT);

//For the ultrasonic sonar device
pinMode(trig, OUTPUT);

pinMode(echo, INPUT);

//Begin serial link
Serial.begin(115200);

}

void loop()

{
  
stepper(-FULL_ROTATION/2);

delay(500);

stepper(FULL_ROTATION/2);

delay(500);

}

void stepper(int count)

{

//Set rotation direction based on step directions (count) +/-
int rotationDirection = count < 1 ? -1 : 1;

//Make count positive
count *= rotationDirection;

for (int x = 0; x < count; x++)

{

if ((x%oneDegree) == 0) {
  if(rotationDirection == -1) {
    distance = calculateDistance();
    Degree += 1;
  } else {
    distance = calculateDistance();
    Degree -= 1;
  }
  Serial.print(Degree);
  Serial.print(",");
  Serial.print(distance);
  Serial.println(".");
}

digitalWrite(IN1, phases1[Phase]);

digitalWrite(IN2, phases2[Phase]);

digitalWrite(IN3, phases3[Phase]);

digitalWrite(IN4, phases4[Phase]);

IncrementPhase(rotationDirection);

delay(100/Speed);

}

}

int calculateDistance(){ 
  
  digitalWrite(trig, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}

void IncrementPhase(int rotationDirection)

{

Phase += 8;

Phase += rotationDirection;

Phase %= 8;

}
