
#include "Lexique.hpp"
#include "utilitaire.hpp"
#include <sstream>
#include <fstream>

Lexique::Lexique(std::string path) {
    content = " ";

    if(!util::readFileIntoString(path, content)) {
        std::cerr << "Error while reading file"<<std::endl;
    }
    util::remove_punctuation(content);
    std::cout<<"remove"<<std::endl;
    util::to_lower(content);
    std::cout<<"lower"<<std::endl;

    list = counter(content);
    std::cout<<"count"<<std::endl;

}
Lexique::t_vector Lexique::counter(std::string content) {
    std::unordered_map<std::string,int> counts;
    std::istringstream iss(content);
    std::string word;

    while (iss >> word) {
        ++counts[word];
    }

    t_vector result;
    result.reserve(counts.size());
    for (auto &kv : counts) {
        result.emplace_back(kv.first, kv.second);
    }
    return result;
}

const Lexique::t_vector Lexique::getList() {
    return this->list;
}

std::string Lexique::toString(Lexique::t_vector list){
    std::string slexic;
    for (size_t i = 0; i < list.size(); i++) {
        slexic += list.at(i).first + ", occure " + std::to_string(list.at(i).second) + " fois \n";
    }
    return slexic;
}

bool Lexique::findEntry(Lexique::t_vector list, std::string word, Lexique::t_pair& i_p) {
    for (size_t i = 0; i < list.size(); i++) {
        if (list.at(i).first == word) {
            i_p = {list.at(i).first, list.at(i).second};
            return true;
        }
    }
    return false;
}

void Lexique::writeFile() {
    std::ofstream newFile("output.txt");
    newFile << Lexique::toString(this->getList());
    newFile.close();
}

    
