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

void setup()
{
  InitLCD(); //initialize options
}

/**
 * Display and I2C specification
 * - I2C pin GND to GND arduino
 * - I2C pin VCC to 5v or 3v arduino
 * - I2C pin SDA should to A4 ANALOG IN Arduino
 * - I2C pin SCL should be to A5 ANALOG IN Adrduino
 */
void InitLCD()
{
  lcd.init(); //init liquidCrystal Module
  lcd.backlight(); //on the backlight of Display
}

/**
 * Show in Display LCD the message send.
 * @param text : message send to LCD
 */
void showLCD(String textLCD)
{
  if(textLCD == null || textLCD == "") 
  {
    textLCD = "Error";
  }
  
  lcd.clear(); //Clear print in LCD
  lcd.print(textLCD);
}
