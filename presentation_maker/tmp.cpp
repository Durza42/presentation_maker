#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<std::string> get_file_text(std::string const& path)
{
    std::ifstream file { path };

    std::vector<std::string> ret;
    std::string line;
    while(std::getline(file, line))
        ret.push_back(line);

    return ret;
}

void remove_comments(std::vector<std::string>& text)
{
    std::string const comment_introcucer { "~~" };

    for(auto& line : text)
    {
        auto first_occur = std::search(
            line.begin(), line.end(),
            comment_introcucer.begin(), comment_introcucer.end()
        );
        line.replace(
            first_occur, line.end(),
            {}
        );
    }
}

int main()
{
    std::string path;
    std::cin >> path;

    std::vector<std::string> plain_text;
    plain_text = get_file_text(path);

    for(auto it : plain_text)
        std::cout << it << std::endl;

    remove_comments(plain_text);
}



