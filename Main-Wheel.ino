// Rotary Encoder Inputs
#define CLK 2
#define DT 3
#define SW 4

 uint8_t buf[8] = {
  0
}; 

int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir ="";
unsigned long lastButtonPress = 0;


boolean Flip1State = false;
boolean Flip2State = false;

boolean buttonActive = false;
boolean longPressActive = false;

long buttonTimer = 0;
long longPressTime = 400;


int upLeft = 79;
int downRight = 80;


void setup() {
  
  // Set encoder pins as inputs
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW, INPUT_PULLUP);

  // Setup Serial Monitor
  Serial.begin(9600);

  // Read the initial state of CLK
  lastStateCLK = digitalRead(CLK);
}

void loop() {
  
  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT) != currentStateCLK) {
      counter --;
      currentDir ="CCW";
      buf[2] = upLeft; 
      Serial.write(buf, 8);
      releaseKey();
    } else {
      // Encoder is rotating CW so increment
      counter ++;
      currentDir ="CW";
      buf[2] = downRight; 
      Serial.write(buf, 8);
      releaseKey();
    }

  }

  // Remember last CLK state
  lastStateCLK = currentStateCLK;

  // Read the button state
  int btnState = digitalRead(SW);

  //If we detect LOW signal, button is pressed
  if (btnState == LOW) {
   if (buttonActive == false) {
      buttonActive = true;
      buttonTimer = millis();
    }

    if ((millis() - buttonTimer > longPressTime) && (longPressActive == false)) {

      longPressActive = true;
      Flip1State = !Flip1State;

      if (Flip1State == 1){
        upLeft = 79;
        downRight = 80;
        
      } else {
        upLeft = 82;
        downRight = 81;
      }
     
    } 
  
  } else {
    if (buttonActive == true) {

      if (longPressActive == true) {
        longPressActive = false;

      } else {
        Flip2State = !Flip2State;
        buf[2] = 40;    // HID: ENTER key
        Serial.write(buf, 8);
        releaseKey();  
      }

      buttonActive = false;
     
    }
 
  }

  // Put in a slight delay to help debounce the reading
  delay(1);
}

void releaseKey()
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key
}
