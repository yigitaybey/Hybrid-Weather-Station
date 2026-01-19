#  Hybrid Electronics: Weather Station Project - Dev Log #1

**Date:** January 19, 2026
**Phase:** Proof of Concept (POC)
**Developer:** Sado (Hybrid Electronics)

---

##  Hardware Architecture & Strategic Decisions

### **MCU Selection: The Pivot to Arduino Nano**
Initially, I planned to utilize the ESP8266 (NodeMCU). However, I made a strategic decision to switch to the **Arduino Nano**. 
* **Reasoning:** The upcoming phases of the project require multiple analog inputs for wind and rain sensors.
* **Scalability:** The Nano’s **8-pin ADC (Analog-to-Digital Converter)** capacity offers much better scalability for this specific system compared to the ESP8266's single analog pin.

### **Data Acquisition**
* **LDR:** Successfully quantified ambient light intensity within a `0-1023` digital range for luminance tracking.
* **DHT22:** Analyzed the sensor's latency and saturation limits. I optimized the polling interval to **2 seconds** to ensure data stability and allow for proper sensor recovery time.

---

##  7-Pin SPI OLED Implementation

The main technical hurdle was configuring the **0.96" SPI OLED** display due to non-standard labeling on the module.

* **Pin Mapping:** Decoded non-standard labels (`SX`, `SDA`, `F`) to their standard functions: **SCK (Clock)**, **MOSI (Data)**, and **Reset**.
* **Communication Protocol:** To resolve synchronization issues with Hardware SPI, I implemented **Software SPI** via the `Adafruit_SSD1306` library. This allowed for manual pin definition and a successful, stable initialization.

---

##  Debugging & Observations

* **Initialization Issues:** Identified that the **Reset (RST/F)** pin must be correctly pulsed during setup; otherwise, the OLED fails to initialize and remains in a "black screen" state.
* **Memory Optimization:** Observed **SRAM constraints** on the Arduino Nano when utilizing heavy graphics libraries. Future code iterations will focus on memory management to leave room for additional sensors.

---

## Future Roadmap & Scalability (The "Hybrid" Vision)

The Hybrid Electronics project is designed to be a fully autonomous environmental monitoring hub. The platform will be expanded with the following modules:

* [ ] **RTC (Real Time Clock):** High-precision time-stamping for data logs.
* [ ] **Data Logging:** SD Card module integration for `.csv` format long-term storage.
* [ ] **Energy Harvesting:** Solar panel integration with Li-ion battery management for 24/7 autonomy.
* [ ] **Aerodynamics:** Anemometer (Wind Speed) and Wind Vane (Direction) sensors.
* [ ] **Precipitation:** Rain Gauge for real-time rainfall tracking.
* [ ] **Audible Alerts:** Active buzzer for extreme weather notifications.

---

##  Next Sprint
* **RTC Integration:** Syncing real-time data with telemetry.
* **SD Card Setup:** Preparing the file system for offline data logging.
