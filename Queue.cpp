int s = 50;
template <class Q>
class queue
{
private:
    Q* arr;
    int front;
    int rear;
public:
    queue()
    {
        arr = new Q[s];
        front = -1;
        rear = -1;
    }
    Q getFront()
    {
        return arr[front];
    }
    void enque(Q x)
    {
        if (isFull())
        {
            cout << "No space to enqueu " << endl;
            return;
        }
        else if (isEmpty())
        {
            rear++;
            front++;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
    }
    void deque()
    {
        Q temp;
        if (isEmpty())
        {
            cout << "Nothing to deque " << endl;
            return;
        }
        else if (front == rear)
        {
            temp = arr[front];
            front = -1;
            rear = -1;
        }
        
        else
        {
            temp = arr[front];
            front++;
        }
    }
    bool isFull()
    {
        if (rear == s - 1)
            return true;
        else
            return false;
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }
    int count()
    {
        if (isEmpty)
            return 0;
        else
            return (rear - front) + 1;
    }
    void print()
    {
        cout << "All the value in the queue  ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " " << endl;

    }
};