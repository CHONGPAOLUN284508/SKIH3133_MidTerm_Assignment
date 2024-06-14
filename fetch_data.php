<?php
$servername = "localhost";
$username = "root"; // default XAMPP MySQL user
$password = ""; // default XAMPP MySQL password is empty
$dbname = "assignment3"; // replace with your database name

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die(json_encode(["error" => "Connection failed: " . $conn->connect_error]));
}

$sql = "SELECT timestamp, temperature, humidity, distance FROM readings ORDER BY timestamp DESC";
$result = $conn->query($sql);

// Check if query was successful
if ($result === false) {
    die(json_encode(["error" => "Query failed: " . $conn->error]));
}

$sensorData = array();
while ($row = $result->fetch_assoc()) {
    $sensorData[] = $row;
}

// Output data as JSON
header('Content-Type: application/json');
echo json_encode($sensorData);

$conn->close();
?>