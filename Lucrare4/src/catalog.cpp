#include <lucrare4/dealership.hpp>

#include <string>
#include <vector>

static int countModels()
{
    std::vector<std::string> models{"Logan", "Duster", "Spring"};
    return static_cast<int>(models.size());
}

int modelCount = countModels();

int catalogModelCount()
{
    static int count = countModels();
    return count;
}
