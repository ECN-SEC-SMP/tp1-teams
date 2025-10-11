#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>

class Lexique {

    private:
        using t_pair = std::pair<std::string, int>;
        using t_vector = std::vector<std::pair<std::string, int>>;

        std::string content;
        std::string name;
        t_pair entry;
        t_vector list;
        
    public:

        Lexique() {};
        Lexique(std::string path); //Pre-processing du lexique

        const t_vector getList();

        t_vector counter(std::string file);
        static std::string toString(t_vector i_list);

        void writeFile();

        bool findEntry(Lexique::t_vector list, std::string word, Lexique::t_pair& i_p);
};
