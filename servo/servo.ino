//Face Tracker using OpenCV and Arduino
//by Shubham Santosh

#include<Servo.h>

Servo x;
int width = 400, height = 400;  // total resolution of the video
int xpos = 90;  // initial positions of both Servos
void setup() {

  Serial.begin(9600);
  x.attach(6);
  // Serial.print(width);
  //Serial.print("\t");
  //Serial.println(height);
  x.write(xpos);
}
const int angle = 2;   // degree of increment or decrement

void loop() {
  if (Serial.available() > 0)
  {
    int x_mid;
    if (Serial.read() == 'X')
    {
      x_mid = Serial.parseInt();  // read center x-coordinate
    }
    /* adjust the servo within the squared region if the coordinates
        is outside it
    */
    if (x_mid > width / 2 + 30)
      xpos -= angle;
    if (x_mid < width / 2 - 30)
      xpos += angle;


    // if the servo degree is outside its range
    if (xpos >= 180)
      xpos = 180;
    else if (xpos <= 0)
      xpos = 0;

    x.write(xpos);

    // used for testing
    //Serial.print("\t");
    // Serial.print(x_mid);
    // Serial.print("\t");
    // Serial.println(y_mid);
  }
}
