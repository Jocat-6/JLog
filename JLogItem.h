#ifndef JLOGITEM_H
#define JLOGITEM_H

#include "JLogCfg.h"
#include <iostream>
#include <source_location>

class JLogItem
{
private:
	JLogLevel _level;
	JLogMesType _mesType;
	char _datetime[20];
	std::string _file;
	int _line;
	std::string _func;
	std::string _message;

	std::string getLog() const;
public:
	JLogItem(JLogLevel, std::string, JLogMesType type = JLogMesType::Text, const std::source_location& location = std::source_location::current());
	//~JLogItem();

	friend std::ostream& operator << (std::ostream& os, const JLogItem& log);
};

#endif // JLOGITEM_H