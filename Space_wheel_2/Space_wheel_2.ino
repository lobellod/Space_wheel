//define input pins in order of wires
#define pin1 2
#define pin2 3
#define pin3 4
#define pin4 5
#define pin5 6
#define pin6 7
#define pin7 8
#define pin8 9

byte inByte;
byte outByte;
byte combinedByte;

int randomProgram = 0;
int randomSpeed = 100;
int randomIteration = 1;
bool randomDirection = 0;
int pin_array[] = {pin1,pin2,pin3,pin4,pin5,pin6,pin7,pin8};


void setup() {
    Serial.begin(9600);
    pinMode(pin1,OUTPUT);
    pinMode(pin2,OUTPUT);
    pinMode(pin3,OUTPUT);
    pinMode(pin4,OUTPUT);  
    pinMode(pin5,OUTPUT);
    pinMode(pin6,OUTPUT);
    pinMode(pin7,OUTPUT);
    pinMode(pin8,OUTPUT);
    randomSeed(analogRead(0));
}

typedef void (*ProgramList[])(int, int, bool);
ProgramList Program = { program1, program2, program3, program4, program5};

void loop() {
  allOn(10000);
  randomSpeed = random(70,151);
  randomDirection = false;
  if(random(0,2) == 1){randomDirection = true;}
  randomProgram = random(0,5);
  randomIteration = random(1,5);

  //Program[3](randomSpeed,randomIteration,randomDirection);
  Program[randomProgram](randomSpeed,randomIteration,randomDirection);

   
}







