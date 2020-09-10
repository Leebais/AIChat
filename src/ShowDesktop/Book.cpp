//
// Created by leebais on 2020/9/10.
//

#include <iostream>
#include <unistd.h>
#include "Book.h"

Book::Book() {
    //book1.pointerForWriter_=book1.book[0];
    //book1.pointerForReader_=book1.book[0];
    book1.messageCount_=0;
    book1.locateForWriter_=0;
    book1.locateForReader_=0;
};

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

void Book::RreadPage(Book &book) {
    book.book1.readPage(book1);
}

void Book::WritePage(Book &book, const char *m) {
    book.book1.writePage(book1,m);
}
