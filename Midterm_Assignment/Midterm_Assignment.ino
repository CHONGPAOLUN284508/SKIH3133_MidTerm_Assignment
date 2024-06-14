#include <ESP8266WiFi.h> // Include the ESP8266 WiFi library for Wi-Fi connectivity
#include <ESP8266HTTPClient.h> // Include the HTTP client library for making HTTP requests
#include <DHT.h> // Include the DHT sensor library for temperature and humidity readings

// WiFi credentials
const char* ssid = "A15"; // Replace with your WiFi SSID
const char* password = "chong1151"; // Replace with your WiFi password

// Server URL
const char* serverName = "http://192.168.207.8/assignment3/store_data.php"; // URL of the PHP script to store data

// DHT settings
#define DHTPIN D4 // DHT11 sensor connected to GPIO D4
#define DHTTYPE DHT11 // Specify the type of DHT sensor
DHT dht(DHTPIN, DHTTYPE); // Initialize the DHT sensor

// Ultrasonic sensor pins
#define TRIG_PIN D6 // Trig pin connected to GPIO D6
#define ECHO_PIN D5 // Echo pin connected to GPIO D5

// Function to measure distance using the ultrasonic sensor
long measureDistance() {
    digitalWrite(TRIG_PIN, LOW); // Ensure the trigger pin is low
    delayMicroseconds(2); // Wait for 2 microseconds
    digitalWrite(TRIG_PIN, HIGH); // Set the trigger pin high
    delayMicroseconds(10); // Wait for 10 microseconds
    digitalWrite(TRIG_PIN, LOW); // Set the trigger pin low
    long duration = pulseIn(ECHO_PIN, HIGH); // Measure the duration of the pulse
    long distance = duration * 0.034 / 2; // Calculate the distance in cm
    return distance; // Return the distance
}

void setup() {
    Serial.begin(115200); // Initialize serial communication at 115200 baud
    dht.begin(); // Initialize the DHT sensor
    pinMode(TRIG_PIN, OUTPUT); // Set the trigger pin as output
    pinMode(ECHO_PIN, INPUT); // Set the echo pin as input

    // Connect to WiFi
    WiFi.begin(ssid, password); // Start WiFi connection
    while (WiFi.status() != WL_CONNECTED) { // Wait until connected
        delay(1000); // Wait for 1 second
        Serial.println("Connecting to WiFi..."); // Print connecting message
    }
    Serial.println("Connected to WiFi"); // Print connected message
    
    //Solution to WiFi Connectivity Challenge
}

void loop() {
    // Read sensor data
    float humidity = dht.readHumidity(); // Read humidity from DHT sensor
    float temperature = dht.readTemperature(); // Read temperature from DHT sensor
    long distance = measureDistance(); // Measure distance using the ultrasonic sensor

    //Solution to Data Accuracy Challenge
   
    // Print sensor data to serial
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" *C\t");
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Check if WiFi is connected
    if (WiFi.status() == WL_CONNECTED) {
        WiFiClient client; // Create a WiFi client
        HTTPClient http; // Create an HTTP client

        // Begin the HTTP request
        http.begin(client, serverName); // Specify the URL
        http.addHeader("Content-Type", "application/x-www-form-urlencoded"); // Specify content type

        // Prepare the data to send
        String httpRequestData = "temperature=" + String(temperature) + "&humidity=" + String(humidity) + "&distance=" + String(distance);
        int httpResponseCode = http.POST(httpRequestData); // Send the POST request

        //Solution to Data Transmission and Error Handling Challenge

        // Print the response
        if (httpResponseCode > 0) {
            String response = http.getString(); // Get the response from the server
            Serial.println(httpResponseCode); // Print the HTTP response code
            Serial.println(response); // Print the response from the server
        } else {
            Serial.print("Error on sending POST: "); // Print error message
            Serial.println(http.errorToString(httpResponseCode)); // Print error description
        }

        http.end(); // End the HTTP request
    } else {
        Serial.println("Error in WiFi connection"); // Print error message if not connected to WiFi
    }

    delay(50000); // Delay for 50 seconds before the next reading to avoid overwhelming the ESP8266
    // Solution to Real-Time Data Updates Challenge
}
