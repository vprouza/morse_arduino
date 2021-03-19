#include <FastLED.h>

char morse[][5] = {
	"",
	".-",
	"-...",
	"-.-.",
	"-..",
	".",
	"..-.",
	"--.",
	"....",
	"..",
	".---",
	"-.-",
	".-..",
	"--",
	"-.",
	"---",
	".--.",
	"--.-",
	".-.",
	"...",
	"-",
	"..-",
	"...-",
	".--",
	"-..-",
	"-.--",
	"--.."};


#define NUM_LEDS 1
#define DATA_PIN 2
#define SPEED 300

CRGB leds[NUM_LEDS];

void setup()
{
	FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS); // GRB ordering is typical
	Serial.begin(115200);
	//Serial.println("=");
}

void loop()
{
	printText("U SLUNCE"); //print text
	
	leds[0] = CRGB::Green;
	FastLED.show();
	delay(200);
	leds[0] = CRGB::Black;
	FastLED.show();
	delay(1000);
}

void dot()
{
	leds[0] = CRGB::Red;
	FastLED.show();
	delay(SPEED);
	leds[0] = CRGB::Black;
	FastLED.show();
}

void dash()
{
	leds[0] = CRGB::Red;
	FastLED.show();
	delay(SPEED*3);
	leds[0] = CRGB::Black;
	FastLED.show();
}

void printText(char text[32]){
	for (int i = 0; i < strlen(text); i++){
		printLetter(text[i]);
	}
}

void printLetter(char letter){
	if(letter >= 'A' && letter <= "Z"){
		printMorse(morse[letter - 64]);
	}
	if(letter == ' '){
		delay(SPEED*4);
	}
}

void printMorse(char letter[5])
{
	for (int i = 0; i < strlen(letter); i++)
	{
		if (letter[i] == '.')
			dot();
		if (letter[i] == '-')
			dash();
		delay(SPEED);
	}
	delay(SPEED*3);
}
