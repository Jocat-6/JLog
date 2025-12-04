#include "JLogItem.h"

#include <ctime>
#include <sstream>

JLogItem::JLogItem(JLogLevel level, std::string message, JLogMesType type, const std::source_location& location)
	:_level(level), _mesType(type), _message(message)
{
	this->_file = const_cast<char*>(location.file_name());
	this->_line = static_cast<int>(location.line());
	this->_func = const_cast<char*>(location.function_name());

	time_t now = time(0);
	tm* ltm = localtime(&now);

	strftime(this->_datetime, sizeof(this->_datetime), "%Y-%m-%d %H:%M:%S", ltm);
}

std::string JLogItem::getLog() const
{
	std::ostringstream oss;
	oss << "[" << JLogLevelToStr(this->_level) << "]"
		<< "[" << this->_datetime << "]"
		<< "[" << this->_file << ":" << this->_line << " " << this->_func << "]"
		<< "[" << JLogMesTypeToStr(this->_mesType) << "] "
		<< this->_message << std::endl;
	return oss.str();
}

std::ostream& operator << (std::ostream& os, const JLogItem& log)
{
	os << log.getLog();
	return os;
}