/*
 * Micro-Jammer - nRF24L01+ esp32 
 * Copyright (c) [ixl55/darkshell] [2025]
 * All rights reserved.
 * 
 * This software is provided for educational purposes only.
 * Use of this software for any unauthorized interference with
 * wireless communications is strictly prohibited by law.
 */
/*
   I'm not in your network.
   I *am* your network.
   — signed: ixl55
   _      _ _____ _____ 
  (_)    | | ____| ____|
   ___  _| | |__ | |__  
  | \ \/ / |___ \|___ \ 
  | |>  <| |___) |___) |
  |_/_/\_\_|____/|____/ 
                      
 */
#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Custom SPI pin configuration for ESP32
#define SCK_PIN   4
#define MISO_PIN  5
#define MOSI_PIN  6
#define CE_PIN    20
#define CSN_PIN   21

// Initialize SPI and radio with custom pins
SPIClass spi(FSPI);  
RF24 radio(CE_PIN, CSN_PIN);

void setup() {
  Serial.begin(115200);
  delay(500);  // Allow time for serial monitor to connect

  // Initialize SPI with custom pins
  spi.begin(SCK_PIN, MISO_PIN, MOSI_PIN);

  Serial.println("\nMicro-Jammer Initialization");
  Serial.println("--------------------------");

  if (!radio.begin(&spi)) {
    Serial.println("ERROR: nRF24L01+ initialization failed!");
    while (1);  // Halt if radio doesn't initialize
  }

  Serial.println("nRF24L01+ successfully initialized");
  Serial.println("Configuring jammer settings...");

  // Configure radio for jamming operation
  radio.setAutoAck(false);          // Disable auto-acknowledgment
  radio.setRetries(0, 0);           // Disable retries
  radio.setPALevel(RF24_PA_MAX);    // Maximum power output
  radio.setDataRate(RF24_2MBPS);    // 2Mbps data rate
  radio.setCRCLength(RF24_CRC_DISABLED); // Disable CRC for faster switching
  radio.setChannel(0);              // Start on channel 0
  radio.stopListening();            // Put radio in TX mode
  
  // Start constant carrier wave transmission
  radio.startConstCarrier(RF24_PA_MAX, 45);
  
  // Seed random number generator for channel hopping
  randomSeed(analogRead(0));
  
  Serial.println("Jammer active - transmitting carrier wave");
  Serial.println("Random channel hopping enabled");
}

void loop() {
  // Randomly switch channels to spread interference
  byte channel = random(0, 126);  // 2.4GHz channels 0-125
  radio.setChannel(channel);
  
  // Random delay between channel switches
  delayMicroseconds(random(30, 100));
}
