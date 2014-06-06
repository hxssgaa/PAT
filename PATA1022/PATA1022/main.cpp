//
//  main.cpp
//  PATA1022
//
//  此题注意getline的用法，以及好好读读输出信息，不要以为输出的book只有一个
//  加快你的速度，it's so so.... long.
//  Created by Xin Huang on 5/5/14.
//  Copyright (c) 2014 David Huang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

int N, M;

typedef struct bookT{
    string id;
    string title;
    string author;
    string keyWords;
    string publisher;
    string publishedYear;
}bookT;

vector<string> getKeywords(string s) {
    stringstream ss(s);
    vector<string> vec;
    string keyword;
    while (getline(ss, keyword, ' ')) {
        vec.push_back(keyword);
    }
    return vec;
}

int main(int argc, const char * argv[])
{
    string sN;
    getline(cin, sN);
    N = atoi(sN.c_str());
    bookT *book = NULL;
    map<string, vector<bookT *>> titleMap;
    map<string, vector<bookT *>> authorMap;
    map<string, vector<bookT *> > keyWordMap;
    map<string, vector<bookT *>> publisherMap;
    map<string, vector<bookT *>> publisherYearMap;
    for (int i = 0; i < N; i++) {
        book = new bookT;
        getline(cin, book->id);
        getline(cin, book->title);
        //实质上这种构建map->vector的方法可以用函数来简便构建.
        if (titleMap.find(book->title) == titleMap.end()) {
            vector<bookT *> vec;
            vec.push_back(book);
            titleMap.insert(pair<string, vector<bookT *>>(book->title, vec));
        } else {
            titleMap[book->title].push_back(book);
        }
        getline(cin, book->author);
        if (authorMap.find(book->author) == authorMap.end()) {
            vector<bookT *> vec;
            vec.push_back(book);
            authorMap.insert(pair<string, vector<bookT *>>(book->author, vec));
        } else {
            authorMap[book->author].push_back(book);
        }
        getline(cin, book->keyWords);
        vector<string> keywords = getKeywords(book->keyWords);
        for (string eachKeyWord : keywords) {
            if (keyWordMap.find(eachKeyWord) == keyWordMap.end()) {
                vector<bookT *> vec;
                vec.push_back(book);
                keyWordMap.insert(pair<string, vector<bookT *>>(eachKeyWord, vec));
            } else {
                keyWordMap[eachKeyWord].push_back(book);
            }
        }
        getline(cin, book->publisher);
        if (publisherMap.find(book->publisher) == publisherMap.end()) {
            vector<bookT *> vec;
            vec.push_back(book);
            publisherMap.insert(pair<string, vector<bookT *>>(book->publisher, vec));
        } else {
            publisherMap[book->publisher].push_back(book);
        }
        getline(cin, book->publishedYear);
        if (publisherYearMap.find(book->publishedYear) == publisherYearMap.end()) {
            vector<bookT *> vec;
            vec.push_back(book);
            publisherYearMap.insert(pair<string, vector<bookT *>>(book->publishedYear, vec));
        } else {
            publisherYearMap[book->publishedYear].push_back(book);
        }
    }
    getline(cin, sN);
    M = atoi(sN.c_str());
    vector<pair<int, string>> query;
    for (int i = 0; i < M; i++) {
        string queryStr;
        getline(cin, queryStr);
        for (int j = 0; j < queryStr.size(); j++) {
            if (queryStr[j] == ':') {
                query.push_back(pair<int, string>(atoi(queryStr.substr(0, j).c_str()),queryStr.substr(j + 2, queryStr.size() - j - 2).c_str()));
                break;
            }
        }
    }
    for (pair<int, string> eachQ : query) {
        cout << eachQ.first << ": " << eachQ.second << endl;
        vector<bookT *> vec;
        vector<string> strVec;
        switch (eachQ.first) {
            case 1:
                if (titleMap.find(eachQ.second) != titleMap.end()) {
                    vec = titleMap[eachQ.second];
                }
                break;
            case 2:
                if (authorMap.find(eachQ.second) != authorMap.end()) {
                    vec = authorMap[eachQ.second];
                }
                break;
            case 3:
                if (keyWordMap.find(eachQ.second) != keyWordMap.end()) {
                    vec = keyWordMap[eachQ.second];
                }
                break;
            case 4:
                if (publisherMap.find(eachQ.second) != publisherMap.end()) {
                    vec = publisherMap[eachQ.second];
                }
                break;
            case 5:
                if (publisherYearMap.find(eachQ.second) != publisherYearMap.end()) {
                    vec = publisherYearMap[eachQ.second];
                }
                break;
            default:
                break;
        }
        if (vec.size() == 0) cout << "Not Found" << endl;
        for (bookT *eachBook : vec) {
            strVec.push_back(eachBook->id);
        }
        sort(strVec.begin(), strVec.end());
        for (string eachStr : strVec) {
            cout << eachStr << endl;
        }
    }
    return 0;
}

