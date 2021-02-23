/*
 * Displays text sent over the serial port (e.g. from the Serial Monitor) on
 * an attached LCD.
 * YWROBOT
 *Compatible with the Arduino IDE 1.0
 *Library version:1.1
 */
#include <Wire.h> 
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino




int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value
int airquality = 0;

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
}

void loop()
{

    int sensorValue = analogRead(A0);
  //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //Print temp and humidity values to serial monitor
    lcd.setCursor(0,0);
    lcd.backlight();   
    lcd.print("H:");
    lcd.print(hum);
    lcd.print("%, "); 
    lcd.backlight();
    lcd.print("T:");
    lcd.print(temp);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.backlight();
    lcd.print("AQ=");
    lcd.print(sensorValue);
    lcd.print("*PPM");
    delay(1000);
 
  
  
  if(250 >= sensorValue <=1000)
  {
if(50 >= hum >= 54.9 || hum<=50){
        if(28.2 >= temp >= 38.2 || temp<=28.2){
            //lcd.setCursor(0,1);
            lcd.clear();
            lcd.print("The AQ, H& T are normal");
            delay(1000);
         }
         
          else{
            //lcd.setCursor(0,1);
            lcd.clear();
            lcd.print("AQ:Normal, T&H: Not normal");
            delay(1000);
            }}
else if ( 55 >= hum >= 59.99 || hum<=55){
        if(28.6 >= temp <= 39.9){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The AQ, H& T are normal");
          delay(1000);        
      }
        
        else if( 30 >= temp <= 32 ){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("AQ:Normal, T&H: Not normal ");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature and humidity are abnormal. Please be weary of your surroundings ");
          delay(1000);
        }} 
else if( 60 >= hum >= 64.99 || hum<=60){
 if(29.1 >= temp <= 39 || temp<=29.1){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The AQ, H& T are normal");
          delay(1000);
        
      }
        else if( 41.9 >= temp <= 54.2){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature is unappropriate in the humidty. Please be cautious.");
          delay(1000);
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature and humidity are abnormal. Please be weary of your surroundings");
          delay(1000);
        }}
else if( 65 >= hum >= 69.99 || hum<=65){
if(29.7 >= temp <= 37.8 || temp<=29.7){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The AQ, H& T are normal");
          delay(1000);        
      }
        
        else if( 40.8 >= temp <= 53.4){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature is unappropriate in the humidty. Please be cautious.");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature and humidity are abnormal. Please be weary of your surroundings");
          delay(1000);
        }}
else if( 70 >= hum >= 74.99 || hum<=70){
if(30.2 >= temp <= 39.4 || temp<=30.2){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality, Humidity and Temperature are normal.");
          delay(1000);
             }
        
        else if( 42.8 >= temp >= 52.4){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature is unappropriate in the humidty. Please be cautious.");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature and humidity are abnormal. Please be weary of your surroundings.");
          delay(1000);
        } }
else if( 75 >= hum >= 79.99 || hum<=75){
if(30.9 >= temp <= 37.9 || temp<=30.9){
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("The Air Quality, Humidity and Temperature are normal.");
          delay(1000);
        }
        
        else if( 41.2 >= temp <= 53.3 ){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature is unappropriate in the humidty. Please be cautious.");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature and humidity are abnormal. Please be weary of your surroundings.");
          delay(1000);
        }  }        
else if( 80 >= hum >= 84.99 || hum<=80){
if(31.6 >= temp <= 39.4 || temp<=31.6){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality, Humidity and Temperature are normal.");
          delay(1000);
        }
      
        else if( 43.2 >= temp <= 51.7){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("in the humidty. Please be cautious.");
        }
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature and humidity are abnormal. Please be weary of your surroundings.");
          delay(1000);
        }}
else if( 85 >= hum >= 89.99 || hum<=85){
if(32.3 >= temp <= 39.1 || temp<=32.3){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality, Humidity and Temperature are normal.");
          delay(1000);
              }
        
        else if( 41.1 >= temp <= 54.7){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature is unappropriate in the humidty. Please be cautious.");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature and humidity are abnormal. Please be weary of your surroundings.");
          delay(1000);
        }}

else if( 90 >= hum >= 94.99 || hum<=90){
if(33.1 >= temp <= 36.7 || temp <= 33.1){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality, Humidity and Temperature are normal.");
          delay(1000);
        }
      
        else if( 40.7 >= temp <= 52.5){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature is unappropriate in the humidty. Please be cautious.");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature and humidity are abnormal. Please be weary of your surroundings.");
          delay(1000);
        }
}
else if( 95 >= hum >= 99.99 || hum<=95){
if(33.9 >= temp <= 37.9 || temp <= 33.9){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality, Humidity and Temperature are normal.");
          delay(1000);
        }
      
        else if(42.7 >= temp <= 54.6){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature is unappropriate in the humidty. Please be cautious.");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature and humidity are abnormal. Please be weary of your surroundings.");
          delay(1000);
        }  }
 else if( hum ==100){
if(34.7 >= temp <= 39.3 || temp<= 34.7){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality, Humidity and Temperature are normal.");
          delay(1000);
        }
      
else if( 44.2 >= temp <= 52.4)
{
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("The Air Quality is normal but the temperature is unappropriate in the humidty. Please be cautious.");
        }
        
        else
        { 
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature and humidity are abnormal. Please be weary of your surroundings.");
          delay(1000);
        }  }
  }




//pangalawang code

 else if(1001 >= sensorValue <=1000)
  {
if(50 >= hum >= 54.9 || hum<=50){
        if(28.2 >= temp >= 38.2 || temp<=28.2){
          //lcd.setCursor(0,1);
          lcd.clear();
            lcd.print("The Air Quality is slightly abnormal but the Temperature and Humidity are normal.");
            delay(1000);
         }
         
          else{
            //lcd.setCursor(0,1);
            lcd.clear();
            lcd.print("The Air Quality is slightly abnormal but the temperature is unappropriate in the humidty. Please be cautious.");
            delay(1000);
            }}
else if ( 55 >= hum >= 59.99 || hum<=55){
        if(28.6 >= temp <= 39.9){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is slightly abnormal but the Temperature and Humidity are normal.");
          delay(1000);        
      }
        
        else if( 30 >= temp <= 32 ){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is slightly abnormal but the temperature is unappropriate in the humidty. Please be cautious.");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality, Temperature and Himidty are abnormal. Please be weary of your surroundings.");
          delay(1000);
        }} 
else if( 60 >= hum >= 64.99 || hum<=60){
 if(29.1 >= temp <= 39 || temp<=29.1){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is slightly abnormal but the Temperature and Humidity are normal.");
          delay(1000);
        
      }
        else if( 41.9 >= temp <= 54.2){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is slightly abnormal but the temperature is unappropriate in the humidty. Please be cautious.");
          delay(1000);
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("The Air Quality, Temperature and Himidty are abnormal. Please be weary of your surroundings.");
          delay(1000);
        }}
else if( 65 >= hum >= 69.99 || hum<=65){
if(29.7 >= temp <= 37.8 || temp<=29.7){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is slightly abnormal but the Temperature and Humidity are normal.");
          delay(1000);        
      }
        
        else if( 40.8 >= temp <= 53.4){
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("The Air Quality is slightly abnormal but the temperature is unappropriate in the humidty. Please be cautious.");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("The Air Quality, Temperature and Himidty are abnormal. Please be weary of your surroundings.");
          delay(1000);
        }}
else if( 70 >= hum >= 74.99 || hum<=70){
if(30.2 >= temp <= 39.4 || temp<=30.2){
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("The Air Quality is slightly abnormal but the Temperature and Humidity are normal.");
          delay(1000);
             }
        
        else if( 42.8 >= temp >= 52.4){
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("The Air Quality is slightly abnormal but the temperature is unappropriate in the humidty. Please be cautious.");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature and humidity are abnormal. Please be weary of your surroundings.");
          delay(1000);
        } }
else if( 75 >= hum >= 79.99 || hum<=75){
if(30.9 >= temp <= 37.9 || temp<=30.9){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is slightly abnormal but the Temperature and Humidity are normal.");
          delay(1000);
        }
        
        else if( 41.2 >= temp <= 53.3 ){
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("The Air Quality is slightly abnormal but the temperature is unappropriate in the humidty. Please be cautious.");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("The Air Quality, Temperature and Himidty are abnormal. Please be weary of your surroundings.");
          delay(1000);
        }  }        
else if( 80 >= hum >= 84.99 || hum<=80){
if(31.6 >= temp <= 39.4 || temp<=31.6){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is slightly abnormal but the Temperature and Humidity are normal.");
          delay(1000);
        }
      
        else if( 43.2 >= temp <= 51.7){
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("The Air Quality is slightly abnormal but the temperature is unappropriate in the humidty. Please be cautious.");
        }
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("The Air Quality, Temperature and Himidty are abnormal. Please be weary of your surroundings.");
          delay(1000);
        }}
else if( 85 >= hum >= 89.99 || hum<=85){
if(32.3 >= temp <= 39.1 || temp<=32.3){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is slightly abnormal but the Temperature and Humidity are normal.");
          delay(1000);
              }
        
        else if( 41.1 >= temp <= 54.7){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is slightly abnormal but the temperature is unappropriate in the humidty. Please be cautious.");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature and humidity are abnormal. Please be weary of your surroundings.");
          delay(1000);
        }}

else if( 90 >= hum >= 94.99 || hum<=90){
if(33.1 >= temp <= 36.7 || temp <= 33.1){
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("The Air Quality, Humidity and Temperature are normal.");
          delay(1000);
        }
      
        else if( 40.7 >= temp <= 52.5){
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("The Air Quality is normal but the temperature is unappropriate in the humidty. Please be cautious.");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature and humidity are abnormal. Please be weary of your surroundings.");
          delay(1000);
        }
}
else if( 95 >= hum >= 99.99 || hum<=95){
if(33.9 >= temp <= 37.9 || temp <= 33.9){
         // lcd.setCursor(0,1);
         lcd.clear();
          lcd.print("The Air Quality is slightly abnormal but the Temperature and Humidity are normal..");
          delay(1000);
        }
      
        else if(42.7 >= temp <= 54.6){
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("Humidity are normal.The Air Quality is slightly abnormal but the temperature is unappropriate in the humidty. Please be cautious.");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("The Air Quality is normal but the temperature and humidity are abnormal. Please be weary of your surroundings.");
          delay(1000);
        }  }
 else if( hum ==100){
if(34.7 >= temp <= 39.3 || temp<= 34.7){
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("The Air Quality, Humidity and Temperature are normal.");
          delay(1000);
        }
      
else if( 44.2 >= temp <= 52.4)
{
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The Air Quality is normal but the temperature is unappropriate in the humidty. The Air Quality is slightly abnormal but the temperature is unappropriate in the humidty. Please be cautious.");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("The The Air Quality, Temperature and Himidty are abnormal the temperature and humidity are abnormal. Please be weary of your surroundings.");
          delay(1000);
        }  }
  }


  //THIRD CODE

  else if(5001 >= sensorValue)
  {
if(50 >= hum >= 54.9 || hum<=50){
        if(28.2 >= temp >= 38.2 || temp<=28.2){
            //lcd.setCursor(0,1);
            lcd.clear();
            lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
            delay(1000);
         }
         
          else{
            //lcd.setCursor(0,1);
            lcd.clear();
            lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
            delay(1000);
            }}
else if ( 55 >= hum >= 59.99 || hum<=55){
        if(28.6 >= temp <= 39.9){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);        
      }
        
        else if( 30 >= temp <= 32 ){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
        }} 
else if( 60 >= hum >= 64.99 || hum<=60){
 if(29.1 >= temp <= 39 || temp<=29.1){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
        
      }
        else if( 41.9 >= temp <= 54.2){
          //lcd.setCursor(0,1);
          lcd.clear();
         lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
        }}
else if( 65 >= hum >= 69.99 || hum<=65){
if(29.7 >= temp <= 37.8 || temp<=29.7){
          // lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);        
      }
        
        else if( 40.8 >= temp <= 53.4){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
        }}
else if( 70 >= hum >= 74.99 || hum<=70){
if(30.2 >= temp <= 39.4 || temp<=30.2){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
             }
        
        else if( 42.8 >= temp >= 52.4){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
        } }
else if( 75 >= hum >= 79.99 || hum<=75){
if(30.9 >= temp <= 37.9 || temp<=30.9){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
        }
        
        else if( 41.2 >= temp <= 53.3 ){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
        }  }        
else if( 80 >= hum >= 84.99 || hum<=80){
if(31.6 >= temp <= 39.4 || temp<=31.6){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
        }
      
        else if( 43.2 >= temp <= 51.7){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
        }
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
        }}
else if( 85 >= hum >= 89.99 || hum<=85){
if(32.3 >= temp <= 39.1 || temp<=32.3){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
              }
        
        else if( 41.1 >= temp <= 54.7){
         //lcd.setCursor(0,1);
         lcd.clear();
         lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
        }}

else if( 90 >= hum >= 94.99 || hum<=90){
if(33.1 >= temp <= 36.7 || temp <= 33.1){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
        }
      
        else if( 40.7 >= temp <= 52.5){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
        }
}
else if( 95 >= hum >= 99.99 || hum<=95){
if(33.9 >= temp <= 37.9 || temp <= 33.9){
        //lcd.setCursor(0,1);
        lcd.clear();
         lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
        }
      
        else if(42.7 >= temp <= 54.6){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
        }  }
 else if( hum ==100){
if(34.7 >= temp <= 39.3 || temp<= 34.7){
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
        }
      
else if( 44.2 >= temp <= 52.4)
{
  //lcd.setCursor(0,1);
  lcd.clear();
         lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
        }
        
        else
        {
          //lcd.setCursor(0,1);
          lcd.clear();
          lcd.print("CAUTION PLEASE EVACUATE IMMADIATELY");
          delay(1000);
        }  }
  }


else{
  //lcd.setCursor(0,1);
  lcd.clear();
  lcd.print("INVALID INPUTS");
  delay(1000);
}

  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.setCursor(0,0);  
      lcd.write(Serial.read());
    }
  }
    

}
