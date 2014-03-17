// error:	OK
// langId:	1
// langName:	C++ 4.8.1
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-10-12 09:01:27
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
//
//  main.cpp
//  AccountsReceivable
//
//  Created by Moshe Berman on 10/11/12.
//  Copyright (c) 2012 Moshe Berman. All rights reserved.
//
//  This is the first assignment for Professor Lowenthal's Data Structures class.
//

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "Record.h"
#include "Customer.h"

using namespace std;

//
//  Function prototypes
//

bool openInputStream(ifstream &, string);
bool openOutputStream(ofstream &, string);
void readNCharactersFromStreamIntoArray(ifstream &, int, char*);

int main() {
    //
    //  Some variables to work with files
    //
    string transactionFileName = "transactionAccountsReceivable";
    string masterFileName = "masterAccountsReceivable";
    ifstream transactionFileStream;
    ofstream masterFileStream;
    //
    //  Variables for processing records
    //
    Record record = Record();
    Customer customer = Customer();
    //
    //  Get the transaction type
    //
    char transactionType;
    //
    //  Open the file streams
    //
    if(!openInputStream(transactionFileStream, transactionFileName)) {
        cerr << "Can't open file " << transactionFileName << ". " << '\n';
        return 1;
    }
    if(!openOutputStream(masterFileStream, masterFileName)) {
        cerr << "Can't open file " << masterFileName << ". " << '\n';
        return 1;
    }
    //
    //  Process the transactions
    //
    while (transactionFileStream.good()) {
        if (!(transactionFileStream >> transactionType)) {
            throw std::runtime_error(std::string("Error reading transactionType"));
        }
        //
        //  Store the appropriate record type for later.
        //  I read it here because of the design of the
        //  file format.
        //
        if (transactionType == 'P') {
            record.type = Payment;
        } else if(transactionType == 'O') {
            record.type = Order;
        }
        //
        //  Get the customer number next
        //
        if (!(transactionFileStream >> customer.customerNumber)) {
            throw std::runtime_error(std::string("Error reading customerNumber"));
        }
        //
        //     Process a payment record
        //
        if (record.type == Payment) {
            if (!(transactionFileStream >> record.cashAmount)) {
                throw std::runtime_error(std::string("Error reading cashAmount"));
            }
        }
        //
        //  Process an Order record
        //
        else if (record.type == Order) {
            readNCharactersFromStreamIntoArray(transactionFileStream, 20, record.itemName);
            if (!(transactionFileStream >> record.itemQuantity)) {
                throw std::runtime_error(std::string("Error reading itemQuantity"));
            }
            if (!(transactionFileStream >> record.cashAmount)) {
                throw std::runtime_error(std::string("Error reading cashAmount"));
            }
        }
        //
        //  We need to put the item into the master file
        //
        record.description();
        customer.description();
    }
    return 0;
}

//
//  Opens an input stream
//
bool openInputStream(ifstream &stream, string fileName) {
    stream.open(fileName.c_str());
    if (!stream.good()) {
        return false;
    }
    return true;
}


//
//  Opens an output stream
//

bool openOutputStream(ofstream &stream, string fileName) {
    stream.open(fileName.c_str());
    if (!stream.good()) {
        return false;
    }
    return true;
}

void readNCharactersFromStreamIntoArray(ifstream &stream, int n, char*characters) {
    for (int i = 0; i<n; i++) {
        if (!(stream >> characters[n])) {
            return;
        }
    }
}


// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:15:20: error: Record.h: No such file or directory
prog.cpp:16:22: error: Customer.h: No such file or directory
prog.cpp: In function ‘int main()’:
prog.cpp:39: error: ‘Record’ was not declared in this scope
prog.cpp:39: error: expected `;' before ‘record’
prog.cpp:40: error: ‘Customer’ was not declared in this scope
prog.cpp:40: error: expected `;' before ‘customer’
prog.cpp:69: error: ‘record’ was not declared in this scope
prog.cpp:69: error: ‘Payment’ was not declared in this scope
prog.cpp:71: error: ‘record’ was not declared in this scope
prog.cpp:71: error: ‘Order’ was not declared in this scope
prog.cpp:76: error: ‘customer’ was not declared in this scope
prog.cpp:82: error: ‘record’ was not declared in this scope
prog.cpp:82: error: ‘Payment’ was not declared in this scope
prog.cpp:90: error: ‘Order’ was not declared in this scope
prog.cpp:102: error: ‘record’ was not declared in this scope
prog.cpp:103: error: ‘customer’ was not declared in this scope

#endif
