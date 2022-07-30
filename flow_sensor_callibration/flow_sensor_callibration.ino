int X;
int Y;
float TIME = 0;
float FREQUENCY = 0;
float WATER = 0;
float TOTAL = 0;
float LS = 0;
const int input = D2;
void setup()
{
Serial.begin(115200);
pinMode(input,INPUT);
}
void loop()
{
X = pulseIn(input, HIGH);
Y = pulseIn(input, LOW);
TIME = X + Y;
FREQUENCY = 1000000/TIME;
WATER = FREQUENCY/89;   // Callibration factor
LS = WATER/60;
if(FREQUENCY >= 0)
{
if(isinf(FREQUENCY))
{

Serial.print("VOL. :0.00 ,");
Serial.print("TOTAL:");
Serial.print( TOTAL);
Serial.println(" L");
}
else
{
TOTAL = TOTAL + LS;
//Serial.print(FREQUENCY);
Serial.print("Flow Rate: ");
Serial.print(WATER);
Serial.print(" L/M , ");
Serial.print("TOTAL:");
Serial.print( TOTAL);
Serial.println(" L");
}
}
delay(1000);
}
