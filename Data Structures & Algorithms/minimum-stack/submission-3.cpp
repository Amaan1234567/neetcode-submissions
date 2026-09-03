#include <cstdlib>

class MinStack {
public:
    int capacity=1;
    int size=0;
    int* data;
    int top_ele=-1;
    stack<int> st;
    MinStack() {
        this->data = (int*)malloc(sizeof(int)*this->capacity);
    }
    
    void push(int val) {
        if(this->size == this->capacity){
            this->resize();
        }
        if(this->size==0){
            this->st.push(val);
        }
        this->st.push(min(this->st.top(),val));
        this->data[this->top_ele+1]=val;
        this->top_ele++;
        this->size++;
    }
    
    void pop() {
        this->top_ele--;
        this->size--;
        this->st.pop();
        // std::cout<<std::endl;
    }

    void resize(){
        this->capacity *= 2;
        int* temp = (int*)malloc(sizeof(int)*this->capacity);
        for(int i=0;i<this->size;i++){
            temp[i] = this->data[i];
        }
        free(this->data);
        this->data=temp;
    }
    
    int top() {
        return this->data[this->top_ele];
    }
    
    int getMin() {
        return this->st.top();
    }
};
