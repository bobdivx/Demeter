#ifndef DEMETER_H
#define DEMETER_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "config.h"
#ifdef DEBUG_MODE

#define printk(string) Serial.print(string)
#define printkn(string) Serial.println(string)
#else
#define printk(string)
#define printkn(string)
#endif

#endif
