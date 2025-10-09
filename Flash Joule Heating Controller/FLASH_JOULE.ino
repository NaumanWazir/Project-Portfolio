//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
// SCL is A5 on board
// SDA is A4 on board
#define PRESS_CONTR 2   
#define VOLT_CONTR 3
#define CHARGING 4
#define FIRE 5

#define POW_LED 7
#define CHRG_LED 6
#define FIRE_LED 8
#define SCR_LED 9
#define RELAY1 10
#define RELAY2 11

#define scantime 1000

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

uint8_t chargingIsOn = 0;
uint8_t endItAll = 0;
uint8_t readyToFire = 0;
uint8_t voltageIsReady = 0;
uint8_t pressureIsReady = 0;
uint8_t flashFire = 0;
uint8_t fireState = 0;
unsigned long int fireTime = 0;

unsigned long int time = 0;
unsigned long int buttonTimer = 0;
char button_state;
char last_button_state;
unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50; 

void setup()
{
  //Serial.begin(9600);
  pinMode(PRESS_CONTR, INPUT);
  pinMode(VOLT_CONTR, INPUT);
  pinMode(CHARGING, INPUT_PULLUP);
  pinMode(FIRE, INPUT);
  
  pinMode(POW_LED, OUTPUT);  
  pinMode(CHRG_LED, OUTPUT);  
  pinMode(FIRE_LED, OUTPUT);
  pinMode(SCR_LED, OUTPUT);  
  pinMode(RELAY1, OUTPUT);  
  pinMode(RELAY2, OUTPUT);
  digitalWrite(POW_LED, HIGH);
  //attachInterrupt(digitalPinToInterrupt(BT2),checkBT2, FALLING);
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  
  lcd.setCursor(3,0);
  lcd.print("CYBORTRONX");
  delay(1000);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("FLASH JOULE");
  lcd.setCursor(3,1);
  lcd.print("HEATING");
  delay(1000);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("11/06/2023");
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("WAITING");
  lcd.setCursor(3,1);
  lcd.print("FOR INPUT");
  
  time =  millis();
  
}

void loop()
{
  unsigned char reading = getStates();
  if(reading > 0)
  {
    if (reading != last_button_state) 
    {
      lastDebounceTime = millis();
    }
    if ((millis() - lastDebounceTime) > debounceDelay)
    {
      if (reading != button_state)
      {
        button_state = reading;
        if(button_state == 2)
        {
          voltageIsReady = 1;
          buttonTimer = millis();
        }
        if(button_state == 3)
        {
          pressureIsReady = 1;
          buttonTimer = millis();  
        } 
        if(button_state == 4)
        {
          lcd.clear();
          lcd.setCursor(4,0);
          lcd.print("SYSTEM");
          lcd.setCursor(3,1);
          lcd.print("CHARGING");
          digitalWrite(RELAY1, HIGH);
          digitalWrite(RELAY2, HIGH);
          analogWrite(CHRG_LED, 127);
          chargingIsOn = 1;
          voltageIsReady = 0;
          pressureIsReady = 0;           
        } 
        if(button_state == 5)
        {
          if(readyToFire)
          {
            // Was not in your requirement comment our these three lines if not needed
            lcd.clear();
            lcd.setCursor(4,0);
            lcd.print("FIRE");
            digitalWrite(RELAY1, LOW);
            digitalWrite(RELAY2, LOW);
            flashFire = 0;
            readyToFire = 0;
            endItAll = 1;
          }
        } 
      }
    }
  }
  last_button_state = reading;
  
  if (voltageIsReady || pressureIsReady)
    if(millis()-buttonTimer>=1000)
    {
      voltageIsReady = 0;
      pressureIsReady = 0;
    }
  
  if(voltageIsReady && pressureIsReady)
  {
    if(chargingIsOn)
    {
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("SYSTEM");
      lcd.setCursor(1,1);
      lcd.print("READY TO FIRE");
      digitalWrite(CHRG_LED, HIGH);
      readyToFire = 1;
      voltageIsReady = 0;
      pressureIsReady = 0;   
      flashFire = 1;
      chargingIsOn = 0;
      fireTime = millis();
    }    
  }
  if (flashFire)
  {
    if ((millis() - fireTime) >= scantime)
    {
      if(fireState)
      {
        digitalWrite(FIRE_LED, HIGH);
        fireState = 0;
      }
      else      
      {
        digitalWrite(FIRE_LED, LOW);
        fireState = 1;
      }
      fireTime = millis();
    } 
  }
  if(endItAll)
  {
    for(int i=0;i<4;i++)
    {
      digitalWrite(FIRE_LED, HIGH);
      delay(250);
      digitalWrite(FIRE_LED, LOW);
      delay(250);
    }
    digitalWrite(SCR_LED, HIGH);
    delay(200);
    digitalWrite(SCR_LED, LOW);
    endItAll = 0;
  }
    
}

char getStates(void)
{
  boolean B2 = digitalRead(PRESS_CONTR);
  boolean B3 = digitalRead(VOLT_CONTR);
  boolean B4 = digitalRead(CHARGING);
  boolean B5 = digitalRead(FIRE);
  
    if (B2 == HIGH)
        return 2;
    if (B3 == HIGH)
        return 3;
    if (B4 == LOW)
        return 4;
    if (B5 == HIGH)
        return 5;
return 0;    
}
