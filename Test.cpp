#include "doctest.h"
#include "Matrix.hpp"
#include "string"
using namespace std;
using namespace zich;

TEST_CASE("Good+")
{
    bool answer = 0;
    Matrix m1{{1, 2, 3, 1, 2, 3, 1, 2, 3}, 3, 3};
    Matrix m2{{1, 2, 3, 4, 5, 6, 1, 2, 3}, 3, 3};
    Matrix m1m2{{2, 4, 6, 5, 7, 9, 2, 4, 6}, 3, 3};
    answer = (m1 + m2 == m1m2);
    CHECK(answer == true);
    ++m1;
    Matrix m1a{{2, 3, 4, 2, 3, 4, 2, 3, 4}, 3, 3};
    answer = (m1 == m1a);
    CHECK(answer == true);
    m1 += m1;
    Matrix m1b{{4, 6, 8, 4, 6, 8, 4, 6, 8}, 3, 3};
    answer = (m1 == m1b);
    CHECK(answer == true);
    Matrix m1ans = m1;
    answer = (m1ans == m1);
    CHECK(answer == true);

    Matrix ma1{{2, 0, 0, 0, 2, 0, 0, 0, 2}, 3, 3};
    Matrix ma2{{6, 0, 0, 0, 6, 0, 0, 0, 6}, 3, 3};
    Matrix ma1ma2{{8, 0, 0, 0, 8, 0, 0, 0, 8}, 3, 3};
    answer = (ma1 + ma2 == ma1ma2);
    CHECK(answer == true);
    ++ma1;
    Matrix ma1a{{3, 1, 1, 1, 3, 1, 1, 1, 3}, 3, 3};
    answer = (ma1 == ma1a);
    CHECK(answer == true);
    ma1 += ma1;
    Matrix ma1b{{6, 2, 2, 2, 6, 2, 2, 2, 6}, 3, 3};
    answer = (ma1 == ma1b);
    CHECK(answer == true);
    Matrix ma1ans = ma1;
    answer = (ma1ans == ma1);
    CHECK(answer == true);
}
TEST_CASE("Good-")
{
    bool answer = 0;
    Matrix m1{{1, 2, 3, 1, 2, 3, 1, 2, 3}, 3, 3};
    Matrix m2{{1, 2, 3, 4, 5, 6, 1, 2, 3}, 3, 3};
    Matrix m1m2{{0, 0, 0, -3, -3, -3, 0, 0, 0}, 3, 3};
    answer = (m1 - m2 == m1m2);
    CHECK(answer == true);
    --m1;
    Matrix m1a{{0, 1, 2, 0, 1, 2, 0, 1, 2}, 3, 3};
    answer = (m1 == m1a);
    CHECK(answer == true);
    m1 -= m1;
    Matrix m1b{{0, 0, 0, 0, 0, 0, 0, 0, 0}, 3, 3};
    answer = (m1 == m1b);
    CHECK(answer == true);
    Matrix m1ans = -m1;
    answer = (m1ans == -m1);
    CHECK(answer == true);

    Matrix ma1{{2, 0, 0, 0, 2, 0, 0, 0, 2}, 3, 3};
    Matrix ma2{{6, 0, 0, 0, 6, 0, 0, 0, 6}, 3, 3};
    Matrix ma1ma2{{-4, 0, 0, 0, -4, 0, 0, 0, -4}, 3, 3};
    answer = (ma1 - ma2 == ma1ma2);
    CHECK(answer == true);
    --ma1;
    Matrix ma1a{{1, -1, -1, -1, 1, -1, -1, -1, 1}, 3, 3};
    answer = (ma1 == ma1a);
    CHECK(answer == true);
    ma1 -= ma1;
    Matrix ma1b{{0, 0, 0, 0, 0, 0, 0, 0, 0}, 3, 3};
    answer = (ma1 == ma1b);
    CHECK(answer == true);
    Matrix ma1ans = -ma1;
    answer = (ma1ans == -ma1);
    CHECK(answer == true);
    CHECK(answer == true);
    CHECK(answer == true);
    CHECK(answer == true);
    CHECK(answer == true);
    CHECK(answer == true);
    CHECK(answer == true);
    CHECK(answer == true);
    CHECK(answer == true);
    CHECK(answer == true);

}

TEST_CASE("Good*"){
    bool answer = 0;
    Matrix q1{{3,4,0,1},2,2};
    Matrix q2{{1,2,0,3},2,2};
    Matrix q1q2{{3,18,0,3},2,2};
    answer = q1*q2==q1q2;
    CHECK(answer==true);
    3*q1;
    Matrix q13{{9,12,0,3},2,2};
    answer = 3*q1==q13;
    CHECK(answer==true);
    q1*=3;
    answer =(q1==q13);
    CHECK(answer==true);
    Matrix q3{{1,0,1,0,0,2},2,3};
    Matrix q23{{1,0,5,0,0,6},2,3};
    answer = q2*q3==q23;
    CHECK(answer == true);
}

TEST_CASE("compare"){
    bool answer = 0 ;
    Matrix q1{{3,4,0,1},2,2};
    Matrix q2{{1,2,0,3},2,2};
    Matrix q1q2{{3,18,0,3},2,2};
    answer = q1>q2;
    CHECK(answer==true);
    // answer = q2<q1;
    // CHECK(answer==true);
    // answer = q1q2<q2;
    // CHECK(answer==true);
    // answer =q1q2>=q1;
    // CHECK(answer==true);   
    // answer = q1!=q2;
    // CHECK(answer==true);
    // answer = q1-q2==q1-q2;
    // CHECK(answer == true);
    // answer = q2*q1!=q1q2;
    // CHECK(answer == true);

}

TEST_CASE("throws"){
    CHECK_THROWS(Matrix *t =new Matrix({1,2,3,4,50},2,3));
    CHECK_THROWS(Matrix *t =new Matrix({1,2,3,4},-2,-2));
    Matrix q1{{3,4,0,1,2,3,4,5,6},3,3};
    Matrix q2{{1,2,0,3},2,2};
    CHECK_THROWS(q1*q2);
    CHECK_THROWS(q2*q1);
    CHECK_THROWS(q1+q2);
    CHECK_THROWS(q1-q2);
    CHECK_THROWS(q1+=q2);
    CHECK_THROWS(q1-=q2);
    CHECK_THROWS(q1*=q2);
    CHECK_THROWS(q2*=q1);

    
    
}


    

