#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

class HashTable {
public:
    int* table;
    int size;


    HashTable(int s)
    {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1;
    }

    int hashFunction(int key)
    {
        return key % size;
    }




    void display() {
        for (int i = 0; i < size; i++)
        {
            cout << i << " --> " << table[i] << endl;
        }
    }

    // Destructor
    ~HashTable() {
        delete[] table;
        table = nullptr;
    }



    int getRandomNumber(int start, int end)
    {
        return rand() % (end - start + 1) + start;
    }


    int insert(int key)
    {
        int index = hashFunction(key);
        int numberofints = 0;
        if (this->table[index] == -1)
        {
            table[index] = key;
            numberofints++;
            cout << "count:" << numberofints<<endl;
            return numberofints;
            
        }
         
        int originalIndex = index;
        while (table[index] != -1) {
            index = (index + 1) % size;

            if (index == originalIndex) {
                cout << "Hash Table is Full!" << endl;
                return 0;
            }
            table[index] = key;
            return 0;
        }
    }



    int Experiment(int size)
    {
        int sum = 0;
        int elements = 0;
        int num = 0;
        for (int i = 0;i < size;i++)
        {
             num = getRandomNumber(1, 100);
        }
        elements = insert(num);
        sum +=num;
        int avg = sum / elements;
        cout << avg<<endl;
        return avg;
    }
};

int main()
{
    HashTable t(50);
    srand(static_cast<unsigned>(time(0))); // seed random generator
    const int numExperiments = 50;
    cout << "Table Size\tAverage Inserted\n";
    cout << "-----------\t----------------\n";
    // Run experiments for table sizes 10, 20, 30, ..., 100
    for (int S = 10; S <= 100; S += 10) {
        double totalInserted = 0.0;
        for (int i = 0; i < numExperiments; i++)
            totalInserted += t.Experiment(S);
        double averageInserted = totalInserted / numExperiments;
        cout << setw(5) << S << "\t\t" << fixed << setprecision(2)
            << averageInserted << endl;

    }
    return 0;
}