// хеш-таблица "с наложением"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>


class HashElement
{
private:

	int m_key;
	std::string m_data;

public:

	HashElement(int key, std::string data) : m_key(key), m_data(data) {};

	std::string getData() { return m_data; }

	int getKey() { return m_key; }
};


class HashTable
{
private:

	std::vector<HashElement> m_hash_table;
	unsigned int start_size = 12;

public:

	HashTable()
	{
		for (int i = 0; i < start_size; ++i)
		{
			m_hash_table.push_back(HashElement(i, ""));
		}
	};

	int GetStartSize() { return start_size; }

	int HashFunc(const std::string& str)
	{
		int hash = 0;

		for (int i = 0; i < str.size(); i++)
		{
			hash += (str[i] - '0');
		}
		return (hash / 23);
	}

	int GetSize() { return m_hash_table.size(); }

	std::string GetData(const std::string& str)
	{
		int key = HashFunc(str);

		for (int i = key; i < m_hash_table.size(); ++i)
		{
			if (m_hash_table[i].getData() == str)
			{
				return m_hash_table[i].getData();
			}
		}

		return "No such data";
	}

	void HashTableInsert(const std::string data)
	{
		int key = HashFunc(data);

		if (key >= m_hash_table.size())
		{
			m_hash_table.push_back(HashElement(key, data));
		}
		else
		{
			int i = key;
			bool flag = false;

			while (m_hash_table[i].getData() != "") { i++; }

			if (m_hash_table.size() < i)
			{
				m_hash_table.push_back(HashElement(key, data));
			}
			else
			{
				m_hash_table[i] = HashElement(key, data);
			}
		}
	}

	HashElement operator[] (int key) { return m_hash_table[key]; }

};

int main()
{
	HashTable table;
	std::string line;
	int n = 1;

	std::ifstream in("in.txt");
	std::ofstream out;

	if (in.is_open())
	{
		while (getline(in, line))
		{
			table.HashTableInsert(line);
			std::cout << n << " - " << table.GetData(line) << std::endl;
			n++;
		}
	}
	in.close();

	out.open("out.txt", std::ios::out | std::ios::trunc);
	out << "Key | Index | Element\n";
	int i = 0;
	for (i; i < table.GetSize() - 1; i++)
	{
		out << i << "----------" << table[i].getKey() << "----------" << table[i].getData() << "\n";
	}

	out << i << "----------" << table[i].getKey() << "----------" << table[i].getData();
	out.close();
}