const int trigger1 = 2;
const int trigger2 = 4;
const int echo1 = 3;
const int echo2 = 5;

long time_taken;
int dist,distLeft,distRight;

void setup()
{
  Serial.begin(9600); //baud rate

  pinMode(trigger1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trigger2, OUTPUT);
  pinMode(echo2, INPUT);
}

void calculate_distance(int trigger, int echo)
{
  digitalWrite(trigger, LOW); //check later
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  time_taken = pulseIn(echo, HIGH);
  dist = time_taken*0.034/2;

  if (dist > 50)
    dist = 50;
}

void loop()
{
  calculate_distance(trigger1, echo1);
  distLeft = dist; //gets the distance of the left sensor

  calculate_distance(trigger2, echo2);
  distRight = dist; //gets the distance of the right sensor

//Comment below is to be used for debugging purposes
  /*Serial.print("Left=");
   Serial.println(distLeft);
   Serial.print("Right=");
   Serial.println(distRight);
   */

   if ((distLeft > 40 && distRight > 40) && (distLeft < 50 && distRight < 50))
   {
    Serial.println("Play/Pause");
    delay(500);
   }

   calculate_distance(trigger1, echo1);
   distLeft = dist;

   calculate_distance(trigger1, echo2);
   distRight = dist;

   if (distLeft >= 13 && distLeft <= 17)
   {
    delay(100);
    calculate_distance(trigger1, echo1);
    distLeft = dist;

    if (distLeft >= 13 && distLeft <= 17)
    {
      Serial.println("Left locked");
      while (distLeft <= 40)
      {
        calculate_distance(trigger1, echo1);
        distLeft = dist; 
        if (distLeft < 10)
        {
          Serial.println("V up");
          delay(300);
        }
        if (distLeft > 20)
        {
          Serial.println("V down");
          delay(300);
        }
      }
    }
   }

   if (distRight >= 13 && distRight <= 17)
   {
    delay(100);
    calculate_distance(trigger2, echo2);
    distRight = dist;
    if (distRight >= 13 && distRight <17)
    {
      Serial.println("Right locked");
      while (distRight <= 40)
      {
        calculate_distance(trigger2, echo2);
        distRight =dist;
        if (distRight < 10) //Right hand pushed in
        {
          Serial.println ("Rewind");
          delay (300);
        }
        if (distRight>20) //Right hand pulled out
        {
         Serial.println ("Forward"); 
         delay (300);
        }
      }
    }
   }
   delay(200);
}
