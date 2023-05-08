#pragma once
#include<iostream>
#include<fstream>
#include<chrono>
#include<iomanip>

namespace esp
{
	enum class LogLvl
	{
		DEBUG,
		RELEASE
	};

	enum class LogType
	{
		DEBUG,
		INFO,
		ERROR
	};

	class Log
	{
	private:

		static std::ofstream m_out;
		static LogLvl m_loglvl;
		LogType m_lp;

	public:

		explicit Log(LogType lp) : m_lp(lp)
		{
			std::cout << "\033[1;30m" << "Constructed" << "\033[0m" << std::endl;
		}

		static void SetLodLvl(LogLvl loglvl)
		{
			m_loglvl = loglvl;
		}

		static void SetLogPath(const std::string& path)
		{
			m_out.open(path);
		}

		static void Write(Log log, const std::string& msg)
		{

			static auto startt = std::chrono::steady_clock::now();


			if (m_loglvl == LogLvl::DEBUG)
			{
				auto endt = std::chrono::steady_clock::now();
				std::chrono::duration<double> elapsed_seconds = endt - startt;

				switch (log.m_lp)
				{
				case (LogType::INFO):
				{
					std::cerr << "\033[1;34m" << "[INFO]" << msg << " Duration: " << 1000 * elapsed_seconds.count() << " ms" << "\033[0m" << std::endl;
					m_out << "[INFO]" << msg << " [INFO] " << "Duration: " << 1000 * elapsed_seconds.count() << " ms" << std::endl;
					break;
				}
				case (LogType::DEBUG):
				{
					std::cerr << "\033[1;33m" << "[DEBUG]" << msg << " Duration: " << 1000 * elapsed_seconds.count() << " ms" << "\033[0m" << std::endl;
					m_out << "[DEBUG]" << msg << " [DEBUG] " << "Duration: " << 1000 * elapsed_seconds.count() << " ms" << std::endl;
					break;
				}
				case (LogType::ERROR):
				{
					std::cerr << "\033[1;31m" << "[ERROR]" << msg << " Duration: " << 1000 * elapsed_seconds.count() << " ms" << "\033[0m" << std::endl;
					m_out << "[ERROR]" << msg << " [ERROR] " << "Duration: " << 1000 * elapsed_seconds.count() << " ms" << std::endl;
					break;
				}
				}

			}

			//__________________________Запись в файл___________________________________________________
			auto endt = std::chrono::steady_clock::now();
			std::chrono::duration<double> elapsed_seconds = endt - startt;

			if (m_loglvl == LogLvl::RELEASE)
			{
				m_out << msg << "Duration: " << 1000 * elapsed_seconds.count() << " ms" << std::endl;
			}

			m_out.flush();  //вбрасывает всё что есть в буффере в файл
			//___________________________________________________________________________________________
		}

		~Log()
		{
			std::cout << "\033[1;30m" << "Destructed" << "\033[0m" << std::endl;
		}
	};
}