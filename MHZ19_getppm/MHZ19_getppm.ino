#include <MHZ.h>

/*----------------------------------------------------------
    MH-Z19 CO2 sensor  SAMPLE
  ----------------------------------------------------------*/

#include <MHZ19_uart.h>

const int rx_pin = A1;	//Serial rx pin no
const int tx_pin = A0;	//Serial tx pin no

MHZ19_uart mhz19;

/*----------------------------------------------------------
    MH-Z19 CO2 sensor  setup
  ----------------------------------------------------------*/
void setup() {
  Serial.begin(9600);
  mhz19.begin(rx_pin, tx_pin);
}

/*----------------------------------------------------------
    MH-Z19 CO2 sensor  loop
  ----------------------------------------------------------*/
void loop() {
  int co2ppm = mhz19.getPPM();
  int temp = mhz19.getTemperature();

  Serial.print("co2: "); Serial.println(co2ppm);
  Serial.print("temp: "); Serial.println(temp);

  Serial.print("CO2 PPM: ");
  Serial.println(co2ppm);
  Serial.print("Temperature: ");
  Serial.println(temp);

  if ((co2ppm < 0) || (co2ppm == 410))
  {
    Serial.println("Sensor Not Ready!");
  }
  
}
