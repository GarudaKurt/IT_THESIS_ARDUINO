#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

// Define the pins for SoftwareSerial
const int barcodeReaderRxPin = 7; // Connect the barcode reader TX pin to this pin
const int barcodeReaderTxPin = 8; // Connect the barcode reader RX pin to this pin

LiquidCrystal_I2C lcd(0x27, 16, 2);  
// Create a SoftwareSerial object
SoftwareSerial barcodeReader(barcodeReaderRxPin, barcodeReaderTxPin);

void setup() {
  lcd.clear();
  lcd.init();
  lcd.backlight();
  
  Serial.begin(9600);
  // Initialize SoftwareSerial for communication with the barcode reader
  barcodeReader.begin(9600);
}

void scrollText() {
  static int scrollPosition = 0;
  String message = "Waiting of barcode scanner...";
  // Clear the display
  lcd.clear();
  
  lcd.setCursor(0, 0);
  
  lcd.print(message.substring(scrollPosition, scrollPosition + 16));
  
  lcd.setCursor(0, 1);
  
  lcd.print(message.substring(0, scrollPosition));
  
  scrollPosition++;
  
  if (scrollPosition >= message.length()) {
    scrollPosition = 0;
  }
}

void loop() {
  // Check if data is available from the barcode reader
  lcd.setCursor(0,0);
  lcd.print(scrollText());
  if (barcodeReader.available()) {
    // Read the data from the barcode reader
    char receivedChar = barcodeReader.read();
    lcd.setCursor(0,1);
    lcd.print(recievedChar);
    // Print the received character to Serial monitor
    Serial.print(receivedChar);
    delay(3000);
    lcd.clear();
  }
}
