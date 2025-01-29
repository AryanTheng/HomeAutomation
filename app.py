from flask import Flask, render_template
import requests

app = Flask(__name__)

# ESP32 IP address (replace with your actual ESP32 IP)
ESP32_IP = "http://192.168.10.114"  # Replace with your ESP32 IP

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/light1/on")
def light1_on():
    requests.get(f"{ESP32_IP}/light1/on")  # Sends request to turn on light 1
    return "Light 1 ON"

@app.route("/light1/off")
def light1_off():
    requests.get(f"{ESP32_IP}/light1/off")  # Sends request to turn off light 1
    return "Light 1 OFF"

@app.route("/light2/on")
def light2_on():
    requests.get(f"{ESP32_IP}/light2/on")
    return "Light 2 ON"

@app.route("/light2/off")
def light2_off():
    requests.get(f"{ESP32_IP}/light2/off")
    return "Light 2 OFF"

@app.route("/light3/on")
def light3_on():
    requests.get(f"{ESP32_IP}/light3/on")
    return "Light 3 ON"

@app.route("/light3/off")
def light3_off():
    requests.get(f"{ESP32_IP}/light3/off")
    return "Light 3 OFF"

@app.route("/light4/on")
def light4_on():
    requests.get(f"{ESP32_IP}/light4/on")
    return "Light 4 ON"

@app.route("/light4/off")
def light4_off():
    requests.get(f"{ESP32_IP}/light4/off")
    return "Light 4 OFF"

if __name__ == "__main__":
    app.run(debug=True)
