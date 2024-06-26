// DateTimeUtils.h

#ifndef DATE_TIME_UTILS_H
#define DATE_TIME_UTILS_H

#include <string>
#include <chrono>

// Function prototype for parsing date and time strings into std::chrono::system_clock::time_point
std::chrono::system_clock::time_point parseDateTime(const std::string& timeStr, const std::string& dateStr);

#endif // DATE_TIME_UTILS_H
