
// seven segment kesatu
int A = A0;
int B = A1;
int C = A2;
int D = A3;
int E = A4;
int F = A5;
int G = 2;

// seven segment kedua
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
  B11111101, // angka 0
  B01100001, // angka 1
  B11011011, // angka 2
  B11110011, // angka 3
  B01100111, // angka 4
  B10110111, // angka 5
  B10111111, // angka 6
  B11100001, // angka 7
  B11111111, // angka 8
  B11110111  // angka 9
};


void setup() {
  // pinMode untuk LED
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  // pinMode untuk Seven Segment 1
  for(int i = 0; i < 8; i++)
  {
    pinMode(sevment1[i], OUTPUT);
  }

  // pinMode untuk Seven Segment 2
    for(int i = 0; i < 8; i++)
  {
    pinMode(sevment2[i], OUTPUT);
  }
}

void loop() {
// lampu menyala bergantian
  // for (int i = 0; i < 3; i++){
  //   if (i == 0) {
  //     digitalWrite(3, HIGH);
  //     digitalWrite(5, LOW);
  //     digitalWrite(6, LOW);
  //     delay(250);
  //   } else if (i == 1) {
  //     digitalWrite(3, LOW);
  //     digitalWrite(5, HIGH);
  //     digitalWrite(6, LOW);
  //     delay(250);
  //   } else {
  //     digitalWrite(3, LOW);
  //     digitalWrite(5, LOW);
  //     digitalWrite(6, HIGH);
  //     delay(250);
  //   }

 // pemanggilan fungsi lampu redup dan nyala secara perlahan
  lampredup(3, 1);
  lampredup(5, 1);
  lampredup(6, 1);

  // lampu lalu lintas
  apill(2);
}

// lampu perlaha nyala/redup
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

// menampilkan numeral
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

// untuk apill
void apill(int r) {

// lampu hijau
  digitalWrite(3, HIGH);
  for (int i = r; i >= 0; i--) {
    showDigit(i);
    for (int i = 9; i >= 0; i--) {
      showDigit2(i);
      delay(1000);
    }
  }
  digitalWrite(3, LOW);

// lampu kuning
  digitalWrite(5, HIGH);
  delay(800);
  digitalWrite(5, LOW);

// lampu merah
  digitalWrite(6, HIGH);
  for (int i = r; i >= 0; i--) {
    showDigit(i);
    for (int i = 9; i >= 0; i--) {
      showDigit2(i);
      delay(1000);
    }
  }
  digitalWrite(6, LOW);

  // lampu kuning
  digitalWrite(5, HIGH);
  delay(800);
  digitalWrite(5, LOW);
}