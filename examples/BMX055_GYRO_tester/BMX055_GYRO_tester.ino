/*
    Code written by Chia Jiun Wei @ 31-8-2017
    This code test the BMX055_Gyro library
*/

/*  PIN connection for a MSP432 LaunchPad board:
    P6.0 - > BMX055 CSG, define P6.0 as SPI chip select
*/

#include "BMX055_GYRO.h"

DSPI master;        // used EUSCI_B0
BMX055_GYRO imu_gyro(&master, 2);

s16 gyro_data[3];

void setup()
{
  // initialize the UART
  Serial.begin(115200);
  delay(300);

  // initialise SPI:
  master.begin();
  delay(300);

  Serial.print("**** Start BMX055 Gyroscope test ****");
  Serial.println();

  //initalise BMX055 Gyroscope
  imu_gyro.init();

  Serial.print("BMX055 Gyroscope initialised");
  Serial.println();
  Serial.print("Pinging BMX055 Gyroscope...");
  Serial.println();

  if (imu_gyro.ping() == 1)
  {
    Serial.print("Ping sucess");
    Serial.println();
  }
  else
  {
    Serial.print("Ping fail");
    Serial.println();
  }
}

void loop()
{
  Serial.print("Reading Gyroscope data");
  Serial.println();
  imu_gyro.get_gyro(gyro_data);

  Serial.print("Gyro x: ");
  Serial.print(gyro_data[0], DEC);
  Serial.print("  ");
  Serial.print("Gyro y: ");
  Serial.print(gyro_data[1], DEC);
  Serial.print("  ");
  Serial.print("Gyro z: ");
  Serial.print(gyro_data[2], DEC);
  Serial.print("  ");
  Serial.println();
}

