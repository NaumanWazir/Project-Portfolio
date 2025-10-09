#define OUT1  11
#define OUT2  10
#define OUT3  9
#define C     14
#define SW1   15
#define SW2   16
#define SW3   17
#define SW6   18
#define SW7   19
#define PD0   0
#define PD1   1
#define PD2   2
#define PD3   3
#define PD4   4
#define U21   8
#define U22   7
#define U31   5
#define U32   6

int counter_u3 = 3;
int counter_u2 = 3;

int state_u31 = 0;
int state_u32 = 0;
int state_u21 = 0;
int state_u22 = 0;

int keySevState;
int lastkeySevState = LOW;


int keySixState;
int lastkeySixState = LOW;
int flash_enable = 0;
int flash_counter = 0;
int flash_state = 0;
int flash_start = 1;
int store_c3 = 0;
int store_c2 = 0;
int enable_both = 1;
int enable_u2 = 1;
int activate = 1;

unsigned long scantime = 200;
unsigned long timepass = 0;
unsigned long keySevTimepass = 0;
unsigned long keySixTimepass = 0;
unsigned long wait3sec = 1000;

int mem11 = 5;
int mem12 = 5;
int mem21 = 5;
int mem22 = 5;
int state=0; 

void setup() 
{

//Serial.begin(9600);  
pinMode(C, OUTPUT);
pinMode(SW1, OUTPUT);
pinMode(SW2, OUTPUT);
pinMode(SW3, OUTPUT);
pinMode(SW6, OUTPUT);
pinMode(SW7, OUTPUT);

pinMode(U21, OUTPUT);
pinMode(U22, OUTPUT);
pinMode(U31, OUTPUT);
pinMode(U32, OUTPUT);

pinMode(PD0, OUTPUT);
pinMode(PD1, OUTPUT);
pinMode(PD2, OUTPUT);
pinMode(PD3, OUTPUT);
pinMode(PD4, OUTPUT);


pinMode(OUT1, OUTPUT);
pinMode(OUT2, OUTPUT);
pinMode(OUT3, OUTPUT);

digitalWrite(U21,LOW); 
digitalWrite(U22,LOW);
digitalWrite(U31,LOW); 
digitalWrite(U32,LOW);

digitalWrite(PD0, LOW);
digitalWrite(PD1, LOW);
digitalWrite(PD2, LOW);
digitalWrite(PD3, LOW);
digitalWrite(PD4, LOW);

digitalWrite(C, LOW);
digitalWrite(SW1, LOW);
digitalWrite(SW2,LOW); 
digitalWrite(SW3,LOW);
digitalWrite(SW6,LOW); 
digitalWrite(SW7,LOW);

digitalWrite(C, HIGH);
digitalWrite(SW1, HIGH);
timepass = millis();
}

void loop() 
{
if ((millis() - timepass) > scantime) 
	{
    state =! state;
    activate = 1;
    digitalWrite(OUT1,state);     
	  timepass = millis();
    if(!enable_both)
    {
    analogWrite(OUT2, 0);
    analogWrite(OUT3, 0);
    }
    else
    {
    analogWrite(OUT2, counter_u3*25);
    if(enable_u2)
      analogWrite(OUT3, counter_u2*25);
    else
      analogWrite(OUT3, 0);      
    }

    if (flash_enable)
    {    
      flash_state =! flash_state;
      if (flash_start)
      {
        flash_start = 0;
        store_c3 = counter_u3;
        store_c2 = counter_u2;                 
      }       

      if(flash_state)
      {
        counter_u3 = store_c3;
        counter_u2 = store_c2;
      }
      else
      {
        counter_u3 = 0;
        counter_u2 = 0;
      }    
      flash_counter++;
      if(flash_counter == 10)
      {
        flash_counter = 0;
        flash_enable = 0;
        flash_start = 1;
        counter_u3 = store_c3;
        counter_u2 = store_c2;       
      }         
    
    }  
  }

 if(state)
 {
  if(activate)
  {     
  digitalWrite(C, HIGH);
  digitalWrite(SW1, LOW);
//increment u3  
  if(digitalRead(SW2))
    {
    //Serial.println("Key3");
    counter_u3++;
    if (counter_u3 > 10)
      counter_u3 = 10; 
    activate = 0; 
    digitalWrite(SW2, LOW);     
    }
//decrement u3
  if(digitalRead(SW3))
    {
    //Serial.println("Key4");      
    counter_u2++;
    if (counter_u2 > 10)
      counter_u2 = 10; 
    activate = 0; 
    digitalWrite(SW3, LOW);     
    }
    
  int reading2 = digitalRead(SW6);
  if (reading2 != lastkeySixState) 
  {
    // reset the debouncing timer
    keySixTimepass = millis();
  }
  if(!reading2)
  {
    if (lastkeySixState)
    {
     //Serial.println("Key6");
     counter_u3 = mem11;
     counter_u2 = mem12;    
     enable_both = 1;
     enable_u2 = 1;
     activate = 0; 
     }    
  }
 if ((millis() - keySixTimepass) > wait3sec) 
 {
  if (reading2 != keySixState)
  {
    keySixState = reading2;
    if (keySixState == HIGH)
      {
      //Serial.println("Key6L");    
      mem11 = counter_u3;
      mem12 = counter_u2;
      flash_enable = 1;
      keySixState = LOW;
      keySixTimepass = millis();
      activate = 0;
      }
    }
  }
  lastkeySixState = reading2;
      
  int reading1 = digitalRead(SW7);
  if (reading1 != lastkeySevState) 
  {
    // reset the debouncing timer
    keySevTimepass = millis();
  }
  if(!reading1)
  {
    if (lastkeySevState)
    {
     //Serial.println("Key7");
     counter_u3 = mem21;
     counter_u2 = mem22;
     
    enable_both = 1;
    enable_u2 = 1;
     activate = 0; 
     }    
  }
 if ((millis() - keySevTimepass) > wait3sec) 
 {
  if (reading1 != keySevState)
  {
    keySevState = reading1;
    if (keySevState == HIGH)
      {
      //Serial.println("Key7L");
      mem21 = counter_u3;
      mem22 = counter_u2;
      flash_enable = 1;
      keySevState = LOW;
      keySevTimepass = millis();
      activate = 0;
      }
    }
  }
  lastkeySevState = reading1;
  }
}
else
{
  if (activate)
  {
  digitalWrite(C, LOW);
  digitalWrite(SW1, HIGH);    
  if(digitalRead(SW3))
    {
    //Serial.println("Key5");
    enable_both =! enable_both; 
    if (enable_both)
      enable_u2 = 1;
    activate = 1;
    digitalWrite(SW3, LOW);     
    }
    //key8  
  if(digitalRead(SW2))
    {
    //Serial.println("Key8");  
    enable_u2 =! enable_u2; 
    activate = 0;
    digitalWrite(SW2, LOW);     
    }
    //increment u2
  if(digitalRead(SW6))
    {
    //Serial.println("Key1");       
      counter_u3--;
    if (counter_u3 <= 1)
      counter_u3 = 1; 
    activate = 0;   
    digitalWrite(SW6, LOW);     
    }    
        
  if(digitalRead(SW7))
    {
    //Serial.println("Key2");
      counter_u2--;
    if (counter_u2 <= 1)
      counter_u2 = 1; 
    activate = 1;   
    digitalWrite(SW7, LOW);    
    }     
   }
  }
if (enable_both)
	{    
	if(enable_u2)
		{
      if (counter_u2 > 5)
        {
        state_u22 = counter_u2 - 5;
        state_u21 = 5;
        }
      else
        {
        state_u22 = 0;
        state_u21 = counter_u2;      
        }          
      Switch_Matrix_Lower(state_u21);   
      digitalWrite(U21, HIGH); 
      delay(2);                       
      digitalWrite(U21, LOW);
      // WRITE U22 
      Switch_Matrix_Lower(state_u22);   
      digitalWrite(U22, HIGH);  
      delay(2);                       
      digitalWrite(U22, LOW);
		}
	else
		{
		Switch_Matrix_Lower(0);   
		digitalWrite(U21, HIGH); 
		delay(2);                       
		digitalWrite(U21, LOW);
		// WRITE U22 
		Switch_Matrix_Lower(0);   
		digitalWrite(U22, HIGH);  
		delay(2);                       
		digitalWrite(U22, LOW);
		}  
	// WRITE U31 
  if (counter_u3 > 5)
    {
    state_u32 = counter_u3 - 5;
    state_u31 = 5;
    }
  else
    {
    state_u32 = 0;
    state_u31 = counter_u3;      
    }  
	Switch_Matrix_Upper(state_u31);   
	digitalWrite(U31, HIGH); 
	delay(2);                       
	digitalWrite(U31, LOW);

	// WRITE U32 
	Switch_Matrix_Upper(state_u32);   
	digitalWrite(U32, HIGH);  
	delay(2);                       
	digitalWrite(U32, LOW);  
	}
}

void Switch_Matrix_Upper(int cases)
{
switch(cases)
	{
	case 1:       
		digitalWrite(PD0, HIGH);  
		digitalWrite(PD1, LOW);  
		digitalWrite(PD2, LOW);  
		digitalWrite(PD3, LOW);  
		digitalWrite(PD4, LOW);      
		break;
	case 2:       
		digitalWrite(PD0, HIGH);  
		digitalWrite(PD1, HIGH);  
		digitalWrite(PD2, LOW);  
		digitalWrite(PD3, LOW);  
		digitalWrite(PD4, LOW);      
		break;
	case 3:       
		digitalWrite(PD0, HIGH);  
		digitalWrite(PD1, HIGH);  
		digitalWrite(PD2, HIGH);  
		digitalWrite(PD3, LOW);  
		digitalWrite(PD4, LOW);      
		break;
	case 4:       
		digitalWrite(PD0, HIGH);  
		digitalWrite(PD1, HIGH);  
		digitalWrite(PD2, HIGH);  
		digitalWrite(PD3, HIGH);  
		digitalWrite(PD4, LOW);      
		break;
	case 5:       
		digitalWrite(PD0, HIGH);  
		digitalWrite(PD1, HIGH);  
		digitalWrite(PD2, HIGH);  
		digitalWrite(PD3, HIGH);  
		digitalWrite(PD4, HIGH);      
		break;
	default:
		digitalWrite(PD0, LOW);  
		digitalWrite(PD1, LOW);  
		digitalWrite(PD2, LOW);  
		digitalWrite(PD3, LOW);  
		digitalWrite(PD4, LOW);      
		break;
	}
}

void Switch_Matrix_Lower(int cases)
{
switch(cases)
	{
	case 1:       
		digitalWrite(PD0, LOW);  
		digitalWrite(PD1, LOW);  
		digitalWrite(PD2, LOW);  
		digitalWrite(PD3, LOW);  
		digitalWrite(PD4, HIGH);      
		break;
	case 2:       
		digitalWrite(PD0, LOW);  
		digitalWrite(PD1, LOW);  
		digitalWrite(PD2, LOW);  
		digitalWrite(PD3, HIGH);  
		digitalWrite(PD4, HIGH);      
		break;
	case 3:       
		digitalWrite(PD0, LOW);  
		digitalWrite(PD1, LOW);  
		digitalWrite(PD2, HIGH);  
		digitalWrite(PD3, HIGH);  
		digitalWrite(PD4, HIGH);      
		break;
	case 4:       
		digitalWrite(PD0, LOW);  
		digitalWrite(PD1, HIGH);  
		digitalWrite(PD2, HIGH);  
		digitalWrite(PD3, HIGH);  
		digitalWrite(PD4, HIGH);      
		break;
	case 5:       
		digitalWrite(PD0, HIGH);  
		digitalWrite(PD1, HIGH);  
		digitalWrite(PD2, HIGH);  
		digitalWrite(PD3, HIGH);  
		digitalWrite(PD4, HIGH);      
		break;
	default:
		digitalWrite(PD0, LOW);  
		digitalWrite(PD1, LOW);  
		digitalWrite(PD2, LOW);  
		digitalWrite(PD3, LOW);  
		digitalWrite(PD4, LOW);      
		break;
	}
}