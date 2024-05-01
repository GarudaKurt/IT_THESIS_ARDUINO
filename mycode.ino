#include <SoftwareSerial.h>

// Define the pins for SoftwareSerial
const int barcodeReaderRxPin = 7; // Connect the barcode reader TX pin to this pin
const int barcodeReaderTxPin = 8; // Connect the barcode reader RX pin to this pin

// Create a SoftwareSerial object
SoftwareSerial barcodeReader(barcodeReaderRxPin, barcodeReaderTxPin);

void setup() {
  Serial.begin(9600);
  // Initialize SoftwareSerial for communication with the barcode reader
  barcodeReader.begin(9600);
}

void loop() {
  // Check if data is available from the barcode reader
  if (barcodeReader.available()) {
    // Read the data from the barcode reader
    char receivedChar = barcodeReader.read();
    
    // Print the received character to Serial monitor
    Serial.print(receivedChar);
  }
}
