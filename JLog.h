#ifndef JLOG_H
#define JLOG_H

#include "JLogItem.h"
#include <queue>

class JLog {
private:
	std::queue<JLogItem> logs;
	int curIndex = 0;

	void Log(std::string, JLogLevel, JLogMesType, const std::source_location&);
	void writeLogToFile();
public:
	JLog();

	void InfoLog(std::string, JLogMesType type = JLogMesType::Text, const std::source_location& location = std::source_location::current());
	void DebugLog(std::string, JLogMesType type = JLogMesType::Text, const std::source_location& location = std::source_location::current());
	void WarningLog(std::string, JLogMesType type = JLogMesType::Text, const std::source_location& location = std::source_location::current());
	void ErrorLog(std::string, JLogMesType type = JLogMesType::Text, const std::source_location& location = std::source_location::current());

	JLogItem getFrontLog() const { return this->logs.front(); }
};

#endif