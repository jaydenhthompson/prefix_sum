#include <spin_barrier.h>

void spin_barrier::wait_for_all()
{
    mtx.lock();
    auto wait = go.load();
    if (counter + 1 >= n_threads)
    {
        counter = 0;
        go = !go;
        mtx.unlock();
    }
    else
    {
        counter++;
        mtx.unlock();

        while(wait == go){}
    }
}