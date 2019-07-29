 
/*This is the code to show the alphabetical characters on a 7 segment LED display*/

//bits representing the alphabetical characters
const byte alphabet[16]= {
B11101110, //A
B00111110, //b
B10011100, //C
B00011010, //c
B01111010, //d
B10011110, //E
B10001110, //F
B01101110, //H
B00101110, //h
B00011100, //L
B01100000, //l
B11111100, //O
B00111010, //o
B11001110, //P
B10110110, //S
B00000000, //shows nothing
};

//pins for each segment (a-g) on the 7 segment LED display with the corresponding arduino connection
const int segmentPins[8]= { 5,8,9,7,6,4,3,2 };

void setup()
{
for (int i=0; i < 8; i++)
{
pinMode(segmentPins[i], OUTPUT);
}
}
void loop()
{
for (int i=0; i <=15; i++)
{
showDigit(i);
delay(1000);
}
delay(2000); //after LED segment shuts off, there is a 2-second delay
}

void showDigit (int number)
{
boolean isBitSet;

for (int segment=0; segment < 15; segment++)
{
isBitSet= bitRead(alphabet[number], segment);
digitalWrite(segmentPins[segment], isBitSet);
}
}

