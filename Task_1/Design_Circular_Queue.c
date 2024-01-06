typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
   MyCircularQueue*  obj= (MyCircularQueue*)malloc(sizeof(MyCircularQueue)*k);
   obj->arr=(int*)malloc(sizeof(int)*k);
   obj->front=-1;
   obj->rear=-1;
   obj->size=k;
   return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front==-1&&obj->rear==-1;

}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear+1)%(obj->size)==obj->front;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj)){
        return false;
    }
    else if(myCircularQueueIsEmpty(obj)){
        obj->front++;
        obj->rear++;
        obj->arr[obj->rear]=value;
        return true;
    }
    obj->rear=(obj->rear+1)%obj->size;
    obj->arr[obj->rear]=value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return false;
    }
    else if(obj->rear==obj->front){
        obj->rear=-1;
        obj->front=-1;
        return true;
    }
    obj->front=(obj->front+1)%obj->size;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    return obj->arr[obj->rear];
}



void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}