#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "canvaslist.h"
#include "include/shape.h"

using namespace std;
using namespace testing;

// TEST(FakeTest, PleaseDeleteOnceYouWriteSome) {
//   // If no tests exist, GoogleTest fails to compile with a fairly confusing
//   // message. We have this empty test that does nothing to allow an empty
//   // autograder submission to compile and regularly fail. Once you write your
//   // own tests for the project, you can delete this one.
//   EXPECT_THAT(1, Eq(1));
// }


/*TODO_STUDENT
- I have an overall leak somewhere, but idk where it is
*/ 


////////////Core Tests////////////
//They all pass, but the auto grader won't read...
TEST(CanvasListCore,Constrctor){ //Works
  CanvasList text;
  int expected = 0;
  //Checks if defualt starts empty
  ASSERT_THAT(text.size(),Eq(expected) )<< "text=\"" << text.size() << "\"";
  // delete text;
}

TEST(CanvasListCore,EmptySets){
  CanvasList text;
  bool expected = true;
  ASSERT_THAT(text.empty(),Eq(expected) ) << "First text=\"" << text.empty() << "\""; //works
  expected = false;
  
  Shape* v = new Shape();
  
  text.push_front(v);//is this the new issue?
  ASSERT_THAT(text.empty(),Eq(expected) )<< "Second text=\"" << text.empty() << "\""; 

  // text->list_size = 0;
  // ASSERT_THAT(text.empty(),Eq(expected) )<< "Second text=\"" << text.empty() << "\""; 
  // text.clear();
  // delete v; //needed or leaks -but need to be hidden for current Core tests on GradeScope - nvm all good now!
}

TEST(CanvasListCore,SizeTests){
  CanvasList text;
  int expected = 0;
  ASSERT_THAT(text.size(),Eq(expected) )<< "First text=\"" << text.size() << "\""; //works
  expected = 1; //to check size change- maybe add anohther for more than one-

  Shape* v = new Shape();
  text.push_front(v);//is this the new issue?
  ASSERT_THAT(text.size(),Eq(expected) )<< "Second text=\"" << text.size() << "\"";
  // delete v;
  
}

TEST(CanvasListCore,FrontTest){
  CanvasList text;
  ASSERT_THAT(text.front(), Eq(nullptr) ) << "First text=\"" << text.front() << "\"";

  Shape* v = new Shape(); 
  text.push_front(v);
 ASSERT_THAT(text.front()->value, Eq(v) ) << "Second text=\"" << text.front() << "\"";
  //  delete v;


}

TEST(CanvasListCore,PushFront){
  //check size and if contents are empty
  CanvasList text;
  bool expected = true;
  int expectedSize = 0;
  ASSERT_THAT(text.empty(),Eq(expected) )<< "If empty text=\"" << text.empty() << "\""; //works
  EXPECT_THAT(text.size(),Eq(expectedSize) )<< "Size text=\"" << text.size() << "\""; //works
  
  expected = false;
  expectedSize++;
  
  Shape* v = new Shape();
  
  text.push_front(v); 
  ASSERT_THAT(text.empty(),Eq(expected) )<< "If empty2 text=\"" << text.empty() << "\""; //works
  EXPECT_THAT(text.size(),Eq(expectedSize) )<< "Size2 text=\"" << text.size() << "\""; //works
  
  // delete v;
}

TEST(CanvasListCore,Clear){
  CanvasList text;
  bool expected = false;
  int expectedSize = 1;
  Shape* v = new Shape();
  text.push_front(v);

  ASSERT_THAT(text.empty(),Eq(expected) )<< "If empty text=\"" << text.empty() << "\""; //works
  EXPECT_THAT(text.size(),Eq(expectedSize) )<< "Size text=\"" << text.size() << "\""; //works

  text.clear(); //should now be empty
  expected = true;
  expectedSize--;
  ASSERT_THAT(text.empty(),Eq(expected) )<< "If empty2 text=\"" << text.empty() << "\""; //works
  EXPECT_THAT(text.size(),Eq(expectedSize) )<< "Size2 text=\"" << text.size() << "\""; //works
  
  
  // delete v;
}
////////////Core Tests////////////

////////////Iterating Tests////////////

//Is having a timing out issue...
TEST(CanvasListIterating, Copy){
  CanvasList text; //shape order: r, c, d
  Shape* d = new Shape(13,12);
  text.push_front(d);
  Circle* c = new Circle(2,4,6);
  text.push_front(c);
  Rect* r = new Rect(4, 6, 12, 16);
  text.push_front(r);
  CanvasList textCopy(text); //It's good now
  // textCopy = text; 
  //Keeps comparing ptrs instead of the actual shape values- help-
  ASSERT_THAT(text.front()->value->as_string(),StrEq( textCopy.front()->value->as_string()))<< "text 1=\"" << textCopy.front()->value->as_string() << "\""; //rect
  ASSERT_THAT(text.front()->next->value->as_string(), StrEq(textCopy.front()->next->value->as_string() ))<< "text 2=\"" << textCopy.front()->value << "\""; //circle
  ASSERT_THAT(text.front()->next->next->value->as_string(), StrEq(textCopy.front()->next->next->value->as_string()))<< "text 3=\"" << textCopy.front()->value << "\""; //defualt
  // delete r;
  // delete c;
  // delete d;
}

TEST(CanvasListIterating, PushBack){
  CanvasList text; //shape order: d, c
  int expectedSize = 1;
  Shape* d = new Shape(13,12);
  text.push_back(d);
  //This methood worked when I used it for core tetsts???
  ASSERT_THAT(text.front()->value, Eq(d) ) << "First text=\"" << text.front() << "\"";
  EXPECT_THAT(text.size(),Eq(expectedSize) )<< "Size1 text=\"" << text.size() << "\""; //works

  expectedSize++;
  Circle* c = new Circle(2,4,6);
  text.push_back(c);

  ASSERT_THAT(text.front()->value, Eq(d) ) << "Front text=\"" << text.front() << "\""; //current front
  ASSERT_THAT(text.front()->next->value , Eq(c) ) << "End text=\"" << text.front() << "\""; //current end
  EXPECT_THAT(text.size(),Eq(expectedSize) )<< "Size2 text=\"" << text.size() << "\""; //works

}

TEST(CanvasListIterating,ShapeAt){ //add test?
  CanvasList text; //shape order: r, c, d
  Shape* d = new Shape(13,12);
  text.push_front(d);
  Circle* c = new Circle(2,4,6);
  text.push_front(c);
  Rect* r = new Rect(4, 6, 12, 16);
  text.push_front(r);
  //testing in bounds
  ASSERT_THAT(text.shape_at(1), Eq(c) ) << "In Bounds 1 text=\"" << text.shape_at(1) << "\"";
  ASSERT_THAT(text.shape_at(2), Eq(d) ) << "In Bounds 2 text=\"" << text.shape_at(2) << "\"";

  ASSERT_THAT(text.shape_at(4), Eq(nullptr) ) << "Out of Bounds Pos text=\"" << text.shape_at(4) << "\"";
  ASSERT_THAT(text.shape_at(-1), Eq(nullptr) ) << "Out of Bounds Neg text=\"" << text.shape_at(-1) << "\"";

}

TEST(CanvasListIterating, Find){
  CanvasList text; //shape order: r, c, d
  ASSERT_THAT(text.find(0,0), Eq(-1) ) << "Empty text=\"" << text.find(0,0) << "\"";
  Shape* d = new Shape(13,12);
  text.push_front(d);
  Circle* c = new Circle(2,4,6);
  text.push_front(c);
  Rect* r = new Rect(4, 6, 12, 16);
  text.push_front(r);
  //returns location...
  ASSERT_THAT(text.find(13,12), Eq(2) ) << "Empty text=\"" << text.find(13,12) << "\"";
  ASSERT_THAT(text.find(2,4), Eq(1) ) << "Empty text=\"" << text.find(2,4) << "\"";
  ASSERT_THAT(text.find(4,6), Eq(0) ) << "Empty text=\"" << text.find(4,6) << "\"";
  ASSERT_THAT(text.find(4,4), Eq(-1) ) << "Empty text=\"" << text.find(4,4) << "\"";

}
////////////Iterating Tests////////////

// ////////////Modifying Tests////////////
// check "//comment out when submitting" to block things to run
TEST(CanvasListModifying ,equalOperator){
  CanvasList text; //shape order: r, c, d
  Shape* d = new Shape(13,12);
  text.push_front(d);
  Circle* c = new Circle(2,4,6);
  text.push_front(c);
  Rect* r = new Rect(4, 6, 12, 16);
  text.push_front(r);
  CanvasList textCopy; //It's good now
  textCopy = text; 
  //Copy does not make the correct shape
  ASSERT_THAT(text.front()->value->as_string(),StrEq( textCopy.front()->value->as_string()))<< "text 1=\"" << textCopy.front()->value->as_string() << "\""; //rect
  ASSERT_THAT(text.front()->next->value->as_string(), StrEq(textCopy.front()->next->value->as_string() ))<< "text 2=\"" << textCopy.front()->value << "\""; //circle
  ASSERT_THAT(text.front()->next->next->value->as_string(), StrEq(textCopy.front()->next->next->value->as_string()))<< "text 3=\"" << textCopy.front()->value << "\""; //defualt
  ASSERT_THAT(text.size(), Eq(textCopy.size())) << " Size text =\"" << textCopy.size() << "\""; //rect

  CanvasList copy; //a, b
  Shape* a = new Shape();
  Shape* b = new Shape();
  copy.push_front(b);
  copy.push_front(a);
  CanvasList& y = copy;
  CanvasList& q = copy;
 
  q = y;
  // cout << "/////////////////////////////"<< q.front()->value->as_string()<< "/////////////////////////////" <<endl;


  // ASSERT_THAT(q.size(), Eq(2)) << " copy q Size text =\"" << q.size() << "\""; //rect
  // ASSERT_THAT(y.size(), Eq(2)) << " copy y Size text =\"" << y.size() << "\""; //rect

}

TEST(CanvasListModifying ,popFront){
  CanvasList text; //shape order: r, c, d

  ASSERT_THAT(text.pop_front(), Eq(nullptr)) << "Pop when empty text=\"" << text.size() << "\""; // causing AddressSanitizer: failed to parse suppressions...

  Shape* d = new Shape(13,12);
  text.push_front(d);
  Circle* c = new Circle(2,4,6);
  text.push_front(c);
  Rect* r = new Rect(4, 6, 12, 16);
  text.push_front(r);
  ASSERT_THAT(text.front()->value->as_string(), StrEq(r->as_string())) << "First text=\"" << text.front()->value->as_string() << "\"";
  EXPECT_THAT(text.size(), Eq(3)) << "First size=\"" << text.size() << "\"";

  ASSERT_THAT(text.pop_front()->as_string(), StrEq(r->as_string())) << "text=\"" << text.front() << "\""; //caused leak...?
  // text.pop_front();

  ASSERT_THAT(text.front()->value->as_string(), StrEq(c->as_string())) << "After text=\"" << text.front()->value->as_string() << "\"";
  EXPECT_THAT(text.size(), Eq(2)) << "After size=\"" << text.size() << "\"";

  delete r; 
}

TEST(CanvasListModifying ,popBack){ //DONE
  CanvasList text; //shape order: r, c, d

  ASSERT_THAT(text.pop_back(), Eq(nullptr)) << "Pop when empty text=\"\""; // causing AddressSanitizer: failed to parse suppressions...

  Shape* d = new Shape(13,12);
  text.push_front(d);
  Circle* c = new Circle(2,4,6);
  text.push_front(c);
  Rect* r = new Rect(4, 6, 12, 16);
  text.push_front(r);

  ASSERT_THAT(text.shape_at(2)->as_string(), StrEq(d->as_string()) ) << "First text=\"" << text.shape_at(2)->as_string() << "\"";
  EXPECT_THAT(text.size(), Eq(3)) << "First size=\"" << text.size() << "\"";

  //deleting d
  ASSERT_THAT(text.pop_back()->as_string(), StrEq(d->as_string())) << "text=\"" << d->as_string() << "\"";

  //checking after pop
  ASSERT_THAT(text.shape_at(1)->as_string(), StrEq(c->as_string()) ) << "Second text=\"" << text.shape_at(1)->as_string() << "\"";
  EXPECT_THAT(text.size(), Eq(2)) << "Second size=\"" << text.size() << "\"";

  //checking if r and c are present
  ASSERT_THAT(text.front()->value, Eq(r)) << "First val text=\"" << text.front()->value << "\"";
  ASSERT_THAT(text.front()->next->value, Eq(c)) << "Second val text=\"" << text.front()->next->value << "\"";

  text.pop_back(); //deleting c
  
  ASSERT_THAT(text.empty(), Eq(false)) << "Is it empty? text=\"" << text.empty() << "\"";
  ASSERT_THAT(text.front()->value, Eq(r)) << "Front with 1 value text=\"" << text.front()->value << "\"";
  ASSERT_THAT(text.size(), Eq(1)) << "Third size=\"" << text.size() << "\""; 
  Shape* s = new Shape();
  text.push_back(s);
  //r,s

  ASSERT_THAT(text.size(), Eq(2)) << "Forth size=\"" << text.size() << "\"";
  ASSERT_THAT(text.front()->value, Eq(r)) << "First val_2 text=\"" << text.front()->value << "\"";
  ASSERT_THAT(text.front()->next->value, Eq(s)) << "Second val_2 text=\"" << text.front()->next->value << "\"";

  delete d; 
  delete c;

  CanvasList singleElementList;
  Shape* singleShape = new Shape(5, 5); // Create a shape

  singleElementList.push_front(singleShape); // Add single element
  ASSERT_THAT(singleElementList.size(), Eq(1))  << "SingleSize before pop text=\"" << text.size() << "\"";

  Shape* poppedShape = singleElementList.pop_back(); // Pop the only element
  ASSERT_THAT(poppedShape->as_string(), StrEq(singleShape->as_string())) << "text=\"" << poppedShape->as_string() << "\"";

  delete poppedShape;

  ASSERT_THAT(singleElementList.size(), Eq(0)) << "SingleSize after pop text=\"" << text.size() << "\"";
  ASSERT_THAT(singleElementList.empty(), Eq(true)) << "text=\"" << text.empty() << "\"";
}

TEST(CanvasListModifying, removeAt){ //check size and use shapeAt?
  CanvasList text; //shape order: r, c, d
  int expected = 3;
  Shape* d = new Shape(13,12);
  text.push_front(d);
  Circle* c = new Circle(2,4,6);
  text.push_front(c);
  Rect* r = new Rect(4, 6, 12, 16); //causing leak??
  text.push_front(r);
  text.remove_at(0); //deleteing r
 
  expected--;

  ASSERT_THAT(text.front()->value, Eq(c)) << "Value check v1 text=\"" <<text.front()->value << "\"";
  ASSERT_THAT(text.front()->next->value, Eq(d)) << "Value check v1 2 text=\"" <<text.front()->value << "\"";
  
  EXPECT_THAT(text.size(), Eq(expected)) << "First size text=\"" <<text.size() << "\"";

  text.remove_at(5); //deleting none
  ASSERT_THAT(text.front()->value, Eq(c)) << "Value check 2 text=\"" <<text.front()->value << "\"";
  ASSERT_THAT(text.front()->next->value, Eq(d)) << "Value check 3 text=\"" <<text.front()->value << "\"";
  ASSERT_THAT(text.size(),Eq(expected) )  << "Second size text=\"" <<text.size() << "\"";

  ASSERT_THAT(text.shape_at(0), Eq(c) ) << "In Bounds 1 text=\"" << text.shape_at(0) << "\"";
  ASSERT_THAT(text.shape_at(1), Eq(d) ) << "In Bounds 2 text=\"" << text.shape_at(1) << "\"";

  
  text.remove_at(1); // deleting d
  expected--; // Decrement expected size
  ASSERT_THAT(text.size(), Eq(expected)) << "Size after removing last element text=\"" << text.size() << "\"";
  ASSERT_THAT(text.front()->value, Eq(c)) << "Front should still be the circle after removing last element text=\"" << text.front()->value << "\"";

  // Ensure the list is now empty after removing 'c'
  text.remove_at(0); // deleting c
  expected--; // Should now be zero

  // Confirm the list is empty
  ASSERT_THAT(text.size(), Eq(expected)) << "Size after removing last element text=\"" << text.size() << "\"";
  ASSERT_THAT(text.empty(), Eq(true)) << "List should be empty after removing all elements";

  //Why does deleting in remove_at cause issues on GradeScope but pop_back/front don't??????
  // delete r; //comment out when submitting
  // delete d; //comment out when submitting
  // delete c; //comment out when submitting
}

TEST(CanvasListModifying, removeLost){
  CanvasList notLost; // a, b, e
  int expected = 3;
  Shape* a = new Shape();
  notLost.push_back(a);
  Shape* b = new Shape();
  notLost.push_back(b);
  Shape* e = new Shape();
  notLost.push_back(e);

  notLost.remove_at(1); //deleting b
  expected--;

  ASSERT_THAT(notLost.front()->value, Eq(a)) << "Value check v1 text=\"" <<notLost.front()->value << "\"";
  ASSERT_THAT(notLost.front()->next->value, Eq(e)) << "Value check v1 2 text=\"" <<notLost.front()->value << "\"";
  
  EXPECT_THAT(notLost.size(), Eq(expected)) << "First size text=\"" <<notLost.size() << "\"";

  // delete b; //comment out when submitting
}
////////////Modifying Tests////////////

////////////Extras Tests////////////

TEST(CanvasListExtras,insertAfter){
  CanvasList text;
  Shape* a = new Shape();
  Shape* b = new Shape();
  Shape* c = new Shape();

  //check adding when empty
  text.insert_after(0,a); //a gets deleted. Also takes ownership of a
  delete a; //comment in when submitting...
  //is the problem child, but I need it for the 4 pts-

  //check that nothing changed
  ASSERT_THAT(text.empty(), Eq(true))<< "text=\"" << text.empty() << "\"";
  ASSERT_THAT(text.size(), Eq(0))<< "text=\"" << text.size() << "\"";

  text.push_back(b);

  text.insert_after(0,c); //adding to a node with 1
  ASSERT_THAT(text.size(), Eq(2))<< "text=\"" << text.size() << "\"";
  ASSERT_THAT(text.front()->value, Eq(b))<< "text=\"" << text.front()->value << "\"";
  ASSERT_THAT(text.front()->next->value, Eq(c))<< "text=\"" << text.front()->next->value << "\"";
}

TEST(CanvasListExtras, removeEveryOther){
  CanvasList text; //shape order: r, c, d, a, b

  text.remove_every_other();
  ASSERT_THAT(text.size(), Eq(0)) << "new size text=\"" << text.size() << "\""; 
  ASSERT_THAT(text.empty(), Eq(true)) << "is empty text=\"" << text.empty() << "\""; 

  Shape* a = new Shape;
  text.push_back(a);
  Shape* b = new Shape;
  text.push_back(b);
  Shape* d = new Shape(13,12);
  text.push_front(d);
  Circle* c = new Circle(2,4,6);
  text.push_front(c);
  Rect* r = new Rect(4, 6, 12, 16);
  text.push_front(r);

  text.remove_every_other(); //shape order: r, d, b
  

  ASSERT_THAT(text.size(), Eq(3)) << "new size text=\"" << text.size() << "\""; //currently wrong...
  ASSERT_THAT(text.front()->value->as_string(), Eq(r->as_string())) << "1st shape text=\"" << text.front()->value->as_string() << "\"";
  ASSERT_THAT(text.front()->next->value->as_string(), Eq(d->as_string())) << "2nd shape text=\"" << text.front()->next->value->as_string() << "\"";
  ASSERT_THAT(text.front()->next->next->value->as_string(), Eq(b->as_string())) << "3rd shape text=\"" << text.front()->next->next->value->as_string() << "\"";
  
}

////////////Extras Tests////////////




