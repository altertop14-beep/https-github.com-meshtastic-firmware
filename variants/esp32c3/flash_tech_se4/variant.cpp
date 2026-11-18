#include <Arduino.h>
#include "variant.h"

void initVariant() {
    pinMode(UNUSED_LORA_CS, OUTPUT);
    digitalWrite(UNUSED_LORA_CS, HIGH);

    pinMode(UNUSED_LORA_RST, OUTPUT);
    digitalWrite(UNUSED_LORA_RST, HIGH);
}
