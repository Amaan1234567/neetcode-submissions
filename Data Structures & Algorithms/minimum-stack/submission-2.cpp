#include <cstdlib>

class MinStack {
public:
    int capacity=1;
    int size=0;
    int* data;
    int top_ele=-1;
    int min_ele=INT_MAX;
    MinStack() {
        this->data = (int*)malloc(sizeof(int)*this->capacity);
    }
    
    void push(int val) {
        if(this->size == this->capacity){
            this->resize();
        }
        this->min_ele = min(this->min_ele,val);
        this->data[this->top_ele+1]=val;
        this->top_ele++;
        this->size++;
    }
    
    void pop() {
        this->top_ele--;
        this->size--;
        this->min_ele = INT_MAX;
        for(int i=0;i<this->size;i++){
            // std::cout<<this->data[i]<<",";
            this->min_ele = min(this->min_ele,this->data[i]);
        }
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
        return this->min_ele;
    }
};
