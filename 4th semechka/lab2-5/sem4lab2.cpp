// 2. Поиск в ширину

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <string>


class Graph
{
private:

    int vertex = 0;
    std::vector <std::vector <int>> graph;
    std::vector <int> weight;

public:

    Graph(int v) : vertex(v)
    {
        for (int x = 0; x < vertex; x++)
        {
            std::vector <int> temp;

            graph.push_back(temp);
            weight.push_back(-36);
        }

    };

    void connect_undir(int start, int fin)
    {
        if ((start < vertex) and (fin < vertex))
        {
            graph[start].push_back(fin);
        }
    }

    void set_weight(int num, int w)
    {
        weight[num] = w;
    }

    std::vector <std::vector <int>> get_graph()
    {
        return graph;
    }

    int get_verrex() 
    { 
        return vertex; 
    }

    void print_graph_paths()
    {
        for (int x = 0; x < vertex; x++)
        {
            std::cout << x << " :  ";

            for (int y = 0; y < graph[x].size(); y++)
            {
                std::cout << graph[x][y] << "  ";
            }

            std::cout << std::endl;
        }
    }

    void print_graph_weight()
    {
        for (int x = 0; x < vertex; x++)
        {
            std::cout << x << " :  " << weight[x] << std::endl;

        }
    }
};

std::vector <int> Rebuild_Path(std::vector<int> from, int fin)
{
    std::vector<int> path;
    
    for (int v = fin; v != -1; v = from[v]) 
    { 
        path.push_back(v); 
    }
    
    std::reverse(path.begin(), path.end());
    
    if (path.size() == 1) 
    { 
        std::cout << "the path doesn't exist."; 
        exit(3); 
    }

    return path;
};

std::vector<int> ShortPath(std::vector <std::vector <int>> gr, int start)
{
    std::vector<int> vis(gr.size(), 0);
    std::vector<int> dist(gr.size(), -36);
    std::vector<int> from(gr.size(), -1);

    std::queue<int> qq;

    vis[start] = 1;
    dist[start] = 0;

    qq.push(start);

    while (!qq.empty())
    {
        int curr = qq.front();
        qq.pop();

        for (int adj : gr[curr])
        {
            if (vis[adj] != 1)
            {
                vis[adj] = 1;
                dist[adj] = dist[curr] + 1;
                from[adj] = curr;

                qq.push(adj);
            }
        }
    }

    return from;
}

std::vector <int> DataCatcher(std::string exmpl, std::vector <int> ex_mas, int leng)
{
    std::string tmp = "";
    int counter = 0;
    bool len_fl = false;

    for (int x = 0; x <= exmpl.length(); x++)
    {
        bool flag = (exmpl[x] != ' ');

        if ((x == exmpl.length()) and (exmpl[x] == '\0'))
        {
            bool len_fl = true;
            if (tmp != "") 
            { 
                ex_mas[counter] = std::stoi(tmp); 
                leng++; 
            }
        }

        if ((x == exmpl.length()) and (exmpl[x] != '\0'))
        {
            tmp += exmpl[x];
            ex_mas[counter] = std::stoi(tmp);
            leng++;
            bool len_fl = true;
        }

        if (flag == true)
        {
            tmp += exmpl[x];
        }

        else if (flag == false)
        {
            if (tmp != "")
            {
                ex_mas[counter] = std::stoi(tmp);
                leng++;
                tmp = "";
                counter += 1;
            }

            else if (len_fl != true)
            {
                tmp += exmpl[x];
                ex_mas[counter] = std::stoi(tmp);
                leng++;
                tmp = "";
                counter += 1;
            }

        }
    }

    return ex_mas;
}



int main()
{
    std::ifstream in;

    in.open("input.txt");

    std::vector <std::string> lines;
    std::string str = "";
    std::string num_of_ver_str = "";

    std::getline(in, num_of_ver_str); // для упрощения чтения графа первая строка -- количество вершин
    
    int num_of_ver_int = std::stoi(num_of_ver_str);

    while (std::getline(in, str)) 
    { 
        lines.push_back(str); 
        std::string str = ""; 
    }
    in.close();


    Graph wh(num_of_ver_int);

    for (int x = 0; x < num_of_ver_int; x++)
    {
        std::vector <int> temp;
        
        for (int i = 0; i < num_of_ver_int; i++) 
        { 
            temp.push_back(-1); 
        }
        
        temp = DataCatcher(lines[x], temp, num_of_ver_int);
        
        for (int i = 0; i < temp.size(); i++) 
        { 
            if (temp[i] == 1) wh.connect_undir(x, i); 
        }


    }

    wh.print_graph_paths();

    std::cout << std::endl;
    std::cout << std::endl;

    int from = 0;
    int here = 0;

    std::cout << "find the shortest path from " << std::endl;
    std::cin >> from;
    std::cout << " where " << std::endl;
    std::cin >> here;


    std::vector<int> answ = Rebuild_Path(ShortPath(wh.get_graph(), from), here);
    for (int i : answ)
    {
        std::cout << i << " ";
    }

}