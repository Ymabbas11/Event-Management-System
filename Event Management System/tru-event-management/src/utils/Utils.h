#pragma once
#include <string>
#include "Event.h"

std::string toUpper(std::string str);
std::string toProperCase(std::string str);
void clearInputBuffer();
void printEventDetails(const Event* event);
std::string getUserInput(const std::string& prompt, bool makeUpper = false, bool properCase = false);
bool isValidDate(const std::string& date);
bool isValidEmail(const std::string& email);
int getIntInput(const std::string& prompt);
bool isValidTime(const std::string& time);
