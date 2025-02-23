#include "include/shape.h"

#include <sstream>
#include <string>

using namespace std;

//////////Shape//////////
Shape::Shape() {
  // TODO_STUDENT
  x = 0;
  y = 0;
}

Shape::Shape(int x, int y) {
  // TODO_STUDENT
  this->x = x;
  this->y = y;
  //what is the diffrence???
  //this classes x = int x. That's the diffrence...
}

Shape::~Shape() {
  // TODO_STUDENT
  // delete[];
  //don't need anything sicne they don't take momory-
}

Shape* Shape::copy() { 
  // TODO_STUDENT
  
  return new Shape(x, y);
}

int Shape::getX() const {
  // TODO_STUDENT
  return this->x;
}

int Shape::getY() const {
  // TODO_STUDENT
  return this->y;
}

void Shape::setX(int x) {
  // TODO_STUDENT
  this->x = x;
}

void Shape::setY(int y) {
  // TODO_STUDENT
  this->y = y;
}

string Shape::as_string() const {
  // TODO_STUDENT
  int X = getX();
  int Y = getY();
  string answer = "It's a Shape at x: " + to_string(X)+", y: "+ to_string(Y);
  return answer;
}
//////////Shape//////////

//////////Circle//////////
Circle::Circle(){
 x = 0;
 y = 0;
 radius =0;
}

Circle::Circle(int r){
  x = 0;
  y = 0;
  this->radius = r;
}

Circle::Circle(int x, int y, int r){
  this->x = x;
  this->y = y;
  this->radius = r;
}

Circle::~Circle() {
  // TODO_STUDENT
  // delete[];
  //don't need anything sicne they don't take momory-
}

Circle* Circle::copy(){
  return new Circle(x, y, radius);
}

int Circle::getRadius() const{
  return this->radius;
}

void Circle::setRadius(int r){
  this->radius = r;
}

string Circle::as_string() const {
  // TODO_STUDENT
  int X = getX();
  int Y = getY();
  int R = getRadius();
  string answer = "It's a Circle at x: " + to_string(X)+", y: "+ to_string(Y)+", radius: "+ to_string(R);
  return answer;
}
//////////Circle//////////

//////////Rect//////////

Rect::Rect(){
  width = 0;
  height = 0;
  x = 0;
  y = 0;
}

Rect::Rect(int w, int h){
  this->width = w;
  this-> height = h;
  x = 0;
  y = 0;
}

Rect::Rect(int x, int y, int w, int h){
  this->x = x;
  this->y = y;
  this->width = w;
  this-> height = h;
}

Rect::~Rect() {
  // TODO_STUDENT
  // delete[];
  //don't need anything sicne they don't take momory-
}

Rect* Rect::copy(){
  return new Rect(x, y, width, height);
}

int Rect::getWidth() const{
  return this-> width;
}

int Rect::getHeight() const{
  return this-> height;
}

void Rect::setWidth(int w){
  this ->width = w;
}

void Rect::setHeight(int h){
  this ->height = h;
}

string Rect::as_string() const {
  int X = getX();
  int Y = getY();
  int W = getWidth();
  int H = getHeight();
  string answer = "It's a Rectangle at x: " + to_string(X)+", y: "+ to_string(Y)+" with width: "+ to_string(W)+" and height: "+ to_string(H);
  return answer;
}
//////////Rect//////////

//////////RightTriangle//////////
RightTriangle::RightTriangle(){
  x = 0;
  y = 0;
  base = 0;
  height = 0;
}

RightTriangle::RightTriangle(int b, int h){
  x = 0;
  y = 0;
  this -> base = b;
  this -> height = h;
}

RightTriangle::RightTriangle(int x, int y, int b, int h){
  this -> x = x;
  this -> y = y;
  this -> base = b;
  this -> height = h;
}

RightTriangle::~RightTriangle() {
  // TODO_STUDENT
  // delete[];
  //don't need anything sicne they don't take momory-
}

RightTriangle* RightTriangle::copy(){
  return new RightTriangle(x, y, base, height);
}

int RightTriangle::getBase() const{
  return this-> base;
}

int RightTriangle::getHeight() const{
  return this -> height;
}

void RightTriangle::setBase(int  b){
  this -> base = b;
}

void RightTriangle::setHeight(int h){
  this -> height = h;
}

string RightTriangle::as_string() const {
  int X = getX();
  int Y = getY();
  int B = getBase();
  int H = getHeight();
  string answer = "It's a Right Triangle at x: " + to_string(X)+", y: "+ to_string(Y)+" with base: "+ to_string(B)+" and height: "+ to_string(H);
  return answer;
}
//////////RightTriangle//////////
