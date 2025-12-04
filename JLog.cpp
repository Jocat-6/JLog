// JLog.cpp: 定义应用程序的入口点。
//

#include "JLog.h"

JLog::JLog()
{
	
}

void JLog::Log(std::string message, JLogLevel level, JLogMesType type, const std::source_location& location)
{
	JLogItem log(level, message, type, location);
	this->logs.push(log);

	if (this->logs.size() >= logsCacheNum)
	{
		this->writeLogToFile();
	}
}

void JLog::writeLogToFile()
{

}

void JLog::InfoLog(std::string message, JLogMesType type, const std::source_location& location)
{
	this->Log(message, JLogLevel::Info, type, location);
}

void JLog::DebugLog(std::string message, JLogMesType type, const std::source_location& location)
{
	this->Log(message, JLogLevel::Debug, type, location);
}

void JLog::WarningLog(std::string message, JLogMesType type, const std::source_location& location)
{
	this->Log(message, JLogLevel::Warning, type, location);
}

void JLog::ErrorLog(std::string message, JLogMesType type, const std::source_location& location)
{
	this->Log(message, JLogLevel::Error, type, location);
}

int main()
{
	JLog LOG;
	LOG.InfoLog("This is an info log message.");
	std::cout << LOG.getFrontLog() << std::endl;
	return 0;
}
