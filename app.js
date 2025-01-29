
        // Replace with your ESP32 IP address
        const esp32Ip = 'http://192.168.10.114'; // Update this with your ESP32's IP address

        // Function to send an HTTP request to the ESP32 to control lights
        function toggleLight(lightNumber) {
            var isOn = document.getElementById("light" + lightNumber).checked;
            var url = `${esp32Ip}/light${lightNumber}/${isOn ? 'on' : 'off'}`;
            
            fetch(url)
                .then(response => {
                    if (!response.ok) {
                        throw new Error('Network response was not ok');
                    }
                    return response.text();
                })
                .then(data => {
                    console.log(data); // Log the response from the ESP32
                    alert(`Light ${lightNumber} is now ${isOn ? 'ON' : 'OFF'}`); // Optional: Alert the user
                })
                .catch(error => {
                    console.error('Error:', error);
                    alert('Error: ' + error.message); // Optional: Alert the user about the error
                });
        }
