#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
public:
    // TODO: Optimize this thing.
    Matrix operator+(Matrix& other)
    {
        Matrix tempMat;
        for (int i = 0; i < this->data.size(); i++)
        {
            tempMat.data.emplace_back();
            for (int j = 0; j < this->data.back().size(); j++)
            {
                tempMat.data.back().push_back(this->data[i][j] + other.data[i][j]);
            }
        }
        return tempMat;
    }

    void print()
    {
        for (int i = 0; i < this->data.back().size(); i++)
        {
            for (int j = 0; j < this->data.back().size(); j++)
            {
                cout << this->data.at(i).at(j) << '\t';
            }
            cout << '\n';
        }
    }

    vector<vector<int>>& getData()
    {
        return data;
    }

private:
    vector<vector<int>> data;
};

int main()
{
    Matrix a, b;

    // Init first row of both matrixes
    a.getData().emplace_back();
    b.getData().emplace_back();
    a.getData().back().push_back(0);
    b.getData().back().push_back(1);
    a.getData().back().push_back(2);
    b.getData().back().push_back(3);

    // Init second row of both matrixes
    a.getData().emplace_back();
    b.getData().emplace_back();
    a.getData().back().push_back(4);
    b.getData().back().push_back(5);
    a.getData().back().push_back(6);
    b.getData().back().push_back(7);

    // Sum matrixes
    a = a + b;

    // Print Matrix
    a.print();

    return 0;
}
