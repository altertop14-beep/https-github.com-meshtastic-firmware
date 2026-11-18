#pragma once

// =========================================================================
// Flash Tech SE4 Dual Band Xross Gemini (ESP32-C3 + Dual LR1121)
// =========================================================================

// Вибір активного радіомодуля (за замовчуванням 868 / 915 МГц).
// Розкоментуй рядок нижче для збірки під чіп 2.4 ГГц:
// #define SE4_USE_24GHZ_CHIP

// Вимикаємо периферію, яка може зайняти GPIO 0-10
#define HAS_SCREEN 0
#define HAS_GPS 0
#define HAS_WIRE 0

// Блокуємо стандартний I2C, щоб не чіпати піни SPI/LR1121
#define I2C_SDA -1
#define I2C_SCL -1

// Блокуємо дефолтну кнопку (у ESP32-C3 вона часто висить на GPIO 9, де у нас IRQ2)
#define BUTTON_PIN -1

// Спільна шина SPI для обох трансиверів LR1121
#define LORA_SCK 6
#define LORA_MISO 5
#define LORA_MOSI 4

#define USE_LR1121

#ifndef SE4_USE_24GHZ_CHIP
  // --- АКТИВНИЙ: Радіомодуль #1 (Sub-GHz: 868 / 915 МГц) ---
  #define LORA_CS 7
  #define LORA_RESET 2
  #define LORA_DIO1 1       // IRQ1
  #define LORA_DIO2 3       // BUSY1

  // --- НЕАКТИВНИЙ: Радіомодуль #2 (2.4 ГГц) — паркуємо в HIGH ---
  #define UNUSED_LORA_CS 10
  #define UNUSED_LORA_RST 0
#else
  // --- АКТИВНИЙ: Радіомодуль #2 (2.4 ГГц) ---
  #define LORA_CS 10
  #define LORA_RESET 0
  #define LORA_DIO1 9       // IRQ2
  #define LORA_DIO2 8       // BUSY2

  // --- НЕАКТИВНИЙ: Радіомодуль #1 (Sub-GHz) — паркуємо в HIGH ---
  #define UNUSED_LORA_CS 7
  #define UNUSED_LORA_RST 2
#endif

// Внутрішні макроси драйвера LR1121Interface у Meshtastic
#define LR1121_IRQ LORA_DIO1
#define LR1121_BUSY LORA_DIO2
#define LR1121_NRESET LORA_RESET

// Налаштування кварцового генератора TCXO BN32.0 (32 МГц, живлення 1.8V від DIO3)
#define LR1121_DIO3_TCXO_VOLTAGE 1.8
#define TCXO_OPTIONAL

// Вимикаємо вимірювання батареї через АЦП (щоб не було наводок)
#undef BATTERY_PIN
