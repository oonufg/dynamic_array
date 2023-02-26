struct dArray;
void arrayExtend(struct dArray* arrayPtr);

void arrayWrite(struct dArray* arrayPtr,int index,void* value);
void* arrayRead(struct dArray* arrayPtr,int index);

void* arrayConstructor(int typeSize);
void arrayDestructor();

int getSize(struct dArray* arrayPtr);
int _getCapacity(struct dArray* arrayPtr);
