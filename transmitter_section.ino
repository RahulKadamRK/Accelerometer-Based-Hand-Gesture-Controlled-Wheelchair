#include <VirtualWire.h>

// Declare pins
int xPin=0;      // x-axis output from ADXL335 t0 A0 of UNO
int yPin=1;      // y-axis output from ADXL335 to A1 of UNO
int ledPin=13;   // to test for successful wirless communication

void setup() 
{
  vw_set_tx_pin(12);           // Transmitter to D12 of UNO
  vw_setup(2000);
  pinMode(ledPin,OUTPUT);
}

// First character represents the axis, second character represents range, third character represents message character
// Eg: xls => x-axis, lower range, for character "s" 
//     yhf => y-axis, higher range, for character "f"

// Change these values as per user's calibration
int xls = 315; int yls = 315;
int xhs = 345; int yhs = 345;
int xlf = 315; int ylf = 265;
int xhf = 335; int yhf = 320;
int xlb = 325; int ylb = 365;
int xhb = 340; int yhb = 405;
int xll = 260; int yll = 315;
int xhl = 300; int yhl = 340;
int xlr = 370; int ylr = 325;
int xhr = 400; int yhr = 350;
  
void loop() 
{
  int xval=analogRead(xPin);   
  int yval=analogRead(yPin);
  
  // Encoding the output voltage range to send paricular characters
  if ((xval>xls && xval<xhs) && (yval>yls && yval<yhs))
  {
    digitalWrite(ledPin,LOW);
    send("s");                                                                //s => "Stop the wheelchair"
  } 
  else 
  { 
    if ((xval>xlf && xval<xhf) && (yval>ylf && yval<yhf)) 
    {
      digitalWrite(ledPin,HIGH);
      send("f");                                                              //f => "Move Forward"
    }
    if ((xval>xlb && xval<xhb) && (yval>ylb && yval<yhb)) 
    {
      digitalWrite(ledPin,HIGH);
      send("b");                                                              //b => "Move Backward"
    }
    if ((xval>xll && xval<xhl) && (yval>yll && yval<yhl)) 
    {
      digitalWrite(ledPin,HIGH);
      send("l");                                                              //l => "Move Left"
     }
    if ((xval>xlr && xval<xhr ) && (yval>ylr && yval<yhr))
    {
      digitalWrite(ledPin,HIGH);
      send("r");                                                              //r => "Move Right"
    }
}  
}

// Function to encode and transmit messages
void send(char *message)
{
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx();
}
