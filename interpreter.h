#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define MOD 34
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43
#define RSTRING 50
#define WSTRING 51

#define MEM_SIZE 100

void type(void);
void load(void);
void execute(void);
void dump(void);
void cleanup(void);
