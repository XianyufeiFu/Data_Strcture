#include "expression_evaluator.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
    // My_Stack a;
    // string m;
    // getline(cin, m);
    // // // std::cout << s; 
    // // a.read_stack(s);
    // // a.print_stack();
    // // std::cout << a.len;
    // Expression_Evaluator b;
    // while(m != "q"){
    //     b.read_original(m);
    //     b.print_original();
    //     // b.original_stack.print_priority();
    //     // cout << endl;
    //     b.expression_change();
    //     // cout << '\t\t';
    //     b.print_rechanged();
    //     b.print_result();
    //     b.clear();
    //     getline(cin, m);
    // }
    // b.print_rechanged();
    // std::cout << a.my_stack[a.len - 1].ch;

    string s;
    Expression_Evaluator a;

    s = "1+2+3*2-6";
    a.do_all(s);

    s = "((1+3)/4-6)/5";
    a.do_all(s);

    s = "((1+3.1)/4.5-6)/5";
    a.do_all(s);

    s = "-1+3*(-5+6/-4)";
    a.do_all(s);

    s = "-1.26e-1-(2+-3.1e2+230)/-1.2e2";
    a.do_all(s);

    s = "(-1+3*(-5+6/-4)";
    a.do_all(s);

    s = "-1++3*(-5+6/-4)";
    a.do_all(s);

    s = "-1+3**(-5+6/-4)";
    a.do_all(s);

    s = "-1+3*(-5+6//-4)";
    a.do_all(s);

    s = "-1+3*(-5+6/-4)--2";
    a.do_all(s);

    s = "2*(-4)";
    a.do_all(s);

    s = "2---2";
    a.do_all(s);

    s = "1.2e+2+1";
    a.do_all(s);

    s = "a+b";
    a.do_all(s);

    s = "/3-1";
    a.do_all(s);

    s = "1/0.0";
    a.do_all(s);

    s = "1.2ee2+3";
    a.do_all(s);

    s = "1..24-1";
    a.do_all(s);

    s = ".21-1";
    a.do_all(s);

    while(1);

    return 0;

}