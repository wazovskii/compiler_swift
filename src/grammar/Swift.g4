grammar Swift;

program
    : statement
    ;

statement
    : importdeclaration (element)*
    ;
function
    : FUNC funcname LPARENTHESIS args RPARENTHESIS MINUS MORECOMPARISON ret_type LBRACE (element)* RETURN name RBRACE
    ;
    
functioncall
    : (funcname LPARENTHESIS name COLON avalibforplus (COMMA name COLON avalibforplus)* RPARENTHESIS)
    ;
args
    : name COLON type (COMMA name COLON type)*
    ;
element
    : print
    | variable
    | wholeif
    | ifconstrukt
    | array
    | r_while
    | arithmetic
    | function
    | name
    | arrayelem
    | functioncall
    ;

arrayelem
    : name LBRACKET r_index RBRACKET
    ;
r_index
    : name
    | number
    ;

number
    : INTEGER
    ;
    
comparemembers
    : LESSCOMPARISON
    | MORECOMPARISON
    | LESSOREQUALCOMPARISON
    | MOREOREQUALCOMPARISON
    | EQUALCOMPARISON
    ;
importdeclaration
    : IMPORTDECLARATION
    ;
print
    : PRINT LPARENTHESIS object+ RPARENTHESIS
    ;

opplus
    : PLUS avalibforplus
    ;

avalibforplus
    : name
    | r_float
    | number
    | arrayelem
    | readline
    | functioncall
    ;
    
opminus
    : MINUS avalibforplus
    ;
opmulti
    : MULTIPLICATION avalibformulti
    ;
opdivision
    : DIVISION avalibformulti
    ;

avalibformulti
    : name
    | r_float
    | number
    ;

arithmetic
    : name ASSIGNMENT avalibforplus operations*
    ;
    
operations
    : opplus
    | opminus
    | opmulti
    | opdivision
    | name
    | types
    ;

object
    : types
    | numbes
    | name
    | arrayelem
    ;
numbes
    : types (COMMA types)*
    ;
types
    : number
    | string
    | r_float
    ;
string
    : STRING
    ;
r_float
    : FLOAT
    ;
    
readline
    : READLINE
    ;

variable
    : VARIABLEDECLARATION name COLON type ASSIGNMENT types
    ;

array
    : VARIABLEDECLARATION name COLON ARRAY LESSCOMPARISON type MORECOMPARISON ASSIGNMENT LBRACKET numbes RBRACKET
    ;

wholeif
    : ifconstrukt elseconstrukt
    ;
    
r_while
    : WHILE name comparemembers secname LBRACE (element)+ RBRACE
    ;
    
ifconstrukt
    : IF name comparemembers secname LBRACE (element)+ RBRACE
    ;

elseconstrukt
    : ELSE LBRACE (element)+ RBRACE
    ;

secname
    : IDENTIFICATOR
    ;
funcname
    : IDENTIFICATOR
    ;

name
    : IDENTIFICATOR
    ;
type
    : INT
    | STR
    | FLO
    ;

ret_type
    : INT
    | STR
    | FLO
    ;
ARRAY
    : 'Array'
    ;

INTEGER
   : '0'
   | MINUS? [1-9] [0-9]*
   ;
DOT : '.';

FLOAT
    : INTEGER DOT INTEGER
    ;
   
INT
    : 'Int'
    ;
STR
    : 'String'
    ;
FLO
    : 'Float'
    ;
FUNC
    : 'func'
    ;

CONSTANTDECLARATION: 'let';
VARIABLEDECLARATION: 'var';
IMPORTDECLARATION: 'import UIKit';

WHILE: 'while';
FOR: 'for';
IF: 'if';
ELSE: 'else';
PRINT: 'print';
READLINE: 'readLine()';
SEPARATOR: 'in';
RETURN: 'return';

STRING: '"' ~ ["\n\r]* '"';
IDENTIFICATOR: [_a-zA-Z][_a-zA-Z0-9]*;
PLUS: '+';
MINUS: '-';
MULTIPLICATION: '*';
DIVISION: '/';
ASSIGNMENT: '=';
LESSCOMPARISON: '<';
MORECOMPARISON: '>';
LESSOREQUALCOMPARISON: '<=';
MOREOREQUALCOMPARISON: '>=';
EQUALCOMPARISON: '==';
LBRACE: '{';
RBRACE: '}';
LBRACKET: '[';
RBRACKET: ']';
LPARENTHESIS: '(';
RPARENTHESIS: ')';
COMMA: ',';
COLON: ':';
WS: [ \n\t\r]+ -> skip;
INVALID: .;
