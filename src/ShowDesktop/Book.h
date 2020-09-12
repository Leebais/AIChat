//
// Created by leebais on 2020/9/10.
//

#ifndef AICHAT_BOOK_H
#define AICHAT_BOOK_H
#include <mutex>

typedef struct sbook{
    std::mutex mu[5]{};
    char book[5][40]={0};
    int messageCount_ ;
    //char* pointerForWriter_;
    //char* pointerForReader_;
    int locateForReader_;
    int locateForWriter_;
    void readPage(sbook& book);
    void writePage(sbook& book,
                   const char* m);
    static void strcpy(char* dest,const char* src);
public:
    sbook();
}sbook;

class Book {
public:
    Book();
    ~Book();
    static void WritePage(sbook & book,
                   const char* m);
    static void RreadPage(sbook& book);
};


#endif //AICHAT_BOOK_H
