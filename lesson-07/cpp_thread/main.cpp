#include <QCoreApplication>

#include <iostream>
#include <unistd.h>
#include <thread>
#include <QTimer>

void  loop(int a, int b)
{
    sleep(3);

    for (int i = a; i < b; i++)
    {
        std::cout << "start thread 1 : " << i << std::endl;
    }
}

void  quit()
{
    QCoreApplication::instance()->quit();
}

int  main(int argc, char *argv[])
{
    QCoreApplication  a(argc, argv);

    std::thread  t(loop, 0, 3);

    std::thread  t2(loop, 5, 8);

    QTimer::singleShot(1000, &quit);
    std::cout << "Hello " << std::endl;

    int  ret = a.exec();

    std::cout << "quit qt loop " << std::endl;

    t.join();
    t2.join();
    std::cout << "Thread joind " << std::endl;

    return ret;
}
