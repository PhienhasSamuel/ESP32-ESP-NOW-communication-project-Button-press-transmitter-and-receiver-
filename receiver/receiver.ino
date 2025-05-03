#include <WiFi.h>
#include <esp_now.h>

uint8_t receivedButtonState = 0;

void OnDataRecv(const esp_now_recv_info_t *info, const uint8_t *data, int len) {
  if (len == sizeof(receivedButtonState)) {
    memcpy(&receivedButtonState, data, sizeof(receivedButtonState));
    Serial.print("Received button state: ");
    Serial.println(receivedButtonState);

    char macStr[18];
    snprintf(macStr, sizeof(macStr), "%02X:%02X:%02X:%02X:%02X:%02X",
             info->src_addr[0], info->src_addr[1], info->src_addr[2],
             info->src_addr[3], info->src_addr[4], info->src_addr[5]);
    Serial.print("From MAC: ");
    Serial.println(macStr);
  } else {
    Serial.println("Received unknown data size");
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting Wi-Fi and ESP-NOW receiver...");

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);
  Serial.println("ESP-NOW receiver ready.");
}

void loop() {
  // Receiver logic handled in callback
}
