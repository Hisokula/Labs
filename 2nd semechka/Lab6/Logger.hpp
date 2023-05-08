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
		INFO
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

				switch (log.m_lp)
				{
					case LogType::INFO:
						std::cerr << "[INFO]" << msg << " Duration: " << 1000 * elapsed_seconds.count() << " ms" << std::endl;
					case LogType::DEBUG:
						std::cerr << "[DEBUG]" << msg << " Duration: " << 1000 * elapsed_seconds.count() << " ms" << std::endl;
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