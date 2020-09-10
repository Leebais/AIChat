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
    void strcpy(char* dest,const char* src){
        //TODO:修正字符串长度
        for(int i=0;src[i]!='\0';i++){
            dest[i] = src[i];
        }
    }
}sbook;

class Book {
    private:
    sbook book1;
    //sbook book2;
    public:
    Book();
    ~Book();
    void WritePage(Book& book,
                   const char* m);
    void RreadPage(Book& book);
};


#endif //AICHAT_BOOK_H
