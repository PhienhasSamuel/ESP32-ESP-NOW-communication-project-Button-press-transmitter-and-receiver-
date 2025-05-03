#include <WiFi.h>
#include <esp_now.h>

uint8_t receiverMac[] = {0xF4, 0x65, 0x0B, 0x4A, 0x88, 0xC0};  // Replace with your receiver MAC

#define BUTTON_PIN 0
uint8_t buttonState = 0;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("Send Status: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Fail");
}

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    return;
  }

  esp_now_register_send_cb(OnDataSent);

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, receiverMac, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    buttonState = 1;
    esp_now_send(receiverMac, &buttonState, sizeof(buttonState));
    Serial.println("Button Press Detected, Message Sent");
    delay(500);  // debounce
  }
}
