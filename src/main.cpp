#include <iostream>
#include <thread>
#include "ShowDesktop/Book.h"

using namespace std;
void Reader(sbook* book)
{
    Book::RreadPage(*book);
}
int main(int argc, char **argv)
{
    sbook book;
    sbook* pointer_book=&book;
    Book::WritePage(book,"Hello");
    thread t1(Reader,&book);
    t1.join();
    return 0;
}