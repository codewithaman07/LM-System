#include"book.h"
#include<bits/stdc++.h>
using namespace std;

Book::Book(int id, string title, string author){
    this->id = id;
    this->title = title;
    this->author = author;
    this->isAvailable = true; 
}

void Book::displayBook(){
    cout<<"ID: " << id << endl;
    cout<<"Title: " << title << endl;
    cout<<"Author: " << author << endl;
    cout<<"Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
}
int Book::getId(){
    return id;
}

string Book::getTitle(){
    return title;
}

bool Book::getAvailability(){
    return isAvailable;
}

void Book::setAvailability(bool status){
    isAvailable = status;
}