#pragma once

#include <tesla.hpp>
#include <switch.h>
#include <stdio.h>
#include <fancontrol.h>

#define SysFanControlID 0x00FF0000B378D640
#define SysFanControlB2FPath "/atmosphere/contents/00FF0000B378D640/flags/boot2.flag"

u64 IsRunning();
void CreateB2F();
void RemoveB2F();