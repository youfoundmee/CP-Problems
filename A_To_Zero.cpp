#include <iostream>
#include <vector>
using namespace std;

class Semaphore
{
private:
    int count;

public:
    Semaphore(int init = 1) : count(init) {}

    void wait()
    {
        while (count <= 0)
        {
        }
        count--;
    }

    void signal()
    {
        count++;
    }
};

class ReadersWriters
{
public:
    vector<int> data = {100};
    int read_count = 0;
    int write_waiting = 0;
    Semaphore mutex = Semaphore(1);
    Semaphore rw_mutex = Semaphore(1);
    Semaphore writer_queue = Semaphore(1);

    void reader(int id)
    {
        writer_queue.wait();
        mutex.wait();
        read_count++;
        if (read_count == 1)
        {
            rw_mutex.wait();
        }
        mutex.signal();
        writer_queue.signal();

        cout << "Reader " << id << " read data: " << data[0] << endl;

        mutex.wait();
        read_count--;
        if (read_count == 0)
        {
            rw_mutex.signal();
        }
        mutex.signal();
    }

    void writer(int id, int value)
    {
        mutex.wait();
        write_waiting++;
        mutex.signal();

        writer_queue.wait();
        rw_mutex.wait();

        mutex.wait();
        write_waiting--;
        mutex.signal();

        data[0] = value;
        cout << "Writer " << id << " wrote " << value << endl;

        rw_mutex.signal();
        writer_queue.signal();
    }
};

int main()
{
    ReadersWriters rw;
    vector<pair<char, int>> operations = {
        {'R', 2}, {'W', 10}, {'R', 3}, {'R', 5}, {'W', 20}, {'R', 6}, {'W', 35}, {'R', 8}, {'W', 50}, {'R', 10}, {'W', 75}, {'R', 12}};

    for (auto &op : operations)
    {
        if (op.first == 'R')
        {
            rw.reader(op.second);
        }
        else if (op.first == 'W')
        {
            rw.writer(op.second, op.second * 10);
        }
    }

    return 0;
}
