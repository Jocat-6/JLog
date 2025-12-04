#ifndef JLOGCFG_H
#define JLOGCFG_H
#include <string>

#define logsCacheNum 10

enum class JLogLevel
{
	Info,
	Debug,
	Warning,
	Error
};

enum class JLogMesType
{
	Text,
	Bin,
	Hex
};

std::string JLogLevelToStr(JLogLevel level);
std::string JLogMesTypeToStr(JLogMesType type);

#endif // JLOGCFG_H