/**
 * LIST OF COMPONENTS
 * 
 * - Arduino UNO
 * - Display LCD 16*2 with interfaz I2C
 * - Thermocouple type K (termocupla tipo K)
 * - Module MAX6675

* LIST OF LIBRARIES
* 
* - LiquidCyistal_I2C (Display LCD)
* - MAX6675 library 
* 
* @author PabloPalillo
* @since 2019
* @version 0.1
*/

#include <LiquidCrystal_I2C.h>
#include <max6675.h>

/**
 * Create object of lcd library 0x3F (16 COL- 2 ROWS)
 */
LiquidCrystal_I2C lcd(0x27,20,4);

const int pinMAXSCK = 5; //pin MAX6675 SCK to DITITAL pin 5 arduino
const int pinMAXCS  = 6; //pin MAX6675 SC to DITITAL pin 6 arduino
const int pinMAXSO  = 7; //pin MAX6675 SO to DITITAL pin 7 arduino
MAX6675 therm(pinMAXSCK, pinMAXCS, pinMAXSO); //Init MAX6675 component to arduino


/**
 * Display and I2C specification
 * - I2C pin GND to GND arduino
 * - I2C pin VCC to 5v or 3v arduino
 * - I2C pin SDA should to A4 ANALOG IN Arduino
 * - I2C pin SCL should be to A5 ANALOG IN Adrduino
 */
void initLCD()
{
  lcd.init(); //init liquidCrystal Module
  lcd.backlight(); //on the backlight of Display
}

/**
 * Show in Display LCD the message send.
 * @param text : message send to LCD
 * @param rowCursor : number of row to show message
 */
void showLCD(String textLCD, int rowCursor = 0, boolean LCDClear = false)
{
  if(rowCursor >= 0) 
  {
    lcd.setCursor(0, rowCursor);  
  }
  
  
  if(textLCD == "") 
  {
    textLCD = "Error";
  }

  if(LCDClear) 
  {
    lcd.clear(); //Clear print in LCD  
  }
  
  lcd.print(textLCD);
}


float getCelsius()
{
  float currentCelsius = therm.readCelsius();
  
  if(!currentCelsius) 
  {
    return 0;
  }

  return currentCelsius;
}

String getTextCurrentCelsius()
{
  float currentCelsius = getCelsius();
  String textCelsius = String(currentCelsius, 2);
  textCelsius += F(" C");

  return textCelsius;
}


void setup()
{
  initLCD(); //initialize options
  showLCD("TEMPERATURE ");
}

void loop()
{
  showLCD("TEMPERATURE: ");
  showLCD(getTextCurrentCelsius(), 1);
  delay(1000);
}
