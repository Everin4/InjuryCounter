// Injury Counter Display
// James Kemp-Dale
// 16th January 2025

// General Function Declarations

int outputBinary[4];

void convertToFourBit(int convertingNum) {
  // Turns convertingNum into four bit binary, as long as the number is single digit
  // i.e 8 is converted to 0100

  outputBinary[4] = new int[4] {0,0,0,0};

  if (convertingNum < 10) {
    switch(convertingNum) {
      case 1:
        outputBinary[3] = 1;
        break;
      case 2:
        outputBinary[2] = 1;
        break;
      case 3:
        outputBinary[2] = 1;
        outputBinary[3] = 1;
        break;
      case 4:
        outputBinary[1] = 1;
        break;
      case 5:
        outputBinary[1] = 1;
        outputBinary[3] = 1;
        break;
      case 6:
        outputBinary[1] = 1;
        outputBinary[2] = 1;
        break;
      case 7:
        outputBinary[1] = 1;
        outputBinary[2] = 1;
        outputBinary[3] = 1;
        break;
      case 8:
        outputBinary[0] = 1;
        break;
      case 9:
        outputBinary[0] = 1;
        outputBinary[3] = 1;
        break;
    }
  }

  return outputBinary;
}

// Class declarations for SevenSegDisplay

class SevenSegDisplay {
  public:
    void initializeDisplay(int newDisplayPins[], bool newDriverAttached);
    void generateDirectNum(int newNum);
    void generateDriverNum(int newNum);
    bool driverAttached;
  private:
    int driverDisplayPins[4];
    int directDisplayPins[8];
};

void SevenSegDisplay::initializeDisplay(int newDisplayPins[], bool newDriverAttached) {
  // Depending on if a 4511 is declared to be utilized, fill the list of pin numbers according to newDisplayPins and turn the pins into outputs
  
  if (newDriverAttached) {
    for (int x = 0; x < 4; x++) {
      driverDisplayPins[x] = newDisplayPins[x];
      pinMode(driverDisplayPins[x], OUTPUT);
    }
  } else {
    for (int x = 0; x < 8; x++) {
      directDisplayPins[x] = newDisplayPins[x];
      pinMode(directDisplayPins[x], OUTPUT);
    }
  }
};

void SevenSegDisplay::generateDirectNum(int newNum) {
  // Checks that the number is a single digit, maps to a configured 
  // digit configuration for all 8 directly connected pins and outputs that configuration. Not the most elegant solution.
  // Works when a 4511 Driver is not present

  // Lays out a default list of 8 pin positions, all set to off.
  int pinMapping[] = {0,0,0,0,0,0,0,0};
  
  // As long as newNum is a single digit then the 
  if (newNum < 10) {
    // Checks through a list of possible configurations according to newNum
    // All cases are currently empty until testing occurs
    switch(newNum) {
      case 0:
        break;
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
        break;
      case 9:
        break;
    }

    // Once the configuration is set then turn on all applicable pins
    for (int pin = 0; pin < 8; pin++) {
      digitalWrite(this->directDisplayPins[pin], *pinMapping);
    }
  }
}

void SevenSegDisplay::generateDriverNum(int newNum) {
  convertToFourBit(newNum);
  for (int pin = 0; pin < 4; pin++) {
    digitalWrite(this->driverDisplayPins[pin], outputBinary[pin]);
  }
}

// Functions run during runtime

void setup() {

}

void loop() {

}