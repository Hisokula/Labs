#pragma once
#include<iostream>
#include<fstream>
#include<chrono>


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
			std::cout << "Constructed" << std::endl;
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

				switch (log.m_lp)                                                          //m_out не работает(???)
				{
					case (LogType::INFO):
					{
						std::cerr << "[INFO]" << msg << " Duration: " << 1000 * elapsed_seconds.count() << " ms" << std::endl;
						m_out << "[INFO]" << msg << std::endl;
						break;
					}
					case (LogType::DEBUG):
					{
						std::cerr << "[DEBUG]" << msg << " Duration: " << 1000 * elapsed_seconds.count() << " ms" << std::endl;
						m_out << "[DEBUG]" << msg << std::endl;
						break;
					}
					case (LogType::ERROR):
					{
						std::cerr << "[ERROR]" << msg << " Duration: " << 1000 * elapsed_seconds.count() << " ms" << std::endl;
						m_out << "[ERROR]" << msg << std::endl;
						break;
					}
				}
				
			}

			//__________________________Запись в файл___________________________________________________
			auto endt = std::chrono::steady_clock::now();
			std::chrono::duration<double> elapsed_seconds = endt - startt;
			
			m_out << msg << std::endl;
			m_out << "Duration: " << 1000*elapsed_seconds.count() << " ms" << std::endl;

			m_out.flush();  //вбрасывает всё что есть в буффере в файл
			//___________________________________________________________________________________________
		}

		~Log()
		{
			std::cout << "Destructed" << std::endl;
		}
	};
}