#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "redblacktree.cpp"
using namespace std;

Employee add_employee(const string& filename);
RedBlackTree<Employee> add_companys_data(const string& filename);

void startprogram();

void console(RedBlackTree<Employee>&c);
void error_at_login();
void login(RedBlackTree<Employee>&c);
bool existing_person(int i,string a,RedBlackTree<Employee>&c,Elem<Employee>* &e);

void decidewhattoshow(Elem<Employee>*&e,RedBlackTree<Employee>&c);
//what to show
void showpersonal(Elem<Employee>*&e,RedBlackTree<Employee>&c);
void showmedical(Elem<Employee>*&e,RedBlackTree<Employee>&c);
void showcontact(Elem<Employee>* &e,RedBlackTree<Employee>&c);
void showemployment(Elem<Employee>* &e,RedBlackTree<Employee>&c);
void showperformance(Elem<Employee>*&e,RedBlackTree<Employee>&c);
void showsecurity(Elem<Employee>*&e,RedBlackTree<Employee>&c);
void showall(Elem<Employee>*&e,RedBlackTree<Employee>&c);
void showadmin(Elem<Employee>*& e,RedBlackTree<Employee>&c);

