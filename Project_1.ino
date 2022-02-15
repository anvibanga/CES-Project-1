/*  
 Test the tft.print() viz embedded tft.write() function

 This sketch used font 2, 4, 7
 
 Make sure all the display driver and pin connections are correct by
 editing the User_Setup.h file in the TFT_eSPI library folder.

 Note that yield() or delay(0) must be called in long duration for/while
 loops to stop the ESP8266 watchdog triggering.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
 */


#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

#define TFT_GREY 0x5AEB // New colour

void setup(void) {
  tft.init();
  tft.setRotation(1);
}

void loop() {
  
  // Fill screen with grey so we can see the effect of printing with and without 
  // a background colour defined
  tft.fillScreen(TFT_BLACK);
  
  // Set "cursor" at top left corner of display (0,0) and select font 2
  // (cursor will move to next line automatically during printing with 'tft.println'
  //  or stay on the line is there is room for the text with tft.print)
  tft.setCursor(100, 100, 2);
  // Set the font colour to be white with a black background, set text size multiplier to 1
  tft.setTextColor(TFT_WHITE,TFT_BLACK);  tft.setTextSize(2);
  // We can now plot text on screen using the "print" class
  //tft.println("Hello World!");

  const char *verse_one[14]  = {"Harry Truman", "Doris Day", "Red China", "Johnnie Ray", "South Pacific", "Walter Winchell", "Joe DiMaggio", "Joe McCarthy", "Richard Nixon", "Studebaker", 
  "television", "North Korea", "South Korea", "Marilyn Monroe"};
  
  const char *verse_two[14]  = {"Rosenbergs", "H-bomb", "Sugar Ray", "Panmunjom", "Brando", "The King and I", " and The Catcher in the Rye", "Eisenhower", "Vaccine", "England's got a new queen",
  "Marciano", "Liberace", "Santayana", "goodbye"};
  
  const char *chorus[6] = {"We didn't start the fire", "It was always burning", "since the world's been turning", "We didn't start the fire","No, we didn't light it", "but we tried to fight it"};

  const char *verse_three[13] = {"Joseph Stalin", "Malenkov", "Nasser", "and Prokofiev", "Rockefeller", "Campanella", "Communist Bloc","Roy Cohn", "Juan Peron", "Toscanini", "Dacron",
  "Dien Bien Phu falls", "Rock Around the Clock"};

  const char *verse_four[14] = {"Einstein", "James Dean", "Brooklyn's got a winning team", "Davy Crockett", "Peter Pan", "Elvis Presley", "Disneyland", "Bardot", "Budapest", "Alabama", "Krushchev",
  "Princess Grace", "Peyton Place", "Trouble in the Suez"};

  const char *verse_five[12] = {"Little Rock", "Pasternak", "Mickey Mantle", "Kerouac", "Sputnik", "Chou En-Lai", "Bridge on the River Kwai", "Lebanon", "Charles de Gaulle", "California baseball",
  "Starkweather homicide", "children of thalidomide"};

  const char *verse_six[13] = {"Buddy Holly", "Ben Hur", "space monkey", "mafia", "Hula hoops", "Castro", "Edsel is a no-go", "U2", "Syngman Rhee", "Payola and Kennedy", "Chubby Checker",
  "Psycho", "Belgians in the Congo"};

  const char *verse_seven[16] = {"Hemingway", "Eichmann", "Stranger in a Strange Land", "Dylan", "Berlin", "Bay of Pigs invasion","Lawrence of Arabia", "British Beatlemania", "Ole Miss", 
  "John Glenn", "Liston beats Patterson", "Pope Paul", "Malcolm X", "British politician sex", "JFK – blown away", "what else do I have to say?"};

  const char *verse_eight[13] = {"Birth control", "Ho Chi Minh", "Richard Nixon back again", "Moonshot", "Woodstock", "Watergate", "punk rock", "Begin", "Reagan", "Palestine", "terror on the airline",
  "Ayatollah's in Iran", "Russians in Afghanistan"};

  const char *verse_nine[13] = {"Wheel of Fortune", "Sally Ride", "heavy metal suicide", "Foreign debts", "homeless vets", "AIDS", "crack", "Bernie Goetz", "Hypodermics on the shore", 
  "China's under martial law", "Rock and roller", "cola wars", "I can't take it anymore"};
  
  String currentLine = "";
  for(;;){
    //verse one
    for (int i = 0; i < 14; i++)
    {
      currentLine = verse_one[i];
      if (i%3 == 1)
      {
        tft.setTextColor(TFT_RED);
      }
      else if (i%3 == 2)
      {
        tft.setTextColor(TFT_ORANGE);
      }
      else
      {
        tft.setTextColor(TFT_YELLOW);
      }
      tft.setTextSize(2);
      if (strlen(verse_one[i]) > 14)
      {
        tft.setTextSize(1.75);
      }
      int location1 = rand() % (55 - strlen(verse_one[i])) + 1; 
      int location2 = rand() % 100 + 1; 
      tft.setCursor(location1, location2, 2);
      tft.println(verse_one[i]);
      delay(730);
      tft.fillScreen(TFT_BLACK);
    }

    //verse two
    for (int i = 0; i < 14; i++)
    {
      currentLine = verse_two[i];
      if (i%3 == 1)
      {
        tft.setTextColor(TFT_RED);
      }
      else if (i%3 == 2)
      {
        tft.setTextColor(TFT_ORANGE);
      }
      else
      {
        tft.setTextColor(TFT_YELLOW);
      }
      tft.setTextSize(2);
      if (strlen(verse_two[i]) > 14)
      {
        tft.setTextSize(1.75);
      }
      int location1 = rand() % (55 - strlen(verse_two[i])) + 1; 
      int location2 = rand() % 100 + 1; 
      tft.setCursor(location1, location2, 2);
      tft.println(verse_two[i]);
      delay(730);
      tft.fillScreen(TFT_BLACK);
    }

    //chorus
    for (int i = 0; i < 6; i++)
    {
      currentLine = chorus[i];
      if (i%3 == 1)
      {
        tft.setTextColor(TFT_RED);
      }
      else if (i%3 == 2)
      {
        tft.setTextColor(TFT_ORANGE);
      }
      else
      {
        tft.setTextColor(TFT_YELLOW);
      }
      tft.setTextSize(1);
      int location1 = 1; 
      int location2 = 50; 
      tft.setCursor(location1, 1 + (i%3)*50, 2);
      tft.println(chorus[i]);
      delay(730);
      tft.fillScreen(TFT_BLACK);
    }

    //verse three
    for (int i = 0; i < 13; i++)
    {
      currentLine = verse_three[i];
      if (i%3 == 1)
      {
        tft.setTextColor(TFT_RED);
      }
      else if (i%3 == 2)
      {
        tft.setTextColor(TFT_ORANGE);
      }
      else
      {
        tft.setTextColor(TFT_YELLOW);
      }
      tft.setTextSize(2);
      if (strlen(verse_three[i]) > 14)
      {
        tft.setTextSize(1.75);
      }
      int location1 = rand() % (55 - strlen(verse_three[i])) + 1; 
      int location2 = rand() % 100 + 1; 
      tft.setCursor(location1, location2, 2);
      tft.println(verse_three[i]);
      delay(730);
      tft.fillScreen(TFT_BLACK);
    }

    //verse four
    for (int i = 0; i < 14; i++)
    {
      currentLine = verse_four[i];
      if (i%3 == 1)
      {
        tft.setTextColor(TFT_RED);
      }
      else if (i%3 == 2)
      {
        tft.setTextColor(TFT_ORANGE);
      }
      else
      {
        tft.setTextColor(TFT_YELLOW);
      }
      tft.setTextSize(2);
      if (strlen(verse_four[i]) > 14)
      {
        tft.setTextSize(1.75);
      }
      int location1 = rand() % (55 - strlen(verse_four[i])) + 1; 
      int location2 = rand() % 100 + 1; 
      tft.setCursor(location1, location2, 2);
      tft.println(verse_four[i]);
      delay(730);
      tft.fillScreen(TFT_BLACK);
    }

    //chorus
    for (int i = 0; i < 6; i++)
    {
      currentLine = chorus[i];
      if (i%3 == 1)
      {
        tft.setTextColor(TFT_RED);
      }
      else if (i%3 == 2)
      {
        tft.setTextColor(TFT_ORANGE);
      }
      else
      {
        tft.setTextColor(TFT_YELLOW);
      }
      tft.setTextSize(1);
      int location1 = 1; 
      int location2 = 50; 
      tft.setCursor(location1, 1 + (i%3)*50, 2);
      tft.println(chorus[i]);
      delay(730);
      tft.fillScreen(TFT_BLACK);
    }

    //verse five
    for (int i = 0; i < 12; i++)
    {
      currentLine = verse_five[i];
      if (i%3 == 1)
      {
        tft.setTextColor(TFT_RED);
      }
      else if (i%3 == 2)
      {
        tft.setTextColor(TFT_ORANGE);
      }
      else
      {
        tft.setTextColor(TFT_YELLOW);
      }
      tft.setTextSize(2);
      if (strlen(verse_five[i]) > 14)
      {
        tft.setTextSize(1.75);
      }
      int location1 = rand() % (55 - strlen(verse_five[i])) + 1; 
      int location2 = rand() % 100 + 1; 
      tft.setCursor(location1, location2, 2);
      tft.println(verse_five[i]);
      delay(730);
      tft.fillScreen(TFT_BLACK);
    }

    //verse six
    for (int i = 0; i < 13; i++)
    {
      currentLine = verse_six[i];
      if (i%3 == 1)
      {
        tft.setTextColor(TFT_RED);
      }
      else if (i%3 == 2)
      {
        tft.setTextColor(TFT_ORANGE);
      }
      else
      {
        tft.setTextColor(TFT_YELLOW);
      }
      tft.setTextSize(2);
      if (strlen(verse_six[i]) > 14)
      {
        tft.setTextSize(1.75);
      }
      int location1 = rand() % (55 - strlen(verse_six[i])) + 1; 
      int location2 = rand() % 100 + 1; 
      tft.setCursor(location1, location2, 2);
      tft.println(verse_six[i]);
      delay(730);
      tft.fillScreen(TFT_BLACK);
    }

    //chorus
    for (int i = 0; i < 6; i++)
    {
      currentLine = chorus[i];
      if (i%3 == 1)
      {
        tft.setTextColor(TFT_RED);
      }
      else if (i%3 == 2)
      {
        tft.setTextColor(TFT_ORANGE);
      }
      else
      {
        tft.setTextColor(TFT_YELLOW);
      }
      tft.setTextSize(1);
      int location1 = 1; 
      int location2 = 50; 
      tft.setCursor(location1, 1 + (i%3)*50, 2);
      tft.println(chorus[i]);
      delay(730);
      tft.fillScreen(TFT_BLACK);
    }

    //verse seven
    for (int i = 0; i < 16; i++)
    {
      currentLine = verse_seven[i];
      if (i%3 == 1)
      {
        tft.setTextColor(TFT_RED);
      }
      else if (i%3 == 2)
      {
        tft.setTextColor(TFT_ORANGE);
      }
      else
      {
        tft.setTextColor(TFT_YELLOW);
      }
      tft.setTextSize(2);
      if (strlen(verse_seven[i]) > 14)
      {
        tft.setTextSize(1.75);
      }
      int location1 = rand() % (55 - strlen(verse_seven[i])) + 1; 
      int location2 = rand() % 100 + 1; 
      tft.setCursor(location1, location2, 2);
      tft.println(verse_seven[i]);
      delay(730);
      tft.fillScreen(TFT_BLACK);
    }

    //chorus
    for (int i = 0; i < 6; i++)
    {
      currentLine = chorus[i];
      if (i%3 == 1)
      {
        tft.setTextColor(TFT_RED);
      }
      else if (i%3 == 2)
      {
        tft.setTextColor(TFT_ORANGE);
      }
      else
      {
        tft.setTextColor(TFT_YELLOW);
      }
      tft.setTextSize(1);
      int location1 = 1; 
      int location2 = 50; 
      tft.setCursor(location1, 1 + (i%3)*50, 2);
      tft.println(chorus[i]);
      delay(730);
      tft.fillScreen(TFT_BLACK);
    }

    //verse eight
    for (int i = 0; i < 13; i++)
    {
      currentLine = verse_eight[i];
      if (i%3 == 1)
      {
        tft.setTextColor(TFT_RED);
      }
      else if (i%3 == 2)
      {
        tft.setTextColor(TFT_ORANGE);
      }
      else
      {
        tft.setTextColor(TFT_YELLOW);
      }
      tft.setTextSize(2);
      if (strlen(verse_eight[i]) > 14)
      {
        tft.setTextSize(1.75);
      }
      int location1 = rand() % (55 - strlen(verse_eight[i])) + 1; 
      int location2 = rand() % 100 + 1; 
      tft.setCursor(location1, location2, 2);
      tft.println(verse_eight[i]);
      delay(730);
      tft.fillScreen(TFT_BLACK);
    }

    //verse nine
    for (int i = 0; i < 13; i++)
    {
      currentLine = verse_nine[i];
      if (i%3 == 1)
      {
        tft.setTextColor(TFT_RED);
      }
      else if (i%3 == 2)
      {
        tft.setTextColor(TFT_ORANGE);
      }
      else
      {
        tft.setTextColor(TFT_YELLOW);
      }
      tft.setTextSize(2);
      if (strlen(verse_nine[i]) > 14)
      {
        tft.setTextSize(1.75);
      }
      int location1 = rand() % (55 - strlen(verse_nine[i])) + 1; 
      int location2 = rand() % 100 + 1; 
      tft.setCursor(location1, location2, 2);
      tft.println(verse_nine[i]);
      delay(730);
      tft.fillScreen(TFT_BLACK);
    }

    //chorus
    for (int i = 0; i < 6; i++)
    {
      currentLine = chorus[i];
      if (i%3 == 1)
      {
        tft.setTextColor(TFT_RED);
      }
      else if (i%3 == 2)
      {
        tft.setTextColor(TFT_ORANGE);
      }
      else
      {
        tft.setTextColor(TFT_YELLOW);
      }
      tft.setTextSize(1);
      int location1 = 1; 
      int location2 = 50; 
      tft.setCursor(location1, 1 + (i%3)*50, 2);
      tft.println(chorus[i]);
      delay(730);
      tft.fillScreen(TFT_BLACK);
    }
  }
  // Set the font colour to be yellow with no background, set to font 7
  tft.setTextColor(TFT_YELLOW); tft.setTextFont(2);
  //tft.println("deadbeef");
  
  // Set the font colour to be red with black background, set to font 4
  tft.setTextColor(TFT_RED,TFT_BLACK);    tft.setTextFont(2);
  //tft.println("ellis"); // Should print DEADBEEF

  // Set the font colour to be green with black background, set to font 2
  tft.setTextColor(TFT_GREEN,TFT_BLACK);
  tft.setTextFont(2);
  //tft.println("chaotic");

  // Test some print formatting functions
  float fnumber = 123.45;
   // Set the font colour to be blue with no background, set to font 2
  tft.setTextColor(TFT_BLUE);    tft.setTextFont(4);
  // tft.print("Float = "); tft.println(fnumber);           // Print floating point number
  // tft.print("Binary = "); tft.println((int)fnumber, BIN); // Print as integer value in binary
  // tft.print("Hexadecimal = "); tft.println("i'm the one"); // Print as integer number in Hexadecimal

  while(1) yield(); // We must yield() to stop a watchdog timeout.
}
