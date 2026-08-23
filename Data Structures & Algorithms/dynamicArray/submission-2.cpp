#include <cstdlib>
class DynamicArray {
   public:
    int cap = 0;
    int size = 0;
    int* arr = nullptr;
    DynamicArray(int capacity) {
        this->arr = (int*)malloc(capacity*sizeof(int));
        this->cap = capacity;
    }

    int get(int i) { 
        // for(int i=0;i<size;i++){
        //     cout<<this->arr[i]<<",";
        // }
        return this->arr[i]; }

    void set(int i, int n) {
        this->arr[i] = n;
    }

    void pushback(int n) {
        
        if(this->size == this->cap){
            this->resize();
        }
        if(this->size!=0){
            this->arr[this->size] = n;
        } else {
            this->arr[0] = n;
        }
        this->size += 1;
        // cout<<"inside pushback"<<std::endl;
        // for(int i=0;i<this->size;i++){
        //     cout<<this->arr[i]<<",";
        // }
        // cout<<std::endl;
    }

    int popback() {
        // for(int i=0;i<size;i++){
        //     cout<<this->arr[i]<<",";
        // }
        int ele = this->arr[this->size - 1];
        this->size -= 1;
        return ele;
    }

    void resize() {
        int* new_arr =(int*) malloc(this->cap*2*sizeof(int));
        for (int i = 0; i < size; i++) {
            new_arr[i] = this->arr[i];
        }
        this->cap *= 2;
        free(this->arr);
        this->arr = new_arr;
        // cout<<"insize resize"<<std::endl;
        // for(int i=0;i<this->size;i++){
        //     cout<<this->arr[i]<<",";
        // }
        // cout<<std::endl;
    }

    int getSize() { return this->size; }

    int getCapacity() { return this->cap; }
};
