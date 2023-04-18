typedef struct _dArray dArray;

void arrayExtend(dArray* arrayPtr);

void arrayWrite(dArray* arrayPtr,int index,void* value);
void* arrayRead(dArray* arrayPtr,int index);

void* arrayConstructor(int typeSize);
void arrayDestructor();

int getSize(dArray* arrayPtr);
int _getCapacity(dArray* arrayPtr);
