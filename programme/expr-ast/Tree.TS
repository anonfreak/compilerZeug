208
Tree

 
ю PROGRAM
Є  	0
0
0
B  
ь	Pos
tPosition
tPosition
А   
ью program
∞  	Ident
tIdent
tIdent
А   
ьBlock
BLOCKEXEC
BLOCKEXEC
А   
ю BLOCKEXEC
Є   	0
0
0
B  
ь€ blocklist
∞ Next
BLOCKEXEC
BLOCKEXEC
Д   
€ Stmt
STATEMENT
STATEMENT
А   
ю STATEMENT
Є   	0
0
0
B  
ь€ no_stmt
∞   € ю € declaration
∞  Next
DECLARATION
DECLARATION
А   
ю DECLARATION
Є  	0
0
0
B  
ь	Pos
tPosition
tPosition
А   
ь€ decl_ident
∞  	Value
tIdent
tIdent
А   
ь	Ident
tIdent
tIdent
А   
ь€ € € decl_assignm
∞  	Value
tIdent
tIdent
А   
ьRight
ASSIGNMENT
ASSIGNMENT
А   
ю ASSIGNMENT
Є  	0
0
0
B  
ь	Pos
tPosition
tPosition
А   
ь€ assign
∞  	Ident
tIdent
tIdent
А   
ьRight
COMPUTATION
COMPUTATION
А   
ю COMPUTATION
Є  	0
0
0
B  
ь	Pos
tPosition
tPosition
А   
ь€ binary_comp
∞  	Op
char
char
А   
ьLeft
COMPUTATION
COMPUTATION
А   
€ Right
COMPUTATION
COMPUTATION
А   
€ € € € int_const
∞  	Value
int
int
А   
ь€ € € float_const
∞  	Value
double
double
А   
ь€ € € unary_comp
∞  	Op
char
char
А   
ьArgument
COMPUTATION
COMPUTATION
А   
€ € € € string_const
∞  	Value
tIdent
tIdent
А   
ь€ € € identifier
∞  	Ident
tIdent
tIdent
А   
ь€ € € € € ю	 KEYWORD
Є   	0
0
0
B  
ь€ keyword_if
∞  Cond
COMPUTATION
COMPUTATION
А   
€ Block
BLOCKEXEC
BLOCKEXEC
А   
€ ElseIf
KEYWORD
KEYWORD
А   
€	 € € €	 keyword_else
∞  Block
BLOCKEXEC
BLOCKEXEC
А   
€ € € €	 nokeyword
∞   € € €	 keyword_while
∞  Cond
COMPUTATION
COMPUTATION
А   
€ Block
BLOCKEXEC
BLOCKEXEC
А   
€ € € €	 keyword_for
∞  Decl
DECLARATION
DECLARATION
А   
€ Cond
COMPUTATION
COMPUTATION
А   
€ Ass
ASSIGNMENT
ASSIGNMENT
А   
€ Block
BLOCKEXEC
BLOCKEXEC
А   
€ € € €	 € € € € € € € € € € € € € € € € € € assignment
∞  Next
ASSIGNMENT
ASSIGNMENT
А   
€ € € € keyword
∞  Next
KEYWORD
KEYWORD
А   
€	 € € € € € € € € € blocknostmt
∞   € € € € € € € € € € € € 