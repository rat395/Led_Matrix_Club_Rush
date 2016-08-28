#include <LedControl.h>

int DIN = 12;
int CS = 11;
int CLK = 10;


//byte s [8] =  {0x18,0x24,0x20,0x10,0x08,0x24,0x24,0x18};
//byte t [8] =  {0xFF,0x18,0x18,0x18,0x18,0x18,0x18,0x18};
//byte e [8] =  {0x3E,0x20,0x20,0x3C,0x20,0x20,0x3E,0x00};
//byte a [8] =  {0x18,0x24,0x3C,0x24,0x24,0x24,0x24,0x00};
//byte m [8] =  {0x00,0x22,0x36,0x2A,0x22,0x22,0x22,0x00};

//putting the byte arrays in a 2D array
//this way we can loop through them in the "void loop"
byte steam_array [5][8] = {{0x18,0x24,0x20,0x10,0x08,0x24,0x24,0x18}, //s
                           {0xFF,0x18,0x18,0x18,0x18,0x18,0x18,0x18}, //t
                           {0x3E,0x20,0x20,0x3C,0x20,0x20,0x3E,0x00}, //e
                           {0x18,0x24,0x3C,0x24,0x24,0x24,0x24,0x00}, //a
                           {0x00,0x22,0x36,0x2A,0x22,0x22,0x22,0x00}};//m


byte invader2a[] =
{
  B00100100, // First frame of invader #2
  B00100100,
  B01111110,
  B11011011,
  B11111111,
  B11111111,
  B10100101,
  B00100100
};
 
byte invader2b[] =
{
  B00100100, // Second frame of invader #2
  B10100101,
  B11111111,
  B11011011,
  B11111111,
  B01111110,
  B00100100,
  B01000010
};



LedControl lc=LedControl (DIN,CLK,CS,0);

void setup() {
Serial.begin(9600);
lc.shutdown(0, false); //The driver is in power saving on startup
lc.setIntensity(0, 3); // set max brightness
lc.clearDisplay(0); // clear the display
}

void loop() {

  //this is where we print out "steam"
  //it loops through the rows of the array and returns each full row
  for (int i = 0; i < 5; i++) {
      printByte(steam_array[i]);
      delay(1200);
   }

  
  for (int i = 0; i < 8; i++) {
      if (i % 2 == 0) {
          printByte(invader2b);
        } else {
          printByte(invader2a);
        }

      delay(200);
  }
}


void printByte(byte character []) {
  int i = 0;
  for(i=0;i<8;i++) {
    lc.setRow(0,i,character[i]);
  }
}
