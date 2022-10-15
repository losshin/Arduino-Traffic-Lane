
// first seven segment
int A = A0;
int B = A1;
int C = A2;
int D = A3;
int E = A4;
int F = A5;
int G = 2;

// second seven segment
int a = 4;
int b = 12;
int c = 7;
int d = 8;
int e = 9;
int f = 10;
int g = 11;

const int sevment1[8] = {A6,G,F,E,D,C,B,A};
const int sevment2[8] = {A6,g,f,e,d,c,b,a};

const byte numeral[10] = {
  B11111101, // 0
  B01100001, // 1
  B11011011, // 2
  B11110011, // 3
  B01100111, // 4
  B10110111, // 5
  B10111111, // 6
  B11100001, // 7
  B11111111, // 8
  B11110111  // 9
};


void setup() {
  // pinMode LED
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  // pinMode for Seven Segment 1
  for(int i = 0; i < 8; i++)
  {
    pinMode(sevment1[i], OUTPUT);
  }

  // pinMode for Seven Segment 2
    for(int i = 0; i < 8; i++)
  {
    pinMode(sevment2[i], OUTPUT);
  }
}

void loop() {


 // function lights slowly turn on/dim
  lampredup(3, 1);
  lampredup(5, 1);
  lampredup(6, 1);

  // Traffic Lane
  trafficLane(2);
}

// lights slowly turn on/dim
void lampredup(int r, int n) {

  for (int i = 0; i <= 255; i++) {
    analogWrite(r, i);
    delay(n);
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(r, i);
    delay(n);
  }
}

// Show Numeral
void showDigit(int number) {
  boolean isBitSet;
  for(int segment = 1; segment < 8; segment++) {
    if( number < 0 || number > 9)
    {
      isBitSet = 0;
    }
    else
    {
      isBitSet = bitRead(numeral[number], segment);
    }
  isBitSet = !isBitSet;
  digitalWrite(sevment1[segment], isBitSet);
  }
}

void showDigit2(int number) {
  boolean isBitSet;
  for(int segment = 1; segment < 8; segment++) {
    if( number < 0 || number > 9)
    {
      isBitSet = 0;
    }
    else
    {
      isBitSet = bitRead(numeral[number], segment);
    }
  isBitSet = !isBitSet;
  digitalWrite(sevment2[segment], isBitSet);
  }
}

// Traffic Lane
void trafficLane(int r) {

// Green light
  digitalWrite(3, HIGH);
  for (int i = r; i >= 0; i--) {
    showDigit(i);
    for (int i = 9; i >= 0; i--) {
      showDigit2(i);
      delay(1000);
    }
  }
  digitalWrite(3, LOW);

// Yellow light
  digitalWrite(5, HIGH);
  delay(800);
  digitalWrite(5, LOW);

// Red light
  digitalWrite(6, HIGH);
  for (int i = r; i >= 0; i--) {
    showDigit(i);
    for (int i = 9; i >= 0; i--) {
      showDigit2(i);
      delay(1000);
    }
  }
  digitalWrite(6, LOW);

// Yellow light
  digitalWrite(5, HIGH);
  delay(800);
  digitalWrite(5, LOW);
}
