#include <iostream>
#include <stack>
using namespace std;
    
struct Node
{
    int  priority;
    char ch;
    double value = 0;
};

bool is_operator(char c){
    return (c == '+' || c == '-' || c == '/' || c == '*' || c == '(' || c == ')'); 
}

double my_pow(double t, int k){
    if(k == 0) return 1;
    double res = 1;
    for(int i = 0; i < k; i++){
        res = res * t;
    }
    return res;
}

class My_Stack
{
public:
    Node my_stack[100000];
    int len = 0;

    void push_stack(Node p){
        my_stack[len] = p;
        len ++;
    } 

    Node pop_stack(){
        len --;
        return my_stack[len];
    }

    void read_stack(string s){
        char a;
        double v = 0;
        double v1 = 0;
        double v2 = 0;
        int mi = 0;
        char last_ch = -1;
        bool flag = 0;

        int i = 0;
        a = s[i];

        int flag1 = 1;
        int flag2 = 0;
        int flag3 = 0;
        int flag4 = 0;
        int k = 1;
        bool my_switch = 0;

        while(a != '\0')
        {
            // if(a == ' ') continue;
            
            if(a == '.'){
                flag2 = 1;
            }
            else if( a == 'e'){
                flag3 = 1;
            }
            else if(last_ch == 'e' && a == '-'){
                flag4 = 1;
            }
            else if((a >= '0' && a <= '9')){
                if(a == '0') my_switch = 1;
                if(flag2 == 0 && flag3 == 0){
                    v1 = 10 * v1 + a - '0';
                }
                else if(flag2 == 1 && flag3 == 0){
                    v2 = v2 + (a - '0') * my_pow(0.1, k);
                    k++;
                }
                else if(flag3 == 1){
                    mi = 10 * mi + a - '0';
                }
                // cout << a;
            }
            else if(((last_ch == -1 || is_operator(last_ch)) && last_ch != ')') && a == '-'){
                flag1 = -1;
            }
            else 
            {
                if(v1 != 0 || v2 != 0){
                    my_switch = 1;
                }
                else if(!is_operator(last_ch)){
                    if(last_ch > 0){
                        my_switch = 1;                    
                    }
                }
                if(my_switch){
                    if(flag3 == 0)
                        v = flag1 * (v1 + v2);
                    else{
                        if(flag4 == 0){
                            double m = my_pow(10, mi);
                            // cout << m << endl;
                            v = flag1 * (v1 + v2) * m; 
                        }
                        else{
                            double m = my_pow(0.1, mi);
                            // cout << m << endl;
                            v = flag1 * (v1 + v2) * m;
                        }
                    }
                    Node num = {-1, -1, v};
                    // cout << flag1 << ' ' << num.value << endl;
                    push_stack(num);
                    v1 = v2 = v = 0;
                    k = 1;
                    flag1 = 1;
                    flag2 = 0;
                    flag3 = 0;
                    flag4 = 0;
                    mi = 0;
                }
                Node p;
                if(a == '+' || a == '-')
                    p = {1, a, 0};
                else if(a == '*' || a == '/')
                    p = {2, a, 0};
                else if(a == '(')
                    p = {0, a, 0};
                else if(a == ')')
                    p = {0, a, 0};
                push_stack(p);
                flag = 1;
            }
            last_ch = a;
            i++;
            a = s[i];
            // cout <<  v1 << ' ' << flag2 << ' ' << v2 << ' ' << mi << endl;
        }
        if(a == '\0'){
            if(v1 != 0 || v2 != 0 || my_switch){
                if(flag3 == 0)
                    v = flag1 * (v1 + v2);
                else{
                    if(flag4 == 0){
                        double m = my_pow(10, mi);
                        // cout << m << endl;
                        v = flag1 * (v1 + v2) * m; 
                    }
                    else{
                        double m = my_pow(0.1, mi);
                        // cout << m << endl;
                        v = flag1 * (v1 + v2) * m;
                    }
                }
                Node num = {-1, -1, v};
                push_stack(num);
            }
            // else if(is_operator(last_ch)){
            //     Node num = {-1, -1, 0};
            //     push_stack(num);
            // }
        }
    }

    void print_stack(){
        for(int i = 0;i < len; i++)
        {
            if(my_stack[i].priority == -1)
                cout << my_stack[i].value << ' ';
            else 
                cout << my_stack[i].ch << ' ';
        }
        cout << endl;
    }

    bool is_empty(){
        if(len == 0) return 1;
        if(len > 0) return 0;
    }

    void print_priority(){
        for(int i = 0; i < len; i++){
            cout << my_stack[i].priority << ' ';
        }
        cout << endl;
    }

    void clear_stack(){
        len = 0;
    }

};



class Expression_Evaluator
{
public: 

    Expression_Evaluator(){

    }

    My_Stack original_stack;
    My_Stack op_stack;
    My_Stack rechanged_stack;
    My_Stack calculate_stack;

    void expression_change(){
        Node end{-2, '#', 0};
        op_stack.push_stack(end);
        for(int i = 0; i < original_stack.len; i++)
        {
            if(original_stack.my_stack[i].priority == -1){
                Node p = original_stack.my_stack[i];
                rechanged_stack.push_stack(p);
            }
            else{
                Node current = original_stack.my_stack[i];
                // cout << current.priority <<endl;
                if(op_stack.my_stack[op_stack.len-1].ch == '#'){
                    op_stack.push_stack(current);
                }
                else if(current.ch == ')'){
                    Node p = op_stack.pop_stack();
                    // cout << endl << p->ch;
                    while(p.ch != '('){
                        rechanged_stack.push_stack(p);
                        p = op_stack.pop_stack();
                    }
                }
                else if(current.ch == '('){
                    op_stack.push_stack(current);
                }
                else if(current.priority > op_stack.my_stack[op_stack.len-1].priority){
                    op_stack.push_stack(current);
                }
                else{
                    while(current.priority <= op_stack.my_stack[op_stack.len-1].priority){
                        rechanged_stack.push_stack(op_stack.pop_stack());
                    }
                    op_stack.push_stack(current);
                }
                
            }
            // op_stack.print_stack();
        }
        while(op_stack.my_stack[op_stack.len-1].ch != '#'){
            rechanged_stack.push_stack(op_stack.pop_stack());
        }
    }

    bool correct_flag = 1;

    bool operation(char ch){
        Node a,b;
        if(!calculate_stack.is_empty()){
            a = calculate_stack.pop_stack();
            if(a.priority != -1){
                cout << "Invalid Formula!" << endl;
                correct_flag = 0;
                return 0; 
            }
        }
        else{
            cout << "Invalid Formula!" << endl;
            correct_flag = 0;
            return 0; 
        }
        if(!calculate_stack.is_empty()){
            b = calculate_stack.pop_stack();
            if(b.priority != -1){
                cout << "Invalid Formula!" << endl;
                correct_flag = 0;
                return 0; 
            }
        }
        else{
            cout << "Invalid Formula!" << endl;
            correct_flag = 0;
            return 0;
        }
        double result;
        if(ch == '+'){
            result = a.value + b.value;
        }
        else if(ch == '-'){
            result = b.value - a.value;
        }
        else if(ch == '*'){
            result = a.value * b.value;
        }
        else if(ch == '/'){
            result = b.value / a.value;
        }
        Node c = {-1, 0 , result};
        calculate_stack.push_stack(c);
        return 1;
    }

    double calculate(){
        for(int i = 0; i < rechanged_stack.len; i++){
            Node current = rechanged_stack.my_stack[i];
            if(current.priority == -1){
                calculate_stack.push_stack(current);
            }
            else if(is_operator(current.ch)){
                if(!operation(current.ch))
                    return -1;
            }
            // calculate_stack.print_stack();
        }
        if(calculate_stack.len != 1){
            cout << "Invalid Formula!" << endl;
            correct_flag = 0;
            return -1; 
        }
        else{
            return calculate_stack.pop_stack().value;
        }
    }

    void print_result(){
        double result = calculate();
        if(correct_flag)
            cout << result << endl;
        else{
            cout << "No result!";
        }
    }

    void read_original(string s){
        original_stack.read_stack(s);
    }

    void print_original(){
        original_stack.print_stack();
    }

    void print_rechanged(){
        rechanged_stack.print_stack();
    }

    void clear(){
        original_stack.clear_stack();
        op_stack.clear_stack();
        rechanged_stack.clear_stack();
        calculate_stack.clear_stack();
    }

};
