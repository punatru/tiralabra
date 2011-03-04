#ifndef MYVECTOR_H
#define MYVECTOR_H
#include<vector>
#include<cassert>
using namespace std;
template<typename T>
class MyVector {

    private:
        vector<T> v;
        T** array;
        int size;
        int arraysize;


    public:
        T* operator[] (int i) {return array[i];};
        MyVector(){
            
            size = 0;
            arraysize = 30;
            array = new T*[arraysize];
        }
        ~MyVector() {
            delete [] array;
        }

        int getsize(){
          return size;
        }

        void resize(int newsize){
            delete [] array;
            size = newsize;
            arraysize = 30;
            array = new T*[arraysize];
        }

        void push(T* node){
        	
        	if(size==arraysize){
                arraysize = arraysize*2;
                T**  temp = new T*[arraysize];
                for(int i=0; i<size; i++){
                    temp[i] = array[i];
                }
                delete [] array;
                array = temp;
                
            }
            
            int index = size;
            for(int i=size-1; i>=0; i--){
                if((*node) < (*array[i]) ){
                    array[i+1] = array[i];
                    index = i;
                }else{
                	break;
                }
            }

            array[index] = node;
            
            size++;
        }
        T* find(char letter){
        	if(size<=0) return 0;
            int roof = size-1;
            int floor = 0;
            int now = (roof+floor)/2;
            do{
                T* child = array[now];

                if((*child)==letter){
                    return child;
                }
                if((*child)>letter){
                    roof = now-1;
                } 
                if((*child)<letter){
                    floor = now+1;
                }
                
                now = (roof+floor)/2;
            }while(roof>=floor);
            return 0;
        }
};
#endif 
