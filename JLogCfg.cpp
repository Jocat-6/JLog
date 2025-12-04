#include "JLogCfg.h"

std::string JLogLevelToStr(JLogLevel level)
{
	switch (level)
	{
	case JLogLevel::Info:
		return "Info";
	case JLogLevel::Debug:
		return "Debug";
	case JLogLevel::Warning:
		return "Warning";
	case JLogLevel::Error:
		return "Error";
	default:
		return "Unknown";
	}
}

std::string JLogMesTypeToStr(JLogMesType type)
{
	switch (type)
	{
	case JLogMesType::Text:
		return "Text";
	case JLogMesType::Bin:
		return "Bin";
	case JLogMesType::Hex:
		return "Hex";
	default:
		return "Unknown";
	}
}