//
// Created by leebais on 2020/9/10.
//

#include <iostream>
#include <unistd.h>
#include "Book.h"

Book::Book()=default;

Book::~Book() = default;

void sbook::writePage(sbook& dbook,const char *m) {
    if(messageCount_<5
            &&mu[locateForWriter_].try_lock()){
        strcpy(book[locateForWriter_],m);
        messageCount_++;
        locateForWriter_=(locateForWriter_+1)%5;
        mu[locateForWriter_-1].unlock();
    }
}

void sbook::readPage(sbook& dbook) {
    if(messageCount_>0
            &&mu[locateForReader_].try_lock()){
        std::cout << book[locateForReader_];
        messageCount_--;
        locateForReader_=(locateForReader_+1)%5;
        mu[locateForReader_-1].unlock();
    }
}

sbook::sbook() {
    messageCount_=0;
    locateForWriter_=0;
    locateForReader_=0;

}

void sbook::strcpy(char *dest, const char *src) {
    {
        //TODO:修正字符串长度
        for(int i=0;src[i]!='\0';i++){
            dest[i] = src[i];
        }
    }
}

void Book::RreadPage(sbook &book) {
    book.readPage(book);
}

void Book::WritePage(sbook &book, const char *m) {
    book.writePage(book,m);
}
