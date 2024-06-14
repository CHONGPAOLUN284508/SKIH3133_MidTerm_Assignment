<?php
$servername = "localhost";
$username = "root"; // default XAMPP MySQL user
$password = ""; // default XAMPP MySQL password is empty
$dbname = "assignment3"; // replace with your database name

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error); // Die if connection fails
}

// Get sensor data from POST request
$temperature = $_POST['temperature'];
$humidity = $_POST['humidity'];
$distance = $_POST['distance'];

// Prepare and bind
$stmt = $conn->prepare("INSERT INTO readings (temperature, humidity, distance) VALUES (?, ?, ?)");
$stmt->bind_param("ddi", $temperature, $humidity, $distance); // Bind parameters

// Execute statement
if ($stmt->execute()) {
    echo "New record created successfully"; // Success message
} else {
    echo "Error: " . $stmt->error; // Error message
}

$stmt->close(); // Close statement
$conn->close(); // Close connection

// **Solution to Data Transmission and Error Handling Challenge:**
// This PHP script ensures that data received from the ESP8266 is correctly inserted into the MySQL database.
// Proper error handling is implemented to provide feedback in case of a failure during data insertion.
?>