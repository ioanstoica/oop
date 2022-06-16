#include <vector>
#include <string>
#include <fstream>
#include <sstream>

std::vector<std::vector<std::string> > parseCSV(std::string src)
{
    std::ifstream data(src);
    std::string line;
    std::vector<std::vector<std::string> > parsedCsv;
    while(std::getline(data,line))
    {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<std::string> parsedRow;
        while(std::getline(lineStream,cell,','))
            parsedRow.push_back(cell);
        parsedCsv.push_back(parsedRow);
    }
    return parsedCsv;

}
