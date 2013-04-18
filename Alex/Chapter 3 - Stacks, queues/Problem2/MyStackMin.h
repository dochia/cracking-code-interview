
class MyStackMin
{
      private: 
               int* mMinValues;
               int* mArr;
               int mCapacity;
               int mLength;
               int mMinLength;
               int AddValue(int value);
      public:
             MyStackMin(int Capacity);
             void Push(int Value);
             int Pop();
             int FindMin();
             void PrintStack();
               
};
